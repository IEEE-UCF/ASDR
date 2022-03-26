#include "stepper_motor_node.hpp"

StepperMotorNode::StepperMotorNode(ros::NodeHandle const &node_handle) : 
    m_node_handle { node_handle }
{
    int32_t stepper_motor_id;

    if (!m_node_handle.getParam("stepper_motor_id", stepper_motor_id)) {
        throw std::runtime_error("stepper_motor_id not provided.");
    }

    m_stepper_motor_id = static_cast<uint32_t>(stepper_motor_id);

    m_set_stepper_motor_server = m_node_handle.advertiseService(ros::names::resolve(std::to_string(m_stepper_motor_id) + "/set_stepper_motor"), &StepperMotorNode::onSetStepperMotor, this);

    m_send_command_client = m_node_handle.serviceClient<serial_command_client::send_command>(ros::names::resolve("send_command"));
}

bool StepperMotorNode::onSetStepperMotor(stepper_motor::set_stepper_motor::Request &request, stepper_motor::set_stepper_motor::Response &response)
{
    static uint8_t const STEPPER_MOTOR_COMMAND = 1;

    serial_command_client::send_command send_command_srv;

    send_command_srv.request.command = STEPPER_MOTOR_COMMAND;

    send_command_srv.request.buffer.resize(sizeof(uint32_t) + sizeof(float));

    std::memcpy(&send_command_srv.request.buffer[0], &m_stepper_motor_id, sizeof(uint32_t));
    std::memcpy(&send_command_srv.request.buffer[sizeof(uint32_t)], &request.velocity, sizeof(float));

    if (m_send_command_client.call(send_command_srv)) {
        if (send_command_srv.response.status == serial_command_client::send_command::Response::SUCCESS && std::size(send_command_srv.response.buffer) == 0) {
            return true;
        }
    }

    return false;
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "stepper_motor");

    ros::NodeHandle node_handle("~");
    
    try {
        StepperMotorNode stepper_motor_node(node_handle);
        
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
