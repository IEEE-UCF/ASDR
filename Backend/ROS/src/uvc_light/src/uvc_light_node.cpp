#include "uvc_light_node.hpp"

UVCLightNode::UVCLightNode(ros::NodeHandle const &node_handle) : 
    m_node_handle { node_handle }
{
    m_set_uvc_light_server = m_node_handle.advertiseService(ros::names::resolve("set_uvc_light"), &UVCLightNode::onSetUVCLight, this);

    m_send_command_client = m_node_handle.serviceClient<serial_command_client::send_command>(ros::names::resolve("send_command"));
}

bool UVCLightNode::onSetUVCLight(uvc_light::set_uvc_light::Request &request, uvc_light::set_uvc_light::Response &response)
{
    static uint8_t const UVC_LIGHT_COMMAND = 1;

    serial_command_client::send_command send_command_srv;

    send_command_srv.request.command = UVC_LIGHT_COMMAND;

    send_command_srv.request.buffer.resize(sizeof(uint8_t));

    std::memcpy(&send_command_srv.request.buffer[0], &request.state, sizeof(uint8_t));

    if (m_send_command_client.call(send_command_srv)) {
        if (send_command_srv.response.status == serial_command_client::send_command::Response::SUCCESS) {
            return true;
        }
    }

    return false;
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "uvc_light");

    ros::NodeHandle node_handle("~");
    
    try {
        UVCLightNode uvc_light_node(node_handle);
        
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
