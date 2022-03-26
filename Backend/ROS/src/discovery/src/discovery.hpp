#pragma once

#include <tuple>
#include <optional>
#include <queue>

#include <eigen3/Eigen/Dense>

#include "ros/ros.h"
#include "ros/console.h"

#include "tf/transform_listener.h"

#include "nav_msgs/OccupancyGrid.h"

class Discovery
{
    nav_msgs::OccupancyGrid m_occupancy_grid;
    std::tuple<uint32_t, uint32_t> m_cell;

public:
    void setOccupancyGrid(nav_msgs::OccupancyGrid const &occupancy_grid);

    void setCell(std::tuple<uint32_t, uint32_t> const &cell);

    void compute(std::optional<std::tuple<uint32_t, uint32_t>> &goal);
};
