#pragma once

#include <stdexcept>
#include <memory>

#include "ros/ros.h"
#include "ros/console.h"

#include "geometry_msgs/Twist.h"

#include "asdr/set_state.h"
#include "asdr/get_state.h"
#include "asdr/set_velocity.h"

#include "finite_state_machine.hpp"

class ASDRNode
{
    ros::NodeHandle m_node_handle;

	FiniteStateMachine::Instance m_finite_state_machine;

    ros::ServiceServer m_get_state_server;
    ros::ServiceServer m_set_state_server;
    ros::ServiceServer m_set_velocity_server;

    ros::Publisher m_cmd_vel_publisher;

    double m_max_linear_velocity;
    double m_min_linear_velocity;

    double m_max_angular_velocity;
    double m_min_angular_velocity;

public:
    ASDRNode(ros::NodeHandle const &node_handle);

    void update();

private:
    bool onGetState(asdr::get_state::Request &request, asdr::get_state::Response &response);
    bool onSetState(asdr::set_state::Request &request, asdr::set_state::Response &response);
    bool onSetVelocity(asdr::set_velocity::Request &request, asdr::set_velocity::Response &response);
};
