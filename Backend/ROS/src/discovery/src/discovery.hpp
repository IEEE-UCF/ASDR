/*
 * Copyright 2022 Casey Sanchez
 */

#pragma once

#include <array>
#include <optional>
#include <queue>

#include <eigen3/Eigen/Dense>

#include "ros/ros.h"
#include "ros/console.h"

#include "nav_msgs/OccupancyGrid.h"

class Discovery
{
    nav_msgs::OccupancyGrid m_occupancy_grid;

    std::array<uint32_t, 2> m_cell;

public:
    void setOccupancyGrid(nav_msgs::OccupancyGrid const &occupancy_grid);

    void setCell(std::array<uint32_t, 2> const &cell);

    void compute(std::optional<std::array<uint32_t, 2>> &goal);
};
