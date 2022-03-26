# %Tag(FULLTEXT)%
cmake_minimum_required(VERSION 3.8)
project(stepper_motor)

## Find catkin and any catkin packages
find_package(catkin REQUIRED COMPONENTS roscpp rospy std_msgs genmsg serial_command_client)

add_service_files(FILES set_stepper_motor.srv)

## Generate added messages and services
generate_messages(DEPENDENCIES std_msgs)

## Declare a catkin package
catkin_package()

## Build talker and listener
include_directories(include ${catkin_INCLUDE_DIRS})

# %Tag(SRVCLIENT)%

add_executable(stepper_motor_node src/stepper_motor_node.cpp)
target_link_libraries(stepper_motor_node ${catkin_LIBRARIES})
add_dependencies(stepper_motor_node stepper_motor_gencpp ${catkin_EXPORTED_TARGETS})
set_property(TARGET stepper_motor_node PROPERTY CXX_STANDARD 17)

# %EndTag(SRVCLIENT)%

# %EndTag(FULLTEXT)%

