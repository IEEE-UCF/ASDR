#include "mobile_base_node.hpp"

MobileBaseNode::MobileBaseNode(ros::NodeHandle const &node_handle) : 
    m_node_handle { node_handle },
    m_pid { { { { { 0.1, 0.05, 0.01 }, { 0.1, 0.05, 0.01 } } }, { { { 0.1, 0.05, 0.01 }, { 0.1, 0.05, 0.01 } } } } },
    m_position { { { 0.0, 0.0 }, { 0.0, 0.0 } } },
    m_velocity { { { 0.0, 0.0 }, { 0.0, 0.0 } } },
    m_effort { { { 0.0, 0.0 }, { 0.0, 0.0 } } },
    m_command { { { 0.0, 0.0 }, { 0.0, 0.0 } } }
{
    {
        hardware_interface::JointStateHandle joint_state_handle("left_front", &m_position[LEFT][FRONT], &m_velocity[LEFT][FRONT], &m_effort[LEFT][FRONT]);
        hardware_interface::JointHandle joint_velocity_handle(joint_state_handle, &m_command[LEFT][FRONT]);

        m_joint_state_interface.registerHandle(joint_state_handle);
        m_joint_velocity_interface.registerHandle(joint_velocity_handle);
    }

    {
        hardware_interface::JointStateHandle joint_state_handle("left_back", &m_position[LEFT][BACK], &m_velocity[LEFT][BACK], &m_effort[LEFT][BACK]);
        hardware_interface::JointHandle joint_velocity_handle(joint_state_handle, &m_command[LEFT][BACK]);

        m_joint_state_interface.registerHandle(joint_state_handle);
        m_joint_velocity_interface.registerHandle(joint_velocity_handle);
    }

    {
        hardware_interface::JointStateHandle joint_state_handle("right_front", &m_position[RIGHT][FRONT], &m_velocity[RIGHT][FRONT], &m_effort[RIGHT][FRONT]);
        hardware_interface::JointHandle joint_velocity_handle(joint_state_handle, &m_command[RIGHT][FRONT]);

        m_joint_state_interface.registerHandle(joint_state_handle);
        m_joint_velocity_interface.registerHandle(joint_velocity_handle);
    }

    {
        hardware_interface::JointStateHandle joint_state_handle("right_back", &m_position[RIGHT][BACK], &m_velocity[RIGHT][BACK], &m_effort[RIGHT][BACK]);
        hardware_interface::JointHandle joint_velocity_handle(joint_state_handle, &m_command[RIGHT][BACK]);

        m_joint_state_interface.registerHandle(joint_state_handle);
        m_joint_velocity_interface.registerHandle(joint_velocity_handle);
    }

    hardware_interface::RobotHW::registerInterface(&m_joint_state_interface);
    hardware_interface::RobotHW::registerInterface(&m_joint_velocity_interface);

    m_get_rotary_encoder_client[LEFT][FRONT] = m_node_handle.serviceClient<rotary_encoder::get_rotary_encoder>(ros::names::resolve("/dev/ttyUSB1/" + std::to_string(FRONT) + "/get_rotary_encoder"));
    m_get_rotary_encoder_client[LEFT][BACK] = m_node_handle.serviceClient<rotary_encoder::get_rotary_encoder>(ros::names::resolve("/dev/ttyUSB1/" + std::to_string(BACK) + "/get_rotary_encoder"));
    m_get_rotary_encoder_client[RIGHT][FRONT] = m_node_handle.serviceClient<rotary_encoder::get_rotary_encoder>(ros::names::resolve("/dev/ttyUSB2/" + std::to_string(FRONT) + "/get_rotary_encoder"));
    m_get_rotary_encoder_client[RIGHT][BACK] = m_node_handle.serviceClient<rotary_encoder::get_rotary_encoder>(ros::names::resolve("/dev/ttyUSB2/" + std::to_string(BACK) + "/get_rotary_encoder"));

    m_set_stepper_motor_client[LEFT][FRONT] = m_node_handle.serviceClient<stepper_motor::set_stepper_motor>(ros::names::resolve("/dev/ttyUSB1/" + std::to_string(FRONT) + "/set_stepper_motor"));
    m_set_stepper_motor_client[LEFT][BACK] = m_node_handle.serviceClient<stepper_motor::set_stepper_motor>(ros::names::resolve("/dev/ttyUSB1/" + std::to_string(BACK) + "/set_stepper_motor"));
    m_set_stepper_motor_client[RIGHT][FRONT] = m_node_handle.serviceClient<stepper_motor::set_stepper_motor>(ros::names::resolve("/dev/ttyUSB2/" + std::to_string(FRONT) + "/set_stepper_motor"));
    m_set_stepper_motor_client[RIGHT][BACK] = m_node_handle.serviceClient<stepper_motor::set_stepper_motor>(ros::names::resolve("/dev/ttyUSB2/" + std::to_string(BACK) + "/set_stepper_motor"));
}

