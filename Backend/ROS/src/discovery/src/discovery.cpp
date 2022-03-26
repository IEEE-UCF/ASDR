#include "discovery.hpp"

void Discovery::setOccupancyGrid(nav_msgs::OccupancyGrid const &occupancy_grid)
{
    m_occupancy_grid = occupancy_grid;
}

void Discovery::setCell(std::tuple<uint32_t, uint32_t> const &cell)
{
    m_cell = cell;
}

void Discovery::compute(std::optional<std::tuple<uint32_t, uint32_t>> &goal)
{
    auto const &[cell_x, cell_y] = m_cell;

    nav_msgs::OccupancyGrid visit_occupancy_grid;

    visit_occupancy_grid.info = m_occupancy_grid.info;

    visit_occupancy_grid.data.resize(visit_occupancy_grid.info.width * visit_occupancy_grid.info.height);

    std::fill(std::begin(visit_occupancy_grid.data), std::end(visit_occupancy_grid.data), -1);

    std::queue<std::tuple<uint32_t, uint32_t>> visit_queue;
    
    visit_queue.emplace(cell_x, cell_y);

    goal = std::nullopt;

    while (!visit_queue.empty()) {
        auto const &[x, y] = visit_queue.front();

        visit_queue.pop();

        {
            uint32_t const current_x = x + 1;
            uint32_t const current_y = y;

            uint32_t const index = current_x + current_y * m_occupancy_grid.info.width;

            if (index >= 0 && index < std::size(m_occupancy_grid.data)) {
                if (m_occupancy_grid.data[index] == -1 && current_x != cell_x && current_y != cell_y) {
                    goal = { current_x, current_y };
                    
                    break;
                }
                else if (m_occupancy_grid.data[index] == 0 && visit_occupancy_grid.data[index] == -1) {
                    visit_occupancy_grid.data[index] = 0;
                    
                    visit_queue.emplace(current_x, current_y);
                }
            }
        }
        
        {
            uint32_t const current_x = x;
            uint32_t const current_y = y + 1;

            uint32_t const index = current_x + current_y * m_occupancy_grid.info.width;

            if (index >= 0 && index < std::size(m_occupancy_grid.data)) {
                if (m_occupancy_grid.data[index] == -1 && current_x != cell_x && current_y != cell_y) {
                    goal = { current_x, current_y };
                    
                    break;
                }
                else if (m_occupancy_grid.data[index] == 0 && visit_occupancy_grid.data[index] == -1) {
                    visit_occupancy_grid.data[index] = 0;
                    
                    visit_queue.emplace(current_x, current_y);
                }
            }
        }

        {
            uint32_t const current_x = x - 1;
            uint32_t const current_y = y;

            uint32_t const index = current_x + current_y * m_occupancy_grid.info.width;

            if (index >= 0 && index < std::size(m_occupancy_grid.data)) {
                if (m_occupancy_grid.data[index] == -1 && current_x != cell_x && current_y != cell_y) {
                    goal = { current_x, current_y };
                    
                    break;
                }
                else if (m_occupancy_grid.data[index] == 0 && visit_occupancy_grid.data[index] == -1) {
                    visit_occupancy_grid.data[index] = 0;
                    
                    visit_queue.emplace(current_x, current_y);
                }
            }
        }

        {
            uint32_t const current_x = x;
            uint32_t const current_y = y - 1;

            uint32_t const index = current_x + current_y * m_occupancy_grid.info.width;

            if (index >= 0 && index < std::size(m_occupancy_grid.data)) {
                if (m_occupancy_grid.data[index] == -1 && current_x != cell_x && current_y != cell_y) {
                    goal = { current_x, current_y };
                    
                    break;
                }
                else if (m_occupancy_grid.data[index] == 0 && visit_occupancy_grid.data[index] == -1) {
                    visit_occupancy_grid.data[index] = 0;
                    
                    visit_queue.emplace(current_x, current_y);
                }
            }
        }
    }
}
