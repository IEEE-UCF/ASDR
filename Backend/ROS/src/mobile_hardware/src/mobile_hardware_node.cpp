/*
 * Copyright 2022 Casey Sanchez
 */

#include "mobile_hardware_node.hpp"

MobileHardwareNode::MobileHardwareNode(ros::NodeHandle const &node_handle) : 
    m_node_handle { node_handle }
{
    std::string serial_port;

    if (!m_node_handle.getParam("serial_port", serial_port)) {
        throw std::runtime_error("serial_port not provided.");
    }

    int32_t left_front_id;
    int32_t left_back_id;
    int32_t right_front_id;
    int32_t right_back_id;

    if (!m_node_handle.getParam("left_front_id", left_front_id)) {
        throw std::runtime_error("left_front_id not provided.");
    }
    else if (left_front_id < 0 || left_front_id >= 4) {
        throw std::runtime_error("left_front_id out-of-bounds.");
    }

    if (!m_node_handle.getParam("left_back_id", left_back_id)) {
        throw std::runtime_error("left_back_id not provided.");
    }
    else if (left_back_id < 0 || left_back_id >= 4) {
        throw std::runtime_error("left_back_id out-of-bounds.");
    }

    if (!m_node_handle.getParam("right_front_id", right_front_id)) {
        throw std::runtime_error("right_front_id not provided.");
    }
    else if (right_front_id < 0 || right_front_id >= 4) {
        throw std::runtime_error("right_front_id out-of-bounds.");
    }

    if (!m_node_handle.getParam("right_back_id", right_back_id)) {
        throw std::runtime_error("right_back_id not provided.");
    }
    else if (right_back_id < 0 || right_back_id >= 4) {
        throw std::runtime_error("right_back_id out-of-bounds.");
    }

    m_left_front_id = static_cast<uint32_t>(left_front_id);
    m_left_back_id = static_cast<uint32_t>(left_back_id);
    m_right_front_id = static_cast<uint32_t>(right_front_id);
    m_right_back_id = static_cast<uint32_t>(right_back_id);

    double proportional_gain;
    double integral_gain;
    double derivative_gain;

    if (!m_node_handle.getParam("proportional_gain", proportional_gain)) {
        throw std::runtime_error("proportional_gain not provided.");
    }

    if (!m_node_handle.getParam("integral_gain", integral_gain)) {
        throw std::runtime_error("integral_gain not provided.");
    }

    if (!m_node_handle.getParam("derivative_gain", derivative_gain)) {
        throw std::runtime_error("derivative_gain not provided.");
    }

    {
        m_pid[m_left_front_id] = std::unique_ptr<PID>(new PID(proportional_gain, integral_gain, derivative_gain));

        hardware_interface::JointStateHandle joint_state_handle("left_front", &m_position[m_left_front_id], &m_velocity[m_left_front_id], &m_effort[m_left_front_id]);
        hardware_interface::JointHandle joint_velocity_handle(joint_state_handle, &m_command[m_left_front_id]);

        m_joint_state_interface.registerHandle(joint_state_handle);
        m_joint_velocity_interface.registerHandle(joint_velocity_handle);
    }

    {
        m_pid[m_left_back_id] = std::unique_ptr<PID>(new PID(proportional_gain, integral_gain, derivative_gain));

        hardware_interface::JointStateHandle joint_state_handle("left_back", &m_position[m_left_back_id], &m_velocity[m_left_back_id], &m_effort[m_left_back_id]);
        hardware_interface::JointHandle joint_velocity_handle(joint_state_handle, &m_command[m_left_back_id]);

        m_joint_state_interface.registerHandle(joint_state_handle);
        m_joint_velocity_interface.registerHandle(joint_velocity_handle);
    }

    {
        m_pid[m_right_front_id] = std::unique_ptr<PID>(new PID(proportional_gain, integral_gain, derivative_gain));

        hardware_interface::JointStateHandle joint_state_handle("right_front", &m_position[m_right_front_id], &m_velocity[m_right_front_id], &m_effort[m_right_front_id]);
        hardware_interface::JointHandle joint_velocity_handle(joint_state_handle, &m_command[m_right_front_id]);

        m_joint_state_interface.registerHandle(joint_state_handle);
        m_joint_velocity_interface.registerHandle(joint_velocity_handle);
    }

    {
        m_pid[m_right_back_id] = std::unique_ptr<PID>(new PID(proportional_gain, integral_gain, derivative_gain));

        hardware_interface::JointStateHandle joint_state_handle("right_back", &m_position[m_right_back_id], &m_velocity[m_right_back_id], &m_effort[m_right_back_id]);
        hardware_interface::JointHandle joint_velocity_handle(joint_state_handle, &m_command[m_right_back_id]);

        m_joint_state_interface.registerHandle(joint_state_handle);
        m_joint_velocity_interface.registerHandle(joint_velocity_handle);
    }

    hardware_interface::RobotHW::registerInterface(&m_joint_state_interface);
    hardware_interface::RobotHW::registerInterface(&m_joint_velocity_interface);

    m_get_rotary_encoder_client[m_left_front_id] = m_node_handle.serviceClient<rotary_encoder::get_rotary_encoder>(ros::names::resolve(serial_port + "/" + std::to_string(m_left_front_id) + "/get_rotary_encoder"));
    m_get_rotary_encoder_client[m_left_back_id] = m_node_handle.serviceClient<rotary_encoder::get_rotary_encoder>(ros::names::resolve(serial_port + "/" + std::to_string(m_left_back_id) + "/get_rotary_encoder"));
    m_get_rotary_encoder_client[m_right_front_id] = m_node_handle.serviceClient<rotary_encoder::get_rotary_encoder>(ros::names::resolve(serial_port + "/" + std::to_string(m_right_front_id) + "/get_rotary_encoder"));
    m_get_rotary_encoder_client[m_right_back_id] = m_node_handle.serviceClient<rotary_encoder::get_rotary_encoder>(ros::names::resolve(serial_port + "/" + std::to_string(m_right_back_id) + "/get_rotary_encoder"));

    m_set_stepper_motor_client[m_left_front_id] = m_node_handle.serviceClient<stepper_motor::set_stepper_motor>(ros::names::resolve(serial_port + "/" + std::to_string(m_left_front_id) + "/set_stepper_motor"));
    m_set_stepper_motor_client[m_left_back_id] = m_node_handle.serviceClient<stepper_motor::set_stepper_motor>(ros::names::resolve(serial_port + "/" + std::to_string(m_left_back_id) + "/set_stepper_motor"));
    m_set_stepper_motor_client[m_right_front_id] = m_node_handle.serviceClient<stepper_motor::set_stepper_motor>(ros::names::resolve(serial_port + "/" + std::to_string(m_right_front_id) + "/set_stepper_motor"));
    m_set_stepper_motor_client[m_right_back_id] = m_node_handle.serviceClient<stepper_motor::set_stepper_motor>(ros::names::resolve(serial_port + "/" + std::to_string(m_right_back_id) + "/set_stepper_motor"));
}

