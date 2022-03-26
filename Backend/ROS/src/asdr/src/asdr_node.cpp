#include "asdr_node.hpp"

ASDRNode::ASDRNode(ros::NodeHandle const &node_handle) : 
    m_node_handle { node_handle },
    m_finite_state_machine { { node_handle } }
{
    if (!m_node_handle.getParam("/asdr/mobile_base_controller/linear/x/max_velocity", m_max_linear_velocity)) {
        throw std::runtime_error("/asdr/mobile_base_controller/linear/x/max_velocity not provided.");
    }
    
    if (!m_node_handle.getParam("/asdr/mobile_base_controller/linear/x/min_velocity", m_min_linear_velocity)) {
        throw std::runtime_error("/asdr/mobile_base_controller/linear/x/min_velocity not provided.");
    }

    if (!m_node_handle.getParam("/asdr/mobile_base_controller/angular/z/max_velocity", m_max_angular_velocity)) {
        throw std::runtime_error("/asdr/mobile_base_controller/angular/z/max_velocity not provided.");
    }
    
    if (!m_node_handle.getParam("/asdr/mobile_base_controller/angular/z/min_velocity", m_min_angular_velocity)) {
        throw std::runtime_error("/asdr/mobile_base_controller/angular/z/min_velocity not provided.");
    }

    m_get_state_server = m_node_handle.advertiseService(ros::names::resolve("get_state"), &ASDRNode::onGetState, this);
    m_set_state_server = m_node_handle.advertiseService(ros::names::resolve("set_state"), &ASDRNode::onSetState, this);
    m_set_velocity_server = m_node_handle.advertiseService(ros::names::resolve("set_velocity"), &ASDRNode::onSetVelocity, this);

    m_cmd_vel_publisher = m_node_handle.advertise<geometry_msgs::Twist>(ros::names::resolve("cmd_vel"), 100);
}

void ASDRNode::update()
{
    m_finite_state_machine.update();
}

bool ASDRNode::onGetState(asdr::get_state::Request &request, asdr::get_state::Response &response)
{
    if (m_finite_state_machine.isActive<Idle>()) {
        response.state = "Idle";

        return true;
    }
    else if (m_finite_state_machine.isActive<Manual>()) {
        response.state = "Manual";

        return true;
    }
    else if (m_finite_state_machine.isActive<Automatic>()) {
        if (m_finite_state_machine.isActive<Delay>()) {
            response.state = "Automatic::Delay"; 

            return true;
        }
        else if (m_finite_state_machine.isActive<Map>()) {
            if (m_finite_state_machine.isActive<Observe>()) {
                response.state = "Automatic::Map::Observe";

                return true;
            }
            else if (m_finite_state_machine.isActive<Explore>()) {
                response.state = "Automatic::Map::Explore";

                return true;
            }
            else {
                response.state = "Automatic::Map";

                return true;
            }
        }
        else if (m_finite_state_machine.isActive<Disinfect>()) {
            if (m_finite_state_machine.isActive<Navigate>()) {
                response.state = "Automatic::Disinfect::Navigate";

                return true;
            }
            else {
                response.state = "Automatic::Disinfect";

                return true;
            }
        }
        else {
            response.state = "Automatic"; 

            return true;
        }
    }

    return false;
}

bool ASDRNode::onSetState(asdr::set_state::Request &request, asdr::set_state::Response &response)
{
    if (request.state == "Idle") {
        m_finite_state_machine.changeTo<Idle>();

        return true;
    }
    else if (request.state == "Manual") {
        m_finite_state_machine.changeTo<Manual>();

        return true;
    }
    else if (request.state == "Automatic") {
        m_finite_state_machine.changeTo<Automatic>();

        return true;
    }
    
    return false;
}

bool ASDRNode::onSetVelocity(asdr::set_velocity::Request &request, asdr::set_velocity::Response &response)
{
    if (m_finite_state_machine.isActive<Manual>()) {
        geometry_msgs::Twist cmd_vel_msg;

        cmd_vel_msg.linear.x = (request.linear + 1.0) * 0.5 * (m_max_linear_velocity - m_min_linear_velocity) + m_min_linear_velocity;
        cmd_vel_msg.linear.y = 0.0;
        cmd_vel_msg.linear.z = 0.0;

        cmd_vel_msg.angular.x = 0.0;
        cmd_vel_msg.angular.y = 0.0;
        cmd_vel_msg.angular.z = (request.angular + 1.0) * 0.5 * (m_max_angular_velocity - m_min_angular_velocity) + m_min_angular_velocity;

        m_cmd_vel_publisher.publish(cmd_vel_msg);

        return true;
    }
    
    return false;
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "asdr");

    ros::NodeHandle node_handle("~");

    try {
        ASDRNode asdr_node(node_handle);
        
        while (ros::ok()) {
            asdr_node.update();

            ros::spinOnce();
        }

        return 0;
    }
    catch (std::exception const &exception) {
        ROS_ERROR_STREAM(exception.what());

        return 1;
    }
}
