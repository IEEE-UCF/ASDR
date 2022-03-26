# %Tag(FULLTEXT)%
cmake_minimum_required(VERSION 3.8)
project(rotary_encoder)

## Find catkin and any catkin packages
find_package(catkin REQUIRED COMPONENTS roscpp rospy std_msgs genmsg serial_command_client)

add_service_files(FILES get_rotary_encoder.srv)

## Generate added messages and services
generate_messages(DEPENDENCIES std_msgs)

## Declare a catkin package
catkin_package()

## Build talker and listener
include_directories(include ${catkin_INCLUDE_DIRS})

# %Tag(SRVCLIENT)%

add_executable(rotary_encoder_node src/rotary_encoder_node.cpp)
target_link_libraries(rotary_encoder_node ${catkin_LIBRARIES})
add_dependencies(rotary_encoder_node rotary_encoder_gencpp ${catkin_EXPORTED_TARGETS})
set_property(TARGET rotary_encoder_node PROPERTY CXX_STANDARD 17)

# %EndTag(SRVCLIENT)%

# %EndTag(FULLTEXT)%

