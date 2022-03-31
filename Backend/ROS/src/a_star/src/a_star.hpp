/*
 * Copyright 2022 Casey Sanchez
 */

#pragma once

#include <array>
#include <vector>
#include <queue>
#include <optional>
#include <algorithm>
#include <limits>

#include "ros/ros.h"
#include "ros/console.h"

#include "nav_msgs/OccupancyGrid.h"
#include "geometry_msgs/Pose.h"

#include "eigen3/Eigen/Dense"

class AStar
{
    struct Node
    {
        std::array<uint32_t, 2> m_current;
        std::array<uint32_t, 2> m_previous;

        float m_g_weight;
        float m_h_weight;

        bool m_closed;

        Node() :
            m_current { { 0U, 0U } },
            m_previous { { ~0U, ~0U } },
            m_g_weight { std::numeric_limits<float>::infinity() },
            m_h_weight { std::numeric_limits<float>::infinity() },
            m_closed { false }
        {
        }

        Node(std::array<uint32_t, 2> const &current) :
            m_current { current },
            m_previous { { ~0U, ~0U } },
            m_g_weight { 0.0f },
            m_h_weight { 0.0f },
            m_closed { false }
        {
        }

        Node(std::array<uint32_t, 2> const &current, std::array<uint32_t, 2> const &previous, float const &g_weight, float const &h_weight) :
            m_current { current },
            m_previous { previous },
            m_g_weight { g_weight },
            m_h_weight { h_weight },
            m_closed { false }
        {
        }

        float getScore() const
        {
            return m_g_weight + m_h_weight;
        }

        bool operator<(Node const &other) const
        {
            return getScore() < other.getScore();
        }
    };

    nav_msgs::OccupancyGrid m_occupancy_grid;

    geometry_msgs::Pose m_begin;
    geometry_msgs::Pose m_end;

    float m_weight;

public:
    void setOccupancyGrid(nav_msgs::OccupancyGrid const &occupancy_grid);

    void setBegin(geometry_msgs::Pose const &begin);

    void setEnd(geometry_msgs::Pose const &end);

    void setWeight(float const &weight);

    void compute(std::optional<std::vector<geometry_msgs::Pose>> &path);
};