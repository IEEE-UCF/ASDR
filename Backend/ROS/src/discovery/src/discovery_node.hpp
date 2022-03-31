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

#include "discovery/discovery.h"

#include "discovery.hpp"

class DiscoveryNode
{
    ros::NodeHandle m_node_handle;
    
    ros::Subscriber m_occupancy_grid_subscriber;

    ros::ServiceServer m_discovery_server;

    std::optional<nav_msgs::OccupancyGrid> m_occupancy_grid;

public:
    DiscoveryNode(ros::NodeHandle const &node_handle);

private:
    void onOccupancyGrid(nav_msgs::OccupancyGrid::ConstPtr const &occupancy_grid);

    bool onDiscovery(discovery::discovery::Request &request, discovery::discovery::Response &response);
};