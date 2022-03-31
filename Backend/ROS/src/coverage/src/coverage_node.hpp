/*
 * Copyright 2022 Casey Sanchez
 */

#pragma once

#include <optional>

#include <pcl-1.10/pcl/filters/statistical_outlier_removal.h>
#include <pcl-1.10/pcl/filters/radius_outlier_removal.h>
#include <pcl-1.10/pcl/surface/concave_hull.h>

#include "ros/ros.h"
#include "ros/console.h"

#include "nav_msgs/OccupancyGrid.h"
#include "geometry_msgs/Pose.h"

#include "coverage/coverage.h"

#include "mandoline.hpp"

class CoverageNode
{
    ros::NodeHandle m_node_handle;
    
    ros::Subscriber m_occupancy_grid_subscriber;

    ros::ServiceServer m_coverage_server;

    std::optional<nav_msgs::OccupancyGrid> m_occupancy_grid;

    float m_extrude_distance;
    float m_slice_spacing;

public:
    CoverageNode(ros::NodeHandle const &node_handle);

private:
    void onOccupancyGrid(nav_msgs::OccupancyGrid::ConstPtr const &occupancy_grid);

    bool onCoverage(coverage::coverage::Request &request, coverage::coverage::Response &response);
};