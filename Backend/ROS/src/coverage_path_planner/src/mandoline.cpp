#include "mandoline.hpp"

void Mandoline::Extrude::setInputCloud(pcl::PointCloud<pcl::PointXYZ>::Ptr const &point_cloud)
{
    m_point_cloud = point_cloud;
}

void Mandoline::Extrude::setDistance(float const &distance)
{
    m_distance = distance;
}

void Mandoline::Extrude::compute(pcl::PointCloud<pcl::PointXYZ> &output)
{
    std::vector<pcl::PointXYZ, Eigen::aligned_allocator<pcl::PointXYZ>> const &points = m_point_cloud->points;

    {
        pcl::PointXYZ const point = extrude({ points[std::size(points) - 1], points[0], points[1] });

        output.points.push_back(point);
    }

    for (size_t index = 0; index < std::size(points) - 2; ++index) {
        pcl::PointXYZ const point = extrude({ points[index + 0], points[index + 1], points[index + 2] });

        output.points.push_back(point);
    }

    {
        pcl::PointXYZ const point = extrude({ points[std::size(points) - 2], points[std::size(points) - 1], points[0] });

        output.points.push_back(point);
    }
}

pcl::PointXYZ Mandoline::Extrude::extrude(std::array<pcl::PointXYZ, 3> const &points) 
{
    Eigen::Vector2f const point_a = { points[0].x, points[0].y };
    Eigen::Vector2f const point_b = { points[1].x, points[1].y };
    Eigen::Vector2f const point_c = { points[2].x, points[2].y };

    Eigen::Vector2f const normal_a = Eigen::Hyperplane<float, 2>::Through(point_a, point_b).normal();
    Eigen::Vector2f const normal_b = Eigen::Hyperplane<float, 2>::Through(point_b, point_c).normal();

    std::array<Eigen::Vector2f, 2> const segment_a = { point_a + normal_a * m_distance, point_b + normal_a * m_distance };
    std::array<Eigen::Vector2f, 2> const segment_b = { point_b + normal_b * m_distance, point_c + normal_b * m_distance };

    Eigen::Hyperplane<float, 2> const line_a = Eigen::Hyperplane<float, 2>::Through(segment_a[0], segment_a[1]);
    Eigen::Hyperplane<float, 2> const line_b = Eigen::Hyperplane<float, 2>::Through(segment_b[0], segment_b[1]);

    Eigen::Vector2f const intersection = line_a.intersection(line_b);

    return { intersection.x(), intersection.y(), 0.0f };
}

void Mandoline::Slice::setInputCloud(pcl::PointCloud<pcl::PointXYZ>::Ptr const &point_cloud) 
{
    m_point_cloud = point_cloud;
}

void Mandoline::Slice::setSpacing(float const &spacing)
{
    m_spacing = spacing;
}

void Mandoline::Slice::compute(pcl::PointCloud<pcl::PointXYZ> &output)
{
    // Scanline segmentation
    // Input:            Output:
    // 0------------1     + 0  3--4  7 +
    // |            |       |  |  |  |
    // |            |       |  |  |  |
    // |            |       |  |  |  |
    // |            |       |  |  |  |
    // 3------------2     + 1--2  5--6 +
    std::vector<Eigen::Vector2f> input_points;
    std::vector<Eigen::Vector2f> output_points;

    Eigen::Vector2f min;
    Eigen::Vector2f max;

    min[0] = std::numeric_limits<float>::infinity();
    min[1] = std::numeric_limits<float>::infinity();

    max[0] = -std::numeric_limits<float>::infinity();
    max[1] = -std::numeric_limits<float>::infinity();

    for (pcl::PointXYZ const &input_point : m_point_cloud->points) {
        min[0] = std::min(min[0], input_point.x);
        min[1] = std::min(min[1], input_point.y);
        
        max[0] = std::max(max[0], input_point.x);
        max[1] = std::max(max[1], input_point.y);

        input_points.emplace_back(input_point.x, input_point.y);
    }

    bool flip = false;

    // Intersect each spaced vertical line with each of the graph's edges,
    // only add the intersection to the point list if it falls within constraints of the line segment
    for (float x = min[0]; x <= max[0]; x += m_spacing) {
        size_t const back_index = std::size(output_points);

        Eigen::Hyperplane<float, 2> const cast_line = Eigen::Hyperplane<float, 2>::Through({ x, min[1] }, { x, max[1] });

        for (size_t index = 0; index < std::size(input_points) - 1; ++index) {
            std::array<Eigen::Vector2f, 2> const segment = { input_points[index], input_points[index + 1] };

            Eigen::Hyperplane<float, 2> const edge_line = Eigen::Hyperplane<float, 2>::Through(segment[0], segment[1]);

            Eigen::Vector2f const intersection = cast_line.intersection(edge_line);

            if (isPointOnSegment(intersection, segment)) {
                output_points.push_back(intersection);
            }
        }

        {
            std::array<Eigen::Vector2f, 2> const segment = { input_points[std::size(input_points) - 1], input_points[0] };

            Eigen::Hyperplane<float, 2> const edge_line = Eigen::Hyperplane<float, 2>::Through(segment[0], segment[1]);

            Eigen::Vector2f const intersection = cast_line.intersection(edge_line);

            if (isPointOnSegment(intersection, segment)) {
                output_points.push_back(intersection);
            }
        }

        auto point_comparator = [flip](Eigen::Vector2f const &point_a, Eigen::Vector2f const &point_b) -> bool {
            return (point_a.y() < point_b.y()) == flip;
        };

        // Sort by y-value to guarantee that only direct vertical point neighbors
        // are used to properly construct edges.
        std::sort(std::next(std::begin(output_points), back_index), std::end(output_points), point_comparator);

        flip = !flip;
    }

    for (Eigen::Vector2f const &output_point : output_points) {
        output.points.emplace_back(output_point.x(), output_point.y(), 0.0f);
    }
}

bool Mandoline::Slice::isPointOnSegment(Eigen::Vector2f const &point, std::array<Eigen::Vector2f, 2> const &segment, float const epsilon) const
{
    float const norm = (segment[0] - point).norm() + (point - segment[1]).norm() - (segment[0] - segment[1]).norm();

    return std::abs(norm) < epsilon;
}
