#pragma once

#include <stdexcept>
#include <memory>

#include "ros/ros.h"
#include "ros/console.h"

#include "uvc_light/set_uvc_light.h"

#include "serial_command_client/send_command.h"

class UVCLightNode
{
    ros::NodeHandle m_node_handle;

    ros::ServiceServer m_set_uvc_light_server;
    
    ros::ServiceClient m_send_command_client;

public:
    UVCLightNode(ros::NodeHandle const &node_handle);

private:
    bool onSetUVCLight(uvc_light::set_uvc_light::Request &request, uvc_light::set_uvc_light::Response &response);
};