void MobileBaseNode::read(ros::Duration const &period) 
{
    rotary_encoder::get_rotary_encoder get_rotary_encoder_srv;

    {
        if (!m_get_rotary_encoder_client[LEFT][FRONT].call(get_rotary_encoder_srv)) {
            throw std::runtime_error("Failed to get left-front rotary encoder.");
        }
        else {
            m_position[LEFT][FRONT] = static_cast<double>(get_rotary_encoder_srv.response.position);
            m_velocity[LEFT][FRONT] = static_cast<double>(get_rotary_encoder_srv.response.velocity);
        }
    }

    {
        if (!m_get_rotary_encoder_client[LEFT][BACK].call(get_rotary_encoder_srv)) {
            throw std::runtime_error("Failed to get left-back rotary encoder.");
        }
        else {
            m_position[LEFT][BACK] = static_cast<double>(get_rotary_encoder_srv.response.position);
            m_velocity[LEFT][BACK] = static_cast<double>(get_rotary_encoder_srv.response.velocity);
        }
    }
    
    {
        if (!m_get_rotary_encoder_client[RIGHT][FRONT].call(get_rotary_encoder_srv)) {
            throw std::runtime_error("Failed to get right-front rotary encoder.");
        }
        else {
            m_position[RIGHT][FRONT] = static_cast<double>(get_rotary_encoder_srv.response.position);
            m_velocity[RIGHT][FRONT] = static_cast<double>(get_rotary_encoder_srv.response.velocity);
        }
    }
    
    {
        if (!m_get_rotary_encoder_client[RIGHT][BACK].call(get_rotary_encoder_srv)) {
            throw std::runtime_error("Failed to get right-back rotary encoder.");
        }
        else {
            m_position[RIGHT][BACK] = static_cast<double>(get_rotary_encoder_srv.response.position);
            m_velocity[RIGHT][BACK] = static_cast<double>(get_rotary_encoder_srv.response.velocity);
        }
    }
}

void MobileBaseNode::write(ros::Duration const &period) 
{
    stepper_motor::set_stepper_motor set_stepper_motor_srv;

    {
        set_stepper_motor_srv.request.velocity = static_cast<float>(m_pid[LEFT][FRONT].compute(m_command[LEFT][FRONT] - m_velocity[LEFT][FRONT], period.toSec()));

        if (!m_set_stepper_motor_client[LEFT][FRONT].call(set_stepper_motor_srv)) {
            throw std::runtime_error("Failed to set left-front stepper motor.");
        }
    }

    {
        set_stepper_motor_srv.request.velocity = static_cast<float>(m_pid[LEFT][BACK].compute(m_command[LEFT][BACK] - m_velocity[LEFT][BACK], period.toSec()));

        if (!m_set_stepper_motor_client[LEFT][BACK].call(set_stepper_motor_srv)) {
            throw std::runtime_error("Failed to set left-back stepper motor.");
        }
    }

    {
        set_stepper_motor_srv.request.velocity = static_cast<float>(m_pid[RIGHT][FRONT].compute(m_command[RIGHT][FRONT] - m_velocity[RIGHT][FRONT], period.toSec()));

        if (!m_set_stepper_motor_client[RIGHT][FRONT].call(set_stepper_motor_srv)) {
            throw std::runtime_error("Failed to set right-front stepper motor.");
        }
    }

    {
        set_stepper_motor_srv.request.velocity = static_cast<float>(m_pid[RIGHT][BACK].compute(m_command[RIGHT][BACK] - m_velocity[RIGHT][BACK], period.toSec()));

        if (!m_set_stepper_motor_client[RIGHT][BACK].call(set_stepper_motor_srv)) {
            throw std::runtime_error("Failed to set right-back stepper motor.");
        }
    }
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "mobile_base");

    ros::NodeHandle node_handle("~");
    
    try {
        MobileBaseNode mobile_base_node(node_handle);

        controller_manager::ControllerManager controller_manager(&mobile_base_node, node_handle);
        
        ros::Time then = ros::Time::now();

        while (ros::ok()) {
            ros::Time const now = ros::Time::now();

            ros::Duration const period = now - then;

            then = now;

            mobile_base_node.read(period);

            controller_manager.update(now, period);

            mobile_base_node.write(period);

            ros::spinOnce();
        }

        return 0;
    }
    catch (std::exception const &exception) {
        ROS_ERROR_STREAM(exception.what());

        return 1;
    }
}
