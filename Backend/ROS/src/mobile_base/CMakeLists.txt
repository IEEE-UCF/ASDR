# %Tag(FULLTEXT)%
cmake_minimum_required(VERSION 3.8)
project(mobile_base)

## Find catkin and any catkin packages
find_package(catkin REQUIRED COMPONENTS roscpp rospy std_msgs genmsg controller_manager hardware_interface rotary_encoder stepper_motor)

## Generate added messages and services
generate_messages(DEPENDENCIES std_msgs)

## Declare a catkin package
catkin_package()

## Build talker and listener
include_directories(include ${catkin_INCLUDE_DIRS})

# %Tag(SRVCLIENT)%

add_executable(mobile_base_node src/mobile_base_node.cpp src/pid.cpp)
target_link_libraries(mobile_base_node ${catkin_LIBRARIES})
add_dependencies(mobile_base_node mobile_base_gencpp ${catkin_EXPORTED_TARGETS})
set_property(TARGET mobile_base_node PROPERTY CXX_STANDARD 17)

# %EndTag(SRVCLIENT)%

# %EndTag(FULLTEXT)%

