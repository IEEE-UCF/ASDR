/*
 * Copyright 2022 Casey Sanchez
 */

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

class MobileHardwareNode : public hardware_interface::RobotHW
{
    ros::NodeHandle m_node_handle;

    uint32_t m_left_front_id;
    uint32_t m_left_back_id;
    uint32_t m_right_front_id;
    uint32_t m_right_back_id;

    hardware_interface::JointStateInterface m_joint_state_interface;
    hardware_interface::VelocityJointInterface m_joint_velocity_interface;

    std::array<double, 4> m_position;
    std::array<double, 4> m_velocity;
    std::array<double, 4> m_effort;
    std::array<double, 4> m_command;

    std::array<std::unique_ptr<PID>, 4> m_pid;

    std::array<ros::ServiceClient, 4> m_get_rotary_encoder_client;
    std::array<ros::ServiceClient, 4> m_set_stepper_motor_client;

public:
    MobileHardwareNode(ros::NodeHandle const &node_handle);
    
    void read(ros::Duration const &period);
    void write(ros::Duration const &period);
};
