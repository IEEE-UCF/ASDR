/*
 * Copyright 2022 Casey Sanchez
 */

#include "coverage_node.hpp"

CoverageNode::CoverageNode(ros::NodeHandle const &node_handle) : 
    m_node_handle { node_handle }
{
    if (!m_node_handle.getParam("extrude_distance", m_extrude_distance)) {
        throw std::runtime_error("extrude_distance not provided.");
    }

    if (!m_node_handle.getParam("slice_spacing", m_slice_spacing)) {
        throw std::runtime_error("slice_spacing not provided.");
    }

    m_occupancy_grid_subscriber = m_node_handle.subscribe(ros::names::resolve("/rtabmap/grid_map"), 1, &CoverageNode::onOccupancyGrid, this);

    m_coverage_server = m_node_handle.advertiseService(ros::names::resolve("coverage"), &CoverageNode::onCoverage, this);
}

void CoverageNode::onOccupancyGrid(nav_msgs::OccupancyGrid::ConstPtr const &occupancy_grid)
{
    m_occupancy_grid = *occupancy_grid;
}

bool CoverageNode::onCoverage(coverage::coverage::Request &request, coverage::coverage::Response &response)
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

            Eigen::Vector3d const pose_position = origin_orientation * Eigen::Vector3d(point_cloud_sliced->points[0].x, point_cloud_sliced->points[0].y, point_cloud_sliced->points[0].z) + origin_position;

            pose.position.x = pose_position.x();
            pose.position.y = pose_position.y();
            pose.position.z = pose_position.z();

            pose.orientation.w = 1.0;
            pose.orientation.x = 0.0;
            pose.orientation.y = 0.0;
            pose.orientation.z = 0.0;

            response.path.push_back(pose);
        }

        for (size_t index = 1; index < std::size(point_cloud_sliced->points); ++index) {
            geometry_msgs::Pose pose;

            Eigen::Vector3d const pose_position = origin_orientation * Eigen::Vector3d(point_cloud_sliced->points[index].x, point_cloud_sliced->points[index].y, point_cloud_sliced->points[index].z) + origin_position;
            Eigen::Quaterniond const pose_orientation = origin_orientation * Eigen::AngleAxisd(std::atan2(point_cloud_sliced->points[index].y - point_cloud_sliced->points[index - 1].y, point_cloud_sliced->points[index].x - point_cloud_sliced->points[index - 1].x), Eigen::Vector3d::UnitZ());

            pose.position.x = pose_position.x();
            pose.position.y = pose_position.y();
            pose.position.z = pose_position.z();

            pose.orientation.w = pose_orientation.w();
            pose.orientation.x = pose_orientation.x();
            pose.orientation.y = pose_orientation.y();
            pose.orientation.z = pose_orientation.z();

            response.path.push_back(pose);
        }

        return true;
    }

    return false;
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "coverage");

    ros::NodeHandle node_handle("~");
    
    try {
        CoverageNode coverage_node(node_handle);
        
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