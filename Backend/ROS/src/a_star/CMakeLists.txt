# %Tag(FULLTEXT)%
cmake_minimum_required(VERSION 3.8)
project(a_star)

## Find catkin and any catkin packages
find_package(catkin REQUIRED COMPONENTS tf roscpp rospy pcl_conversions std_msgs nav_msgs geometry_msgs sensor_msgs visualization_msgs genmsg)

find_package(PCL 1.10)

find_package(Eigen3 3.3 REQUIRED NO_MODULE)

add_service_files(FILES a_star.srv)

## Generate added messages and services
generate_messages(DEPENDENCIES std_msgs nav_msgs geometry_msgs sensor_msgs visualization_msgs)

## Declare a catkin package
catkin_package()

## Build talker and listener
include_directories(include ${catkin_INCLUDE_DIRS} ${PCL_INCLUDE_DIRS})

add_definitions(${PCL_DEFINITIONS})
# %Tag(SRVCLIENT)%

add_executable(a_star_node src/a_star_node.cpp src/a_star.cpp)
target_link_libraries(a_star_node ${catkin_LIBRARIES} ${PCL_LIBRARIES} Eigen3::Eigen)
add_dependencies(a_star_node a_star_gencpp)
set_property(TARGET a_star_node PROPERTY CXX_STANDARD 17)

# %EndTag(SRVCLIENT)%

# %EndTag(FULLTEXT)%

