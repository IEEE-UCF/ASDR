# %Tag(FULLTEXT)%
cmake_minimum_required(VERSION 3.8)
project(serial_command_client)

## Find catkin and any catkin packages
find_package(catkin REQUIRED COMPONENTS roscpp rospy std_msgs genmsg serial)

add_service_files(FILES send_command.srv)

## Generate added messages and services
generate_messages(DEPENDENCIES std_msgs)

## Declare a catkin package
catkin_package()

## Build talker and listener
include_directories(include ${catkin_INCLUDE_DIRS})

# %Tag(SRVCLIENT)%

add_executable(serial_command_client_node src/serial_command_client_node.cpp src/serial_command_client.cpp)
target_link_libraries(serial_command_client_node ${catkin_LIBRARIES})
add_dependencies(serial_command_client_node serial_command_client_gencpp ${catkin_EXPORTED_TARGETS})
set_property(TARGET serial_command_client_node PROPERTY CXX_STANDARD 17)

# %EndTag(SRVCLIENT)%

# %EndTag(FULLTEXT)%

