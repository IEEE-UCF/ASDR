/*
 * Copyright 2022 Casey Sanchez
 */

#pragma once

#include <pcl-1.10/pcl/filters/statistical_outlier_removal.h>
#include <pcl-1.10/pcl/filters/radius_outlier_removal.h>
#include <pcl-1.10/pcl/surface/concave_hull.h>

#include "pcl_conversions/pcl_conversions.h"

#include "ros/ros.h"
#include "ros/console.h"

#include "nav_msgs/OccupancyGrid.h"
#include "geometry_msgs/Pose.h"

#include "a_star/a_star.h"

#include "a_star.hpp"

class AStarNode
{
    ros::NodeHandle m_node_handle;
    
    ros::Subscriber m_occupancy_grid_subscriber;

    ros::ServiceServer m_a_star_server;

    std::optional<nav_msgs::OccupancyGrid> m_occupancy_grid;

public:
    AStarNode(ros::NodeHandle const &node_handle);

private:
    void onOccupancyGrid(nav_msgs::OccupancyGrid::ConstPtr const &occupancy_grid);

    bool onAStar(a_star::a_star::Request &request, a_star::a_star::Response &response);
};