void MobileHardwareNode::read(ros::Duration const &period) 
{
    rotary_encoder::get_rotary_encoder get_rotary_encoder_srv;

    {
        if (!m_get_rotary_encoder_client[m_left_front_id].call(get_rotary_encoder_srv)) {
            throw std::runtime_error("Failed to get left-front rotary encoder.");
        }
        else {
            m_position[m_left_front_id] = static_cast<double>(get_rotary_encoder_srv.response.position);
            m_velocity[m_left_front_id] = static_cast<double>(get_rotary_encoder_srv.response.velocity);
        }
    }

    {
        if (!m_get_rotary_encoder_client[m_left_back_id].call(get_rotary_encoder_srv)) {
            throw std::runtime_error("Failed to get left-back rotary encoder.");
        }
        else {
            m_position[m_left_back_id] = static_cast<double>(get_rotary_encoder_srv.response.position);
            m_velocity[m_left_back_id] = static_cast<double>(get_rotary_encoder_srv.response.velocity);
        }
    }
    
    {
        if (!m_get_rotary_encoder_client[m_right_front_id].call(get_rotary_encoder_srv)) {
            throw std::runtime_error("Failed to get right-front rotary encoder.");
        }
        else {
            m_position[m_right_front_id] = static_cast<double>(get_rotary_encoder_srv.response.position);
            m_velocity[m_right_front_id] = static_cast<double>(get_rotary_encoder_srv.response.velocity);
        }
    }
    
    {
        if (!m_get_rotary_encoder_client[m_right_back_id].call(get_rotary_encoder_srv)) {
            throw std::runtime_error("Failed to get right-back rotary encoder.");
        }
        else {
            m_position[m_right_back_id] = static_cast<double>(get_rotary_encoder_srv.response.position);
            m_velocity[m_right_back_id] = static_cast<double>(get_rotary_encoder_srv.response.velocity);
        }
    }
}

void MobileHardwareNode::write(ros::Duration const &period) 
{
    stepper_motor::set_stepper_motor set_stepper_motor_srv;

    {
        set_stepper_motor_srv.request.velocity = static_cast<float>(m_pid[m_left_front_id]->compute(m_command[m_left_front_id] - m_velocity[m_left_front_id], period.toSec()));

        if (!m_set_stepper_motor_client[m_left_front_id].call(set_stepper_motor_srv)) {
            throw std::runtime_error("Failed to set left-front stepper motor.");
        }
    }

    {
        set_stepper_motor_srv.request.velocity = static_cast<float>(m_pid[m_left_back_id]->compute(m_command[m_left_back_id] - m_velocity[m_left_back_id], period.toSec()));

        if (!m_set_stepper_motor_client[m_left_back_id].call(set_stepper_motor_srv)) {
            throw std::runtime_error("Failed to set left-back stepper motor.");
        }
    }

    {
        set_stepper_motor_srv.request.velocity = static_cast<float>(m_pid[m_right_front_id]->compute(m_command[m_right_front_id] - m_velocity[m_right_front_id], period.toSec()));

        if (!m_set_stepper_motor_client[m_right_front_id].call(set_stepper_motor_srv)) {
            throw std::runtime_error("Failed to set right-front stepper motor.");
        }
    }

    {
        set_stepper_motor_srv.request.velocity = static_cast<float>(m_pid[m_right_back_id]->compute(m_command[m_right_back_id] - m_velocity[m_right_back_id], period.toSec()));

        if (!m_set_stepper_motor_client[m_right_back_id].call(set_stepper_motor_srv)) {
            throw std::runtime_error("Failed to set right-back stepper motor.");
        }
    }
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "mobile_hardware");

    ros::NodeHandle node_handle("~");
    
    try {
        MobileHardwareNode mobile_hardware_node(node_handle);

        controller_manager::ControllerManager controller_manager(&mobile_hardware_node, node_handle);
        
        ros::Time then = ros::Time::now();

        while (ros::ok()) {
            ros::Time const now = ros::Time::now();

            ros::Duration const period = now - then;

            then = now;

            mobile_hardware_node.read(period);

            controller_manager.update(now, period);

            mobile_hardware_node.write(period);

            ros::spinOnce();
        }

        return 0;
    }
    catch (std::exception const &exception) {
        ROS_ERROR_STREAM(exception.what());

        return 1;
    }
}
