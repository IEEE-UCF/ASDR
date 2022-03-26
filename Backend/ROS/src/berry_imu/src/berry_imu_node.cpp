#include "berry_imu_node.hpp"

BerryIMUNode::BerryIMUNode(ros::NodeHandle const &node_handle) : 
    m_node_handle { node_handle }
{
    m_imu_publisher = m_node_handle.advertise<sensor_msgs::Imu>(ros::names::resolve("imu/data_raw"), 100);
    m_magnetic_field_publisher = m_node_handle.advertise<sensor_msgs::MagneticField>(ros::names::resolve("imu/mag"), 100);

    m_send_command_client = m_node_handle.serviceClient<serial_command_client::send_command>(ros::names::resolve("send_command"));
}

void BerryIMUNode::publish()
{
    static uint8_t const BERRY_IMU_COMMAND = 0;

    serial_command_client::send_command send_command_srv;

    send_command_srv.request.command = BERRY_IMU_COMMAND;

    if (!m_send_command_client.call(send_command_srv)) {
        throw std::runtime_error("Failed to call send_command.");
    }
    else {
        if (send_command_srv.response.status == serial_command_client::send_command::Response::FAILURE) {
            throw std::runtime_error("Response status of send_command service is FAILURE.");
        }

        if (std::size(send_command_srv.response.buffer) != sizeof(float) * 3 * 3) {
            throw std::runtime_error("Response size of send_command service is invalid.");
        }

        float gyr[3];
        float acc[3];
        float mag[3];

        std::memcpy(&gyr[0], &send_command_srv.response.buffer[sizeof(float) * 3 * 0], sizeof(float) * 3);
        std::memcpy(&acc[0], &send_command_srv.response.buffer[sizeof(float) * 3 * 1], sizeof(float) * 3);
        std::memcpy(&mag[0], &send_command_srv.response.buffer[sizeof(float) * 3 * 2], sizeof(float) * 3);

        sensor_msgs::Imu imu_msg;

        imu_msg.orientation.x = 0.0;
        imu_msg.orientation.y = 0.0;
        imu_msg.orientation.z = 0.0;
        imu_msg.orientation.w = 0.0;

        imu_msg.orientation_covariance[0] = -1.0;
        imu_msg.orientation_covariance[1] = 0.0;
        imu_msg.orientation_covariance[2] = 0.0;
        imu_msg.orientation_covariance[3] = 0.0;
        imu_msg.orientation_covariance[4] = 0.0;
        imu_msg.orientation_covariance[5] = 0.0;
        imu_msg.orientation_covariance[6] = 0.0;
        imu_msg.orientation_covariance[7] = 0.0;
        imu_msg.orientation_covariance[8] = 0.0;

        imu_msg.angular_velocity.x = gyr[0];
        imu_msg.angular_velocity.y = gyr[1];
        imu_msg.angular_velocity.z = gyr[2];

        imu_msg.angular_velocity_covariance[0] = 0.01;
        imu_msg.angular_velocity_covariance[1] = 0.0;
        imu_msg.angular_velocity_covariance[2] = 0.0;
        imu_msg.angular_velocity_covariance[3] = 0.0;
        imu_msg.angular_velocity_covariance[4] = 0.01;
        imu_msg.angular_velocity_covariance[5] = 0.0;
        imu_msg.angular_velocity_covariance[6] = 0.0;
        imu_msg.angular_velocity_covariance[7] = 0.0;
        imu_msg.angular_velocity_covariance[8] = 0.01;

        imu_msg.linear_acceleration.x = acc[0];
        imu_msg.linear_acceleration.y = acc[1];
        imu_msg.linear_acceleration.z = acc[2];

        imu_msg.linear_acceleration_covariance[0] = 0.01;
        imu_msg.linear_acceleration_covariance[1] = 0.0;
        imu_msg.linear_acceleration_covariance[2] = 0.0;
        imu_msg.linear_acceleration_covariance[3] = 0.0;
        imu_msg.linear_acceleration_covariance[4] = 0.01;
        imu_msg.linear_acceleration_covariance[5] = 0.0;
        imu_msg.linear_acceleration_covariance[6] = 0.0;
        imu_msg.linear_acceleration_covariance[7] = 0.0;
        imu_msg.linear_acceleration_covariance[8] = 0.01;

        imu_msg.header.stamp = ros::Time::now();
        imu_msg.header.frame_id = "berry_imu";

        m_imu_publisher.publish(imu_msg);
        
        sensor_msgs::MagneticField magnetic_field_msg;

        magnetic_field_msg.magnetic_field.x = mag[0];
        magnetic_field_msg.magnetic_field.y = mag[1];
        magnetic_field_msg.magnetic_field.z = mag[2];

        magnetic_field_msg.magnetic_field_covariance[0] = 0.01;
        magnetic_field_msg.magnetic_field_covariance[1] = 0.0;
        magnetic_field_msg.magnetic_field_covariance[2] = 0.0;
        magnetic_field_msg.magnetic_field_covariance[3] = 0.0;
        magnetic_field_msg.magnetic_field_covariance[4] = 0.01;
        magnetic_field_msg.magnetic_field_covariance[5] = 0.0;
        magnetic_field_msg.magnetic_field_covariance[6] = 0.0;
        magnetic_field_msg.magnetic_field_covariance[7] = 0.0;
        magnetic_field_msg.magnetic_field_covariance[8] = 0.01;

        magnetic_field_msg.header.stamp = ros::Time::now();
        magnetic_field_msg.header.frame_id = "berry_imu";

        m_magnetic_field_publisher.publish(magnetic_field_msg);
    }
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "berry_imu");

    ros::NodeHandle node_handle("~");

    try {
        BerryIMUNode berry_imu_node(node_handle);
        
        while (ros::ok()) {
            berry_imu_node.publish();

            ros::spinOnce();
        }

        return 0;
    }
    catch (std::exception const &exception) {
        ROS_ERROR_STREAM(exception.what());

        return 1;
    }
}
