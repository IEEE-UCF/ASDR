# %Tag(FULLTEXT)%
cmake_minimum_required(VERSION 3.8)
project(uvc_light)

## Find catkin and any catkin packages
find_package(catkin REQUIRED COMPONENTS roscpp rospy std_msgs genmsg serial_command_client)

add_service_files(FILES set_uvc_light.srv)

## Generate added messages and services
generate_messages(DEPENDENCIES std_msgs)

## Declare a catkin package
catkin_package()

## Build talker and listener
include_directories(include ${catkin_INCLUDE_DIRS})

# %Tag(SRVCLIENT)%

add_executable(uvc_light_node src/uvc_light_node.cpp)
target_link_libraries(uvc_light_node ${catkin_LIBRARIES})
add_dependencies(uvc_light_node uvc_light_gencpp ${catkin_EXPORTED_TARGETS})
set_property(TARGET uvc_light_node PROPERTY CXX_STANDARD 17)

# %EndTag(SRVCLIENT)%

# %EndTag(FULLTEXT)%

