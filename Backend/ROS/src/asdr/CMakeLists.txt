# %Tag(FULLTEXT)%
cmake_minimum_required(VERSION 3.8)
project(asdr)

## Find catkin and any catkin packages
find_package(catkin REQUIRED COMPONENTS roscpp rospy std_msgs genmsg actionlib move_base_msgs uvc_light coverage_path_planner)

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

add_service_files(FILES get_state.srv set_state.srv set_velocity.srv)

## Generate added messages and services
generate_messages(DEPENDENCIES std_msgs)

## Declare a catkin package
catkin_package()

## Build talker and listener
include_directories(include HFSM2/include ${catkin_INCLUDE_DIRS})

# %Tag(SRVCLIENT)%

add_executable(asdr_node src/asdr_node.cpp src/finite_state_machine.cpp)
target_link_libraries(asdr_node ${catkin_LIBRARIES} Threads::Threads)
add_dependencies(asdr_node asdr_gencpp ${catkin_EXPORTED_TARGETS})
set_property(TARGET asdr_node PROPERTY CXX_STANDARD 17)

# %EndTag(SRVCLIENT)%

# %EndTag(FULLTEXT)%

