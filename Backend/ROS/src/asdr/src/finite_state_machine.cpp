#include "finite_state_machine.hpp"

Context::Context(ros::NodeHandle const &node_handle) : 
    m_node_handle { node_handle }, 
    m_move_base_client { new actionlib::SimpleActionClient<move_base_msgs::MoveBaseAction>("move_base", true) }
{
    if (!m_move_base_client->waitForServer(ros::Duration(10.0))) {
        throw std::runtime_error("Failed to load move_base action client.");
    }
}

void Idle::enter(Control &control) noexcept 
{
    ROS_INFO_STREAM("Idle state entered.");
}

void Idle::update(FullControl &control) noexcept 
{
}

void Idle::exit(Control &control) noexcept
{
    ROS_INFO_STREAM("Idle state exited.");
}

void Manual::enter(Control &control) noexcept 
{
    ROS_INFO_STREAM("Manual state entered.");
}

void Manual::update(FullControl &control) noexcept 
{
}

void Manual::exit(Control &control) noexcept
{
    ROS_INFO_STREAM("Manual state exited.");
}

void Automatic::entryGuard(GuardControl &control) noexcept 
{    
    try {
        m_realsense_pid = m_ros_launch_manager.start(
            "realsense2_camera", "rs_camera.launch",
            "align_depth:=true");

        m_rtabmap_pid = m_ros_launch_manager.start(
            "rtabmap_ros", "rtabmap.launch", 
            "rtabmap_args:=\"--delete_db_on_start\"", 
            "rtabmapviz:=false",
            "depth_topic:=/camera/aligned_depth_to_color/image_raw", 
            "rgb_topic:=/camera/color/image_raw",
            "camera_info_topic:=/camera/color/camera_info",
            "approx_sync:=false",
            "wait_imu_to_init:=true",
            "imu_topic:=/imu/data");
    }
    catch (std::exception const &exception) {
        ROS_ERROR_STREAM(exception.what());

        control.changeTo<Idle>();
    }
}

void Automatic::enter(Control &control) noexcept
{
    ROS_INFO_STREAM("Automatic state entered.");
}

void Automatic::update(FullControl &control) noexcept 
{
}

void Automatic::exitGuard(GuardControl &control) noexcept
{
    try {
        m_ros_launch_manager.stop(m_rtabmap_pid, SIGINT);
        m_ros_launch_manager.stop(m_realsense_pid, SIGINT);
    }
    catch (std::exception const &exception) {
        ROS_ERROR_STREAM(exception.what());

        control.changeTo<Idle>();
    }
}

void Automatic::exit(Control &control) noexcept
{
    ROS_INFO_STREAM("Automatic state exited.");
}

void Delay::enter(Control &control) noexcept 
{
    ROS_INFO_STREAM("Delay state entered.");
    
    m_start = ros::Time::now();
    m_delay = ros::Duration(10.0);
}

void Delay::update(FullControl &control) noexcept 
{
    if (ros::Time::now() > m_start + m_delay) {
        control.changeTo<Map>();
    }
}

void Delay::exit(Control &control) noexcept
{
    ROS_INFO_STREAM("Delay state exited.");
}

void Map::entryGuard(GuardControl &control) noexcept 
{
    try {
        m_set_mode_mapping_client = control.context().m_node_handle.serviceClient<std_srvs::Empty>("/rtabmap/set_mode_mapping");

        std_srvs::Empty set_mode_mapping_srv;

        if (!m_set_mode_mapping_client.call(set_mode_mapping_srv)) {
            throw std::runtime_error("Failed to set RTABMAP mode to mapping.");
        }
    }
    catch (std::exception const &exception) {
        ROS_ERROR_STREAM(exception.what());

        control.changeTo<Idle>();
    }
}

void Map::enter(Control &control) noexcept
{
    ROS_INFO_STREAM("Map state entered.");
}

void Map::exit(Control &control) noexcept
{
    ROS_INFO_STREAM("Map state exited.");
}

void Observe::enter(Control &control) noexcept 
{
    ROS_INFO_STREAM("Observe state entered.");
}

void Observe::update(FullControl &control) noexcept 
{
    control.changeTo<Explore>();
}

void Observe::exit(Control &control) noexcept
{
    ROS_INFO_STREAM("Observe state exited.");
}

void Explore::entryGuard(GuardControl &control) noexcept 
{
    try {
        m_discover_client = control.context().m_node_handle.serviceClient<discovery::discover>("/asdr/discover");

        discovery::discover discover_srv;

        if (!m_discover_client.call(discover_srv)) {
            throw std::runtime_error("Failed to discover.");
        }
        else {
            if (discover_srv.response.status == discovery::discover::Response::FAILURE) {
                control.changeTo<Disinfect>();
            }
            else if (discover_srv.response.status == discovery::discover::Response::SUCCESS) {
                move_base_msgs::MoveBaseGoal goal;

                goal.target_pose.header.frame_id = "base_link";
                goal.target_pose.header.stamp = ros::Time::now();

                goal.target_pose.pose = discover_srv.response.pose;
                
                control.context().m_move_base_client->sendGoal(goal);
            }
        }
    }
    catch (std::exception const &exception) {
        ROS_ERROR_STREAM(exception.what());

        control.changeTo<Idle>();
    }
}

