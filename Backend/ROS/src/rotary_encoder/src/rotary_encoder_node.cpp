#include "rotary_encoder_node.hpp"

RotaryEncoderNode::RotaryEncoderNode(ros::NodeHandle const &node_handle) : 
    m_node_handle { node_handle }
{
    int32_t rotary_encoder_id;

    if (!m_node_handle.getParam("rotary_encoder_id", rotary_encoder_id)) {
        throw std::runtime_error("rotary_encoder_id not provided.");
    }

    m_rotary_encoder_id = static_cast<uint32_t>(rotary_encoder_id);

    m_get_rotary_encoder_server = m_node_handle.advertiseService(ros::names::resolve(std::to_string(m_rotary_encoder_id) + "/get_rotary_encoder"), &RotaryEncoderNode::onGetRotaryEncoder, this);

    m_send_command_client = m_node_handle.serviceClient<serial_command_client::send_command>(ros::names::resolve("send_command"));
}

bool RotaryEncoderNode::onGetRotaryEncoder(rotary_encoder::get_rotary_encoder::Request &request, rotary_encoder::get_rotary_encoder::Response &response)
{
    static uint8_t const ROTARY_ENCODER_COMMAND = 0;

    serial_command_client::send_command send_command_srv;

    send_command_srv.request.command = ROTARY_ENCODER_COMMAND;

    send_command_srv.request.buffer.resize(sizeof(uint32_t));

    std::memcpy(&send_command_srv.request.buffer[0], &m_rotary_encoder_id, sizeof(uint32_t));

    if (m_send_command_client.call(send_command_srv)) {
        if (send_command_srv.response.status == serial_command_client::send_command::Response::SUCCESS && std::size(send_command_srv.response.buffer) == sizeof(float) + sizeof(float)) {
            std::memcpy(&response.position, &send_command_srv.response.buffer[0], sizeof(float));
            std::memcpy(&response.velocity, &send_command_srv.response.buffer[sizeof(float)], sizeof(float));

            return true;
        }
    }

    return false;
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "rotary_encoder");

    ros::NodeHandle node_handle("~");
    
    try {
        RotaryEncoderNode rotary_encoder_node(node_handle);
        
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
