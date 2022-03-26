#pragma once

#include <optional>

#include <pcl-1.10/pcl/filters/statistical_outlier_removal.h>
#include <pcl-1.10/pcl/filters/radius_outlier_removal.h>
#include <pcl-1.10/pcl/surface/concave_hull.h>

#include "ros/ros.h"
#include "ros/console.h"

#include "nav_msgs/OccupancyGrid.h"
#include "geometry_msgs/Pose.h"

#include "coverage_path_planner/make_plan.h"

#include "mandoline.hpp"

class CoveragePathPlannerNode
{
    ros::NodeHandle m_node_handle;
    
    ros::Subscriber m_occupancy_grid_subscriber;

    ros::ServiceServer m_make_plan_server;

    std::optional<nav_msgs::OccupancyGrid> m_occupancy_grid;

    float m_extrude_distance;
    float m_slice_spacing;

public:
    CoveragePathPlannerNode(ros::NodeHandle const &node_handle);

private:
    void onOccupancyGrid(nav_msgs::OccupancyGrid::ConstPtr const &occupancy_grid);

    bool onMakePlan(coverage_path_planner::make_plan::Request &request, coverage_path_planner::make_plan::Response &response);
};