/*
 * Copyright 2022 Casey Sanchez
 */

#pragma once

#include <stdexcept>
#include <memory>

#include "ros/ros.h"
#include "ros/console.h"

#include "sensor_msgs/Imu.h"
#include "sensor_msgs/MagneticField.h"

#include "serial_command_client/send_command.h"

#include "serial_commands.hpp"

class BerryIMUNode
{
    ros::NodeHandle m_node_handle;
    
    ros::Publisher m_imu_publisher;
    ros::Publisher m_magnetic_field_publisher;

    ros::ServiceClient m_send_command_client;

public:
    BerryIMUNode(ros::NodeHandle const &node_handle);

    void publish();
};
