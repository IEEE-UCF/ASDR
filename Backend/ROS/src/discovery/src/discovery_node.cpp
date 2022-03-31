/*
 * Copyright 2022 Casey Sanchez
 */

#include "discovery_node.hpp"

DiscoveryNode::DiscoveryNode(ros::NodeHandle const &node_handle) : 
    m_node_handle { node_handle }
{
    m_occupancy_grid_subscriber = m_node_handle.subscribe(ros::names::resolve("/rtabmap/grid_map"), 1, &DiscoveryNode::onOccupancyGrid, this);

    m_discovery_server = m_node_handle.advertiseService(ros::names::resolve("discovery"), &DiscoveryNode::onDiscovery, this);
}

void DiscoveryNode::onOccupancyGrid(nav_msgs::OccupancyGrid::ConstPtr const &occupancy_grid)
{
    m_occupancy_grid = *occupancy_grid;
}

bool DiscoveryNode::onDiscovery(discovery::discovery::Request &request, discovery::discovery::Response &response)
{
    if (m_occupancy_grid.has_value()) {
        nav_msgs::OccupancyGrid const occupancy_grid = m_occupancy_grid.value();

        Eigen::Vector3d const position(request.pose.position.x, request.pose.position.y, request.pose.position.z);

        Eigen::Vector3d const origin_position(occupancy_grid.info.origin.position.x, occupancy_grid.info.origin.position.y, occupancy_grid.info.origin.position.z);
        Eigen::Quaterniond const origin_orientation(occupancy_grid.info.origin.orientation.w, occupancy_grid.info.origin.orientation.x, occupancy_grid.info.origin.orientation.y, occupancy_grid.info.origin.orientation.z);

        Eigen::Vector3d const grid_position = origin_orientation.inverse() * (position - origin_position);

        uint32_t const cell_x = static_cast<uint32_t>(grid_position.x() / occupancy_grid.info.resolution);
        uint32_t const cell_y = static_cast<uint32_t>(grid_position.y() / occupancy_grid.info.resolution);

        std::array<uint32_t, 2> const cell = { cell_x, cell_y };

        std::optional<std::array<uint32_t, 2>> goal;

        Discovery discovery;

        discovery.setOccupancyGrid(occupancy_grid);
        discovery.setCell(cell);
        discovery.compute(goal);

        // No value means no goal was found

        if (goal.has_value()) {
            auto const &[goal_x, goal_y] = goal.value();

            Eigen::Vector3d const goal_position(static_cast<float>(goal_x) * occupancy_grid.info.resolution, static_cast<float>(goal_y) * occupancy_grid.info.resolution, 0.0);

            Eigen::Vector3d const pose_position = origin_orientation * goal_position + origin_position;
            Eigen::Quaterniond const pose_orientation = origin_orientation * Eigen::AngleAxisd(std::atan2(goal_position.y() - position.y(), goal_position.x() - position.x()), Eigen::Vector3d::UnitZ());

            geometry_msgs::Pose pose;

            pose.position.x = pose_position.x();
            pose.position.y = pose_position.y();
            pose.position.z = pose_position.z();

            pose.orientation.w = pose_orientation.w();
            pose.orientation.x = pose_orientation.x();
            pose.orientation.y = pose_orientation.y();
            pose.orientation.z = pose_orientation.z();

            response.pose = pose;

            response.status = discovery::discovery::Response::SUCCESS;
        }
        else {
            response.status = discovery::discovery::Response::FAILURE;
        }

        return true;
    }

    return false;
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "discovery");

    ros::NodeHandle node_handle("~");
    
    try {
        DiscoveryNode discovery_node(node_handle);
        
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