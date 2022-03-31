/*
 * Copyright 2022 Casey Sanchez
 */

#include "discovery.hpp"

void Discovery::setOccupancyGrid(nav_msgs::OccupancyGrid const &occupancy_grid)
{
    m_occupancy_grid = occupancy_grid;
}

void Discovery::setCell(std::array<uint32_t, 2> const &cell)
{
    m_cell = cell;
}

void Discovery::compute(std::optional<std::array<uint32_t, 2>> &goal)
{
    goal = std::nullopt;
    
    std::array<std::array<int32_t, 2>, 4> const offsets = { { { 1, 0 }, { 0, 1 }, { -1, 0 }, { 0, -1 } } };

    uint32_t const &width = m_occupancy_grid.info.width;
    uint32_t const &height = m_occupancy_grid.info.height;

    size_t const size = width * height;

    auto const &[cell_x, cell_y] = m_cell;

    nav_msgs::OccupancyGrid visit_occupancy_grid;

    visit_occupancy_grid.info = m_occupancy_grid.info;

    visit_occupancy_grid.data.resize(size);

    std::fill(std::begin(visit_occupancy_grid.data), std::end(visit_occupancy_grid.data), -1);

    std::queue<std::array<uint32_t, 2>> visit_queue;
    
    visit_queue.push(m_cell);

    while (!visit_queue.empty()) {
        auto const &[visit_x, visit_y] = visit_queue.front();

        visit_queue.pop();

        for (uint32_t offset_index = 0; offset_index < std::size(offsets); ++offset_index) {
            uint32_t const current_x = visit_x + offsets[offset_index][0];
            uint32_t const current_y = visit_y + offsets[offset_index][1];

            if (current_x >= 0 && current_x < width && current_y >= 0 && current_y < height) {
                size_t const index = current_x + current_y * width;

                if (m_occupancy_grid.data[index] == -1 && current_x != cell_x && current_y != cell_y) {
                    goal = { current_x, current_y };
                    
                    return;
                }
                else if (m_occupancy_grid.data[index] == 0 && visit_occupancy_grid.data[index] == -1) {
                    visit_occupancy_grid.data[index] = 0;
                    
                    visit_queue.push({ current_x, current_y });
                }
            }
        }
    }
}
