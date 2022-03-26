#pragma once

#include <stdexcept>
#include <memory>
#include <vector>

#include "ros/ros.h"
#include "ros/console.h"

#include "actionlib/client/simple_action_client.h"
#include "move_base_msgs/MoveBaseAction.h"

#include "std_srvs/Empty.h"
#include "uvc_light/set_uvc_light.h"
#include "coverage_path_planner/make_plan.h"
#include "discovery/discover.h"

#include "ros_launch_manager.hpp"

#include "hfsm2/machine.hpp"

struct Context 
{
    Context(ros::NodeHandle const &node_handle);

    ros::NodeHandle m_node_handle;

    std::unique_ptr<actionlib::SimpleActionClient<move_base_msgs::MoveBaseAction>> m_move_base_client;
};

struct Idle;
struct Manual;
struct Automatic;
struct Delay;
struct Map;
struct Observe;
struct Explore;
struct Disinfect;
struct Navigate;

using Machine = hfsm2::MachineT<hfsm2::Config::ContextT<Context>>;
using FiniteStateMachine = Machine::PeerRoot<
                Idle,
                Manual,
                Machine::Composite<Automatic,
                    Delay,
                    Machine::Composite<Map,
                        Observe,
                        Explore
                    >,
                    Machine::Composite<Disinfect,
                        Navigate
                    >
                >
            >;

struct Idle : public FiniteStateMachine::State 
{
	void enter(Control &control) noexcept;
	void update(FullControl &control) noexcept;
    void exit(Control &control) noexcept;
};

struct Manual : public FiniteStateMachine::State
{
	void enter(Control &control) noexcept;
	void update(FullControl &control) noexcept;
    void exit(Control &control) noexcept;
};

struct Automatic : public FiniteStateMachine::State
{
    ROSLaunchManager m_ros_launch_manager;

    pid_t m_realsense_pid;
    pid_t m_rtabmap_pid;

	void entryGuard(GuardControl &control) noexcept;
    void enter(Control &control) noexcept;
	void update(FullControl &control) noexcept;
    void exitGuard(GuardControl &control) noexcept;
    void exit(Control &control) noexcept;
};

struct Delay : public FiniteStateMachine::State
{
    ros::Time m_start;
    ros::Duration m_delay;

	void enter(Control &control) noexcept;
	void update(FullControl &control) noexcept;
    void exit(Control &control) noexcept;
};

struct Map : public FiniteStateMachine::State
{
    ros::ServiceClient m_set_mode_mapping_client;

	void entryGuard(GuardControl &control) noexcept;
    void enter(Control &control) noexcept;
    void exit(Control &control) noexcept;
};

struct Observe : public FiniteStateMachine::State
{
	void enter(Control &control) noexcept;
	void update(FullControl &control) noexcept;
    void exit(Control &control) noexcept;
};

struct Explore : public FiniteStateMachine::State
{
    ros::ServiceClient m_discover_client;
    
	void entryGuard(GuardControl &control) noexcept;
	void enter(Control &control) noexcept;
	void update(FullControl &control) noexcept;
    void exit(Control &control) noexcept;
};

struct Disinfect : public FiniteStateMachine::State
{
    ros::ServiceClient m_set_mode_localization_client;
    ros::ServiceClient m_set_uvc_light_client;

	void entryGuard(GuardControl &control) noexcept;
    void enter(Control &control) noexcept;
	void update(FullControl &control) noexcept;
    void exitGuard(GuardControl &control) noexcept;
    void exit(Control &control) noexcept;
};

struct Navigate : public FiniteStateMachine::State
{
    ros::ServiceClient m_make_plan_client;

    std::vector<geometry_msgs::Pose> m_plan;
    std::vector<geometry_msgs::Pose>::const_iterator m_plan_iterator;

	void entryGuard(GuardControl &control) noexcept;
    void enter(Control &control) noexcept;
	void update(FullControl &control) noexcept;
    void exit(Control &control) noexcept;
};
