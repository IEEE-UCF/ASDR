#pragma once

#include <stdexcept>
#include <memory>

#include "ros/ros.h"
#include "ros/console.h"

#include "rotary_encoder/get_rotary_encoder.h"

#include "serial_command_client/send_command.h"

class RotaryEncoderNode
{
    ros::NodeHandle m_node_handle;

    ros::ServiceServer m_get_rotary_encoder_server;
    
    ros::ServiceClient m_send_command_client;

    uint32_t m_rotary_encoder_id;

public:
    RotaryEncoderNode(ros::NodeHandle const &node_handle);

    void update(ros::Duration const &period);

private:
    bool onGetRotaryEncoder(rotary_encoder::get_rotary_encoder::Request &request, rotary_encoder::get_rotary_encoder::Response &response);
};
