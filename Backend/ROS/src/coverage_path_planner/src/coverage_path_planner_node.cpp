#include "coverage_path_planner_node.hpp"

CoveragePathPlannerNode::CoveragePathPlannerNode(ros::NodeHandle const &node_handle) : 
    m_node_handle { node_handle }
{
    if (!m_node_handle.getParam("extrude_distance", m_extrude_distance)) {
        throw std::runtime_error("extrude_distance not provided.");
    }

    if (!m_node_handle.getParam("slice_spacing", m_slice_spacing)) {
        throw std::runtime_error("slice_spacing not provided.");
    }

    m_occupancy_grid_subscriber = m_node_handle.subscribe(ros::names::resolve("/rtabmap/grid_map"), 1, &CoveragePathPlannerNode::onOccupancyGrid, this);

    m_make_plan_server = m_node_handle.advertiseService(ros::names::resolve("make_plan"), &CoveragePathPlannerNode::onMakePlan, this);
}

void CoveragePathPlannerNode::onOccupancyGrid(nav_msgs::OccupancyGrid::ConstPtr const &occupancy_grid)
{
    m_occupancy_grid = *occupancy_grid;
}

bool CoveragePathPlannerNode::onMakePlan(coverage_path_planner::make_plan::Request &request, coverage_path_planner::make_plan::Response &response)
{
    if (m_occupancy_grid.has_value()) {
        nav_msgs::OccupancyGrid const occupancy_grid = m_occupancy_grid.value();

        pcl::PointCloud<pcl::PointXYZ>::Ptr point_cloud(new pcl::PointCloud<pcl::PointXYZ>);
        pcl::PointCloud<pcl::PointXYZ>::Ptr point_cloud_filtered(new pcl::PointCloud<pcl::PointXYZ>);
        pcl::PointCloud<pcl::PointXYZ>::Ptr point_cloud_hull(new pcl::PointCloud<pcl::PointXYZ>);
        pcl::PointCloud<pcl::PointXYZ>::Ptr point_cloud_extruded(new pcl::PointCloud<pcl::PointXYZ>);
        pcl::PointCloud<pcl::PointXYZ>::Ptr point_cloud_sliced(new pcl::PointCloud<pcl::PointXYZ>);

        for (uint32_t index = 0; index < occupancy_grid.info.height * occupancy_grid.info.width; ++index) {
            if (occupancy_grid.data[index] == 0) {
                uint32_t const x = index % occupancy_grid.info.width;
                uint32_t const y = index / occupancy_grid.info.width;
                
                point_cloud->points.emplace_back(static_cast<float>(x) * occupancy_grid.info.resolution, static_cast<float>(y) * occupancy_grid.info.resolution, 0.0f);
            }
        }
        
        pcl::StatisticalOutlierRemoval<pcl::PointXYZ> statistical_outlier_removal;

        statistical_outlier_removal.setInputCloud(point_cloud);
        statistical_outlier_removal.setMeanK(1000);
        statistical_outlier_removal.setStddevMulThresh(0.01);
        statistical_outlier_removal.filter(*point_cloud_filtered);
        
        pcl::ConcaveHull<pcl::PointXYZ> concave_hull;

        concave_hull.setAlpha(0.1);
        concave_hull.setInputCloud(point_cloud_filtered);
        concave_hull.reconstruct(*point_cloud_hull);

        Mandoline::Extrude extrude;

        extrude.setInputCloud(point_cloud_hull);
        extrude.setDistance(m_extrude_distance);
        extrude.compute(*point_cloud_extruded);

        Mandoline::Slice slice;

        slice.setInputCloud(point_cloud_extruded);
        slice.setSpacing(m_slice_spacing);
        slice.compute(*point_cloud_sliced);

        Eigen::Vector3d const origin_position(occupancy_grid.info.origin.position.x, occupancy_grid.info.origin.position.y, occupancy_grid.info.origin.position.z);
        Eigen::Quaterniond const origin_orientation(occupancy_grid.info.origin.orientation.w, occupancy_grid.info.origin.orientation.x, occupancy_grid.info.origin.orientation.y, occupancy_grid.info.origin.orientation.z);

        {
            geometry_msgs::Pose pose;

            Eigen::Vector3d const position = origin_orientation * Eigen::Vector3d(point_cloud_sliced->points[0].x, point_cloud_sliced->points[0].y, point_cloud_sliced->points[0].z) + origin_position;

            pose.position.x = position.x();
            pose.position.y = position.y();
            pose.position.z = position.z();

            pose.orientation.x = 0.0;
            pose.orientation.y = 0.0;
            pose.orientation.z = 0.0;
            pose.orientation.w = 1.0;

            response.plan.push_back(pose);
        }

        for (size_t index = 1; index < std::size(point_cloud_sliced->points); ++index) {
            geometry_msgs::Pose pose;

            Eigen::Vector3d const position = origin_orientation * Eigen::Vector3d(point_cloud_sliced->points[index].x, point_cloud_sliced->points[index].y, point_cloud_sliced->points[index].z) + origin_position;

            pose.position.x = position.x();
            pose.position.y = position.y();
            pose.position.z = position.z();

            Eigen::Quaterniond const orientation = origin_orientation * Eigen::AngleAxisd(std::atan2(point_cloud_sliced->points[index].y - point_cloud_sliced->points[index - 1].y, point_cloud_sliced->points[index].x - point_cloud_sliced->points[index - 1].x), Eigen::Vector3d::UnitZ());

            pose.orientation.x = orientation.x();
            pose.orientation.y = orientation.y();
            pose.orientation.z = orientation.z();
            pose.orientation.w = orientation.w();

            response.plan.push_back(pose);
        }

        return true;
    }

    return false;
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "coverage_path_planner");

    ros::NodeHandle node_handle("~");
    
    try {
        CoveragePathPlannerNode coverage_path_planner_node(node_handle);
        
        while (ros::ok()) {
            ros::spinOnce();
        }

        return 0;
    }
    catch (std::exception const &exception) {
        ROS_ERROR_STREAM(exception.what());

        return 1;
    }
}