void Explore::enter(Control &control) noexcept 
{
    ROS_INFO_STREAM("Explore state entered.");
}

void Explore::update(FullControl &control) noexcept 
{
    try {
        if (control.context().m_move_base_client->getState() == actionlib::SimpleClientGoalState::ABORTED) {
            throw std::runtime_error("Navigation aborted.");
        }
        else if(control.context().m_move_base_client->getState() == actionlib::SimpleClientGoalState::SUCCEEDED) {
            control.changeTo<Observe>();
        }
    }
    catch (std::exception const &exception) {
        ROS_ERROR_STREAM(exception.what());

        control.changeTo<Idle>();
    }
}

void Explore::exit(Control &control) noexcept
{
    ROS_INFO_STREAM("Explore state exited.");
}

void Disinfect::entryGuard(GuardControl &control) noexcept 
{
    try {
        m_set_mode_localization_client = control.context().m_node_handle.serviceClient<std_srvs::Empty>("/rtabmap/set_mode_localization");
        m_set_uvc_light_client = control.context().m_node_handle.serviceClient<uvc_light::set_uvc_light>("/dev/ttyUSB0/set_uvc_light");
        
        std_srvs::Empty set_mode_localization_srv;

        if (!m_set_mode_localization_client.call(set_mode_localization_srv)) {
            throw std::runtime_error("Failed to set RTABMAP mode to localization.");
        }

        uvc_light::set_uvc_light set_uvc_light_srv;

        set_uvc_light_srv.request.state = uvc_light::set_uvc_light::Request::ON;

        if (!m_set_uvc_light_client.call(set_uvc_light_srv)) {
            throw std::runtime_error("Failed to turn UVC light on.");
        }
    }
    catch (std::exception const &exception) {
        ROS_ERROR_STREAM(exception.what());

        control.changeTo<Idle>();
    }
}

void Disinfect::enter(Control &control) noexcept
{
    ROS_INFO_STREAM("Disinfect state entered.");
}

void Disinfect::update(FullControl &control) noexcept
{
}

void Disinfect::exitGuard(GuardControl &control) noexcept
{
    try {
        uvc_light::set_uvc_light set_uvc_light_srv;

        set_uvc_light_srv.request.state = uvc_light::set_uvc_light::Request::OFF;

        if (!m_set_uvc_light_client.call(set_uvc_light_srv)) {
            throw std::runtime_error("Failed to turn UVC light off.");
        }
    }
    catch (std::exception const &exception) {
        ROS_ERROR_STREAM(exception.what());

        control.changeTo<Idle>();
    }
}

void Disinfect::exit(Control &control) noexcept
{
    ROS_INFO_STREAM("Disinfect state exited.");
}

void Navigate::entryGuard(GuardControl &control) noexcept 
{
    try {
        m_make_plan_client = control.context().m_node_handle.serviceClient<coverage_path_planner::make_plan>("/asdr/make_plan");

        coverage_path_planner::make_plan make_plan_srv;

        if (!m_make_plan_client.call(make_plan_srv)) {
            throw std::runtime_error("Failed to make a plan.");
        }
        else {
            m_plan = make_plan_srv.response.plan;

            m_plan_iterator = std::cbegin(m_plan);

            if (m_plan_iterator == std::cend(m_plan)) {
                throw std::runtime_error("Plan is empty.");
            }
            else {
                ROS_INFO_STREAM("Navigating to waypoint " << (std::distance(std::cbegin(m_plan), m_plan_iterator) + 1) << " of "  << std::size(m_plan) << ".");

                move_base_msgs::MoveBaseGoal goal;

                goal.target_pose.header.frame_id = "base_link";
                goal.target_pose.header.stamp = ros::Time::now();

                goal.target_pose.pose = *m_plan_iterator;

                control.context().m_move_base_client->sendGoal(goal);
            }
        }
    }
    catch (std::exception const &exception) {
        ROS_ERROR_STREAM(exception.what());

        control.changeTo<Idle>();
    }
}

void Navigate::enter(Control &control) noexcept
{
    ROS_INFO_STREAM("Navigate state entered.");
}

void Navigate::update(FullControl &control) noexcept
{
    try {
        if (control.context().m_move_base_client->getState() == actionlib::SimpleClientGoalState::ABORTED) {
            throw std::runtime_error("Navigation aborted.");
        }
        else if(control.context().m_move_base_client->getState() == actionlib::SimpleClientGoalState::SUCCEEDED) {
            m_plan_iterator = std::next(m_plan_iterator);

            if (m_plan_iterator == std::cend(m_plan)) {
                control.changeTo<Idle>();
            }
            else {
                ROS_INFO_STREAM("Navigating to waypoint " << (std::distance(std::cbegin(m_plan), m_plan_iterator) + 1) << " of "  << std::size(m_plan) << ".");

                move_base_msgs::MoveBaseGoal goal;

                goal.target_pose.header.frame_id = "base_link";
                goal.target_pose.header.stamp = ros::Time::now();

                goal.target_pose.pose = *m_plan_iterator;

                control.context().m_move_base_client->sendGoal(goal);
            }
        }
    }
    catch (std::exception const &exception) {
        ROS_ERROR_STREAM(exception.what());

        control.changeTo<Idle>();
    }   
}

void Navigate::exit(Control &control) noexcept
{
    ROS_INFO_STREAM("Navigate state exited.");
}
