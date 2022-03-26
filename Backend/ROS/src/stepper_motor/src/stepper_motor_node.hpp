#pragma once

#include <stdexcept>
#include <memory>

#include "ros/ros.h"
#include "ros/console.h"

#include "stepper_motor/set_stepper_motor.h"

#include "serial_command_client/send_command.h"

class StepperMotorNode
{
    ros::NodeHandle m_node_handle;

    ros::ServiceServer m_set_stepper_motor_server;
    
    ros::ServiceClient m_send_command_client;

    uint32_t m_stepper_motor_id;

public:
    StepperMotorNode(ros::NodeHandle const &node_handle);

private:
    bool onSetStepperMotor(stepper_motor::set_stepper_motor::Request &request, stepper_motor::set_stepper_motor::Response &response);
};
