#pragma once

#include <stdexcept>
#include <memory>
#include <array>

#include "ros/ros.h"
#include "ros/console.h"

#include "controller_manager/controller_manager.h"
#include "hardware_interface/joint_command_interface.h"
#include "hardware_interface/joint_state_interface.h"
#include "hardware_interface/robot_hw.h"

#include "rotary_encoder/get_rotary_encoder.h"
#include "stepper_motor/set_stepper_motor.h"

#include "pid.hpp"

class MobileBaseNode : public hardware_interface::RobotHW
{
    enum 
    {
        LEFT = 0,
        RIGHT = 1
    };

    enum
    {
        FRONT = 0,
        BACK = 1
    };

    ros::NodeHandle m_node_handle;

    hardware_interface::JointStateInterface m_joint_state_interface;
    hardware_interface::VelocityJointInterface m_joint_velocity_interface;

    std::array<std::array<double, 2>, 2> m_position;
    std::array<std::array<double, 2>, 2> m_velocity;
    std::array<std::array<double, 2>, 2> m_effort;
    std::array<std::array<double, 2>, 2> m_command;

    std::array<std::array<PID, 2>, 2> m_pid;

    std::array<std::array<ros::ServiceClient, 2>, 2> m_get_rotary_encoder_client;
    std::array<std::array<ros::ServiceClient, 2>, 2> m_set_stepper_motor_client;

public:
    MobileBaseNode(ros::NodeHandle const &node_handle);
    
    void read(ros::Duration const &period);
    void write(ros::Duration const &period);
};
