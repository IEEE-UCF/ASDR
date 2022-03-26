#pragma once

#include <numeric>

#include <pcl-1.10/pcl/io/pcd_io.h>
#include <pcl-1.10/pcl/point_types.h>

#include "geometry_msgs/Pose.h"

namespace Mandoline
{
    class Extrude
    {
        pcl::PointCloud<pcl::PointXYZ>::Ptr m_point_cloud;
        float m_distance;

    public:
        void setInputCloud(pcl::PointCloud<pcl::PointXYZ>::Ptr const &point_cloud);

        void setDistance(float const &distance);

        void compute(pcl::PointCloud<pcl::PointXYZ> &output);

    private:
        pcl::PointXYZ extrude(std::array<pcl::PointXYZ, 3> const &points) ;
    };

    class Slice
    {
        pcl::PointCloud<pcl::PointXYZ>::Ptr m_point_cloud;
        float m_spacing;

    public:
        void setInputCloud(pcl::PointCloud<pcl::PointXYZ>::Ptr const &point_cloud);

        void setSpacing(float const &spacing);

        void compute(pcl::PointCloud<pcl::PointXYZ> &output);

    private:
        bool isPointOnSegment(Eigen::Vector2f const &point, std::array<Eigen::Vector2f, 2> const &segment, float const epsilon = 1e-4) const;
    };
}