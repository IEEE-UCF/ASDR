#pragma once

#include <pcl-1.10/pcl/filters/statistical_outlier_removal.h>
#include <pcl-1.10/pcl/filters/radius_outlier_removal.h>
#include <pcl-1.10/pcl/surface/concave_hull.h>

#include "pcl_conversions/pcl_conversions.h"

#include "ros/ros.h"
#include "ros/console.h"

#include "nav_msgs/OccupancyGrid.h"
#include "geometry_msgs/Pose.h"

#include "tf/transform_listener.h"

#include "discovery/discover.h"

#include "discovery.hpp"

class DiscoveryNode
{
    ros::NodeHandle m_node_handle;
    
    ros::Subscriber m_occupancy_grid_subscriber;

    ros::ServiceServer m_discover_server;

    tf::TransformListener m_transform_listener;

    std::optional<nav_msgs::OccupancyGrid> m_occupancy_grid;

public:
    DiscoveryNode(ros::NodeHandle const &node_handle);

private:
    void onOccupancyGrid(nav_msgs::OccupancyGrid::ConstPtr const &occupancy_grid);

    bool onDiscover(discovery::discover::Request &request, discovery::discover::Response &response);
};