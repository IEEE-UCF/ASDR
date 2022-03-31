/*
 * Copyright 2022 Casey Sanchez
 */

#include "a_star.hpp"

void AStar::setOccupancyGrid(nav_msgs::OccupancyGrid const &occupancy_grid)
{
    m_occupancy_grid = occupancy_grid;
}

void AStar::setBegin(geometry_msgs::Pose const &begin)
{
    m_begin = begin;
}

void AStar::setEnd(geometry_msgs::Pose const &end)
{
    m_end = end;
}

void AStar::setWeight(float const &weight)
{
    m_weight = weight;
}

void AStar::compute(std::optional<std::vector<geometry_msgs::Pose>> &path)
{
    path = std::nullopt;

    uint32_t const &width = m_occupancy_grid.info.width;
    uint32_t const &height = m_occupancy_grid.info.height;

    size_t const size = width * height;

    Eigen::Vector3d const origin_position(m_occupancy_grid.info.origin.position.x, m_occupancy_grid.info.origin.position.y, m_occupancy_grid.info.origin.position.z);
    Eigen::Quaterniond const origin_orientation(m_occupancy_grid.info.origin.orientation.w, m_occupancy_grid.info.origin.orientation.x, m_occupancy_grid.info.origin.orientation.y, m_occupancy_grid.info.origin.orientation.z);

    Eigen::Vector3d const begin_position(m_begin.position.x, m_begin.position.y, m_begin.position.z);
    Eigen::Vector3d const begin_grid_position = origin_orientation.inverse() * (begin_position - origin_position);

    uint32_t const begin_x = static_cast<uint32_t>(begin_grid_position.x() / m_occupancy_grid.info.resolution);
    uint32_t const begin_y = static_cast<uint32_t>(begin_grid_position.y() / m_occupancy_grid.info.resolution);

    std::array<uint32_t, 2> const begin = { begin_x, begin_y };

    Eigen::Vector3d const end_position(m_end.position.x, m_end.position.y, m_end.position.z);
    Eigen::Vector3d const end_grid_position = origin_orientation.inverse() * (end_position - origin_position);

    uint32_t const end_x = static_cast<uint32_t>(end_grid_position.x() / m_occupancy_grid.info.resolution);
    uint32_t const end_y = static_cast<uint32_t>(end_grid_position.y() / m_occupancy_grid.info.resolution);

    std::array<uint32_t, 2> const end = { end_x, end_y };

    if (begin_x >= 0 && begin_x < width && begin_y >= 0 && begin_y < height && end_x >= 0 && end_x < width && end_y >= 0 && end_y < height) {    
        size_t const begin_index = begin_x + begin_y * width;
        size_t const end_index = end_x + end_y * width;
        
        if (m_occupancy_grid.data[begin_index] == 0 && m_occupancy_grid.data[end_index] == 0) {
            std::array<std::array<int32_t, 2>, 8> const offsets = { { { 0, 1 }, { 1, 0 }, { 0, -1 }, { -1, 0 }, { -1, -1 }, { 1, 1 }, { -1, 1 }, { 1, -1 } } };

            std::vector<Node> grid(size);

            grid[begin_index] = { begin };

            std::priority_queue<Node> open;

            open.emplace(begin);

            while (!open.empty()) {
                std::array<uint32_t, 2> const current = open.top().m_current;

                auto const &[current_x, current_y] = current;

                if (current_x == end_x && current_y == end_y) {
                    break;
                }

                open.pop();

                size_t const current_index = current_x + current_y * width;

                grid[current_index].m_closed = true;

                for (size_t offset_index = 0; offset_index < std::size(offsets); ++offset_index) {
                    uint32_t const neighbor_x = current_x + offsets[offset_index][0];
                    uint32_t const neighbor_y = current_y + offsets[offset_index][1];

                    if (neighbor_x >= 0 && neighbor_x < width && neighbor_y >= 0 && neighbor_y < height) {
                        size_t const neighbor_index = neighbor_x + neighbor_y * width;

                        if (m_occupancy_grid.data[neighbor_index] == 0 && !grid[neighbor_index].m_closed) {
                            float const g_weight = grid[current_index].m_g_weight + 1.0f;
                            float const h_weight = m_weight * std::sqrt(std::pow(static_cast<float>(static_cast<int64_t>(end_x) - static_cast<int64_t>(neighbor_x)), 2.0f) + std::pow(static_cast<float>(static_cast<int64_t>(end_y) - static_cast<int64_t>(neighbor_y)), 2.0f));
                            
                            float const score = g_weight + h_weight;

                            if (score < grid[neighbor_index].getScore()) {
                                std::array<uint32_t, 2> const neighbor = { { neighbor_x, neighbor_y } };

                                grid[neighbor_index] = { neighbor, current, g_weight, h_weight };

                                open.push(grid[neighbor_index]);
                            }
                        }
                    }
                }
            }

            std::vector<std::array<uint32_t, 2>> grid_path;

            std::array<uint32_t, 2> current = end;

            while (current[0] != ~0U && current[1] != ~0U) {
                grid_path.push_back(current);

                size_t const current_index = current[0] + current[1] * width;

                current = grid[current_index].m_previous;
            }

            std::reverse(std::begin(grid_path), std::end(grid_path));

            if (grid_path[0][0] == begin_x && grid_path[0][1] == begin_y) {
                std::vector<geometry_msgs::Pose> pose_path;

                pose_path.push_back(m_begin);

                for (size_t index = 1; index < std::size(grid_path) - 1; ++index) {
                    Eigen::Vector3d const grid_position(static_cast<float>(grid_path[index][0]) * m_occupancy_grid.info.resolution, static_cast<float>(grid_path[index][1]) * m_occupancy_grid.info.resolution, 0.0);

                    Eigen::Vector3d const pose_position = origin_orientation * grid_position + origin_position;
                    Eigen::Quaterniond const pose_orientation = origin_orientation * Eigen::AngleAxisd(std::atan2(grid_path[index][1] - grid_path[index - 1][1], grid_path[index][0] - grid_path[index - 1][0]), Eigen::Vector3d::UnitZ());

                    geometry_msgs::Pose pose;

                    pose.position.x = pose_position.x();
                    pose.position.y = pose_position.y();
                    pose.position.z = pose_position.z();

                    pose.orientation.w = pose_orientation.w();
                    pose.orientation.x = pose_orientation.x();
                    pose.orientation.y = pose_orientation.y();
                    pose.orientation.z = pose_orientation.z();

                    pose_path.push_back(pose);
                }

                pose_path.push_back(m_end);

                path = pose_path;
            }
        }
    }
}
