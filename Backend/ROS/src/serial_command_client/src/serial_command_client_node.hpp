/*
 * Copyright 2022 Casey Sanchez
 */

#pragma once

#include <stdexcept>
#include <string>
#include <memory>

#include "ros/ros.h"
#include "ros/console.h"

#include "serial_command_client.hpp"

#include "serial_command_client/send_command.h"

class SerialCommandClientNode
{
    ros::NodeHandle m_node_handle;

    ros::ServiceServer m_send_command_server;

    std::unique_ptr<SerialCommandClient> m_serial_command_client;

public:
    SerialCommandClientNode(ros::NodeHandle const &node_handle);

private:
    bool onSendCommand(serial_command_client::send_command::Request &request, serial_command_client::send_command::Response &response);
};