/*
 * Copyright 2022 Casey Sanchez
 */

#include "a_star_node.hpp"

AStarNode::AStarNode(ros::NodeHandle const &node_handle) : 
    m_node_handle { node_handle }
{
    m_occupancy_grid_subscriber = m_node_handle.subscribe(ros::names::resolve("/rtabmap/grid_map"), 1, &AStarNode::onOccupancyGrid, this);

    m_a_star_server = m_node_handle.advertiseService(ros::names::resolve("a_star"), &AStarNode::onAStar, this);
}

void AStarNode::onOccupancyGrid(nav_msgs::OccupancyGrid::ConstPtr const &occupancy_grid)
{
    m_occupancy_grid = *occupancy_grid;
}

bool AStarNode::onAStar(a_star::a_star::Request &request, a_star::a_star::Response &response)
{
    if (m_occupancy_grid.has_value()) {
        nav_msgs::OccupancyGrid const &occupancy_grid = m_occupancy_grid.value();

        std::optional<std::vector<geometry_msgs::Pose>> path;

        AStar a_star;

        a_star.setOccupancyGrid(occupancy_grid);
        a_star.setBegin(request.begin);
        a_star.setEnd(request.end);
        a_star.setWeight(request.weight);
        a_star.compute(path);

        if (path.has_value()) {
            response.path = path.value();
            
            response.status = a_star::a_star::Response::SUCCESS;
        }
        else {
            response.status = a_star::a_star::Response::FAILURE;
        }

        return true;
    }

    return false;
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "a_star");

    ros::NodeHandle node_handle("~");
    
    try {
        AStarNode a_star_node(node_handle);
        
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