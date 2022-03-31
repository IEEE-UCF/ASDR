/*
 * Copyright 2022 Casey Sanchez
 */

#include "serial_command_client_node.hpp"

SerialCommandClientNode::SerialCommandClientNode(ros::NodeHandle const &node_handle) : 
    m_node_handle { node_handle }
{
    std::string serial_port;

    if (!m_node_handle.getParam("serial_port", serial_port)) {
        throw std::runtime_error("serial_port not provided.");
    }

    m_serial_command_client = std::unique_ptr<SerialCommandClient>(new SerialCommandClient(serial_port));
    
    m_send_command_server = m_node_handle.advertiseService(ros::names::resolve("send_command"), &SerialCommandClientNode::onSendCommand, this);
}

bool SerialCommandClientNode::onSendCommand(serial_command_client::send_command::Request &request, serial_command_client::send_command::Response &response)
{
    SerialCommandRequest serial_command_request;
    SerialCommandResponse serial_command_response;

    serial_command_request.command = request.command;

    serial_command_request.size = std::size(request.buffer);

    std::memcpy(&serial_command_request.buffer[0], &request.buffer[0], std::size(request.buffer));

    if (m_serial_command_client->sendCommand(serial_command_request, serial_command_response)) {
        response.status = serial_command_response.status;

        response.buffer.resize(serial_command_response.size);
        
        std::memcpy(&response.buffer[0], &serial_command_response.buffer[0], serial_command_response.size);

        return true;
    }

    return false;
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "serial_command_client");

    ros::NodeHandle node_handle("~");
    
    try {
        SerialCommandClientNode serial_command_client_node(node_handle);
        
        while (ros::ok()) {
            ros::spinOnce();
        }

        return 0;
    }
    catch (std::exception const &exception) {
        ROS_ERROR_STREAM(exception.what());

        return 1;
    }
}