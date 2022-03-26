# generated from genmsg/cmake/pkg-genmsg.cmake.em

message(STATUS "coverage_path_planner: 0 messages, 1 services")

set(MSG_I_FLAGS "-Istd_msgs:/opt/ros/noetic/share/std_msgs/cmake/../msg;-Inav_msgs:/opt/ros/noetic/share/nav_msgs/cmake/../msg;-Igeometry_msgs:/opt/ros/noetic/share/geometry_msgs/cmake/../msg;-Isensor_msgs:/opt/ros/noetic/share/sensor_msgs/cmake/../msg;-Ivisualization_msgs:/opt/ros/noetic/share/visualization_msgs/cmake/../msg;-Iactionlib_msgs:/opt/ros/noetic/share/actionlib_msgs/cmake/../msg")

# Find all generators
find_package(gencpp REQUIRED)
find_package(geneus REQUIRED)
find_package(genlisp REQUIRED)
find_package(gennodejs REQUIRED)
find_package(genpy REQUIRED)

add_custom_target(coverage_path_planner_generate_messages ALL)

# verify that message/service dependencies have not changed since configure



get_filename_component(_filename "/home/casey/ASDR/Backend/ROS/src/coverage_path_planner/srv/make_plan.srv" NAME_WE)
add_custom_target(_coverage_path_planner_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "coverage_path_planner" "/home/casey/ASDR/Backend/ROS/src/coverage_path_planner/srv/make_plan.srv" "geometry_msgs/Point:geometry_msgs/Quaternion:geometry_msgs/Pose"
)

#
#  langs = gencpp;geneus;genlisp;gennodejs;genpy
#

### Section generating for lang: gencpp
### Generating Messages

### Generating Services
_generate_srv_cpp(coverage_path_planner
  "/home/casey/ASDR/Backend/ROS/src/coverage_path_planner/srv/make_plan.srv"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Pose.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/coverage_path_planner
)

### Generating Module File
_generate_module_cpp(coverage_path_planner
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/coverage_path_planner
  "${ALL_GEN_OUTPUT_FILES_cpp}"
)

add_custom_target(coverage_path_planner_generate_messages_cpp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_cpp}
)
add_dependencies(coverage_path_planner_generate_messages coverage_path_planner_generate_messages_cpp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/casey/ASDR/Backend/ROS/src/coverage_path_planner/srv/make_plan.srv" NAME_WE)
add_dependencies(coverage_path_planner_generate_messages_cpp _coverage_path_planner_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(coverage_path_planner_gencpp)
add_dependencies(coverage_path_planner_gencpp coverage_path_planner_generate_messages_cpp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS coverage_path_planner_generate_messages_cpp)

### Section generating for lang: geneus
### Generating Messages

### Generating Services
_generate_srv_eus(coverage_path_planner
  "/home/casey/ASDR/Backend/ROS/src/coverage_path_planner/srv/make_plan.srv"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Pose.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/coverage_path_planner
)

### Generating Module File
_generate_module_eus(coverage_path_planner
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/coverage_path_planner
  "${ALL_GEN_OUTPUT_FILES_eus}"
)

add_custom_target(coverage_path_planner_generate_messages_eus
  DEPENDS ${ALL_GEN_OUTPUT_FILES_eus}
)
add_dependencies(coverage_path_planner_generate_messages coverage_path_planner_generate_messages_eus)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/casey/ASDR/Backend/ROS/src/coverage_path_planner/srv/make_plan.srv" NAME_WE)
add_dependencies(coverage_path_planner_generate_messages_eus _coverage_path_planner_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(coverage_path_planner_geneus)
add_dependencies(coverage_path_planner_geneus coverage_path_planner_generate_messages_eus)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS coverage_path_planner_generate_messages_eus)

### Section generating for lang: genlisp
### Generating Messages

### Generating Services
_generate_srv_lisp(coverage_path_planner
  "/home/casey/ASDR/Backend/ROS/src/coverage_path_planner/srv/make_plan.srv"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Pose.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/coverage_path_planner
)

### Generating Module File
_generate_module_lisp(coverage_path_planner
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/coverage_path_planner
  "${ALL_GEN_OUTPUT_FILES_lisp}"
)

add_custom_target(coverage_path_planner_generate_messages_lisp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_lisp}
)
add_dependencies(coverage_path_planner_generate_messages coverage_path_planner_generate_messages_lisp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/casey/ASDR/Backend/ROS/src/coverage_path_planner/srv/make_plan.srv" NAME_WE)
add_dependencies(coverage_path_planner_generate_messages_lisp _coverage_path_planner_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(coverage_path_planner_genlisp)
add_dependencies(coverage_path_planner_genlisp coverage_path_planner_generate_messages_lisp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS coverage_path_planner_generate_messages_lisp)

### Section generating for lang: gennodejs
### Generating Messages

### Generating Services
_generate_srv_nodejs(coverage_path_planner
  "/home/casey/ASDR/Backend/ROS/src/coverage_path_planner/srv/make_plan.srv"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Pose.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/coverage_path_planner
)

### Generating Module File
_generate_module_nodejs(coverage_path_planner
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/coverage_path_planner
  "${ALL_GEN_OUTPUT_FILES_nodejs}"
)

add_custom_target(coverage_path_planner_generate_messages_nodejs
  DEPENDS ${ALL_GEN_OUTPUT_FILES_nodejs}
)
add_dependencies(coverage_path_planner_generate_messages coverage_path_planner_generate_messages_nodejs)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/casey/ASDR/Backend/ROS/src/coverage_path_planner/srv/make_plan.srv" NAME_WE)
add_dependencies(coverage_path_planner_generate_messages_nodejs _coverage_path_planner_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(coverage_path_planner_gennodejs)
add_dependencies(coverage_path_planner_gennodejs coverage_path_planner_generate_messages_nodejs)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS coverage_path_planner_generate_messages_nodejs)

### Section generating for lang: genpy
### Generating Messages

### Generating Services
_generate_srv_py(coverage_path_planner
  "/home/casey/ASDR/Backend/ROS/src/coverage_path_planner/srv/make_plan.srv"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Pose.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/coverage_path_planner
)

### Generating Module File
_generate_module_py(coverage_path_planner
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/coverage_path_planner
  "${ALL_GEN_OUTPUT_FILES_py}"
)

add_custom_target(coverage_path_planner_generate_messages_py
  DEPENDS ${ALL_GEN_OUTPUT_FILES_py}
)
add_dependencies(coverage_path_planner_generate_messages coverage_path_planner_generate_messages_py)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/casey/ASDR/Backend/ROS/src/coverage_path_planner/srv/make_plan.srv" NAME_WE)
add_dependencies(coverage_path_planner_generate_messages_py _coverage_path_planner_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(coverage_path_planner_genpy)
add_dependencies(coverage_path_planner_genpy coverage_path_planner_generate_messages_py)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS coverage_path_planner_generate_messages_py)



if(gencpp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/coverage_path_planner)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/coverage_path_planner
    DESTINATION ${gencpp_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_cpp)
  add_dependencies(coverage_path_planner_generate_messages_cpp std_msgs_generate_messages_cpp)
endif()
if(TARGET nav_msgs_generate_messages_cpp)
  add_dependencies(coverage_path_planner_generate_messages_cpp nav_msgs_generate_messages_cpp)
endif()
if(TARGET geometry_msgs_generate_messages_cpp)
  add_dependencies(coverage_path_planner_generate_messages_cpp geometry_msgs_generate_messages_cpp)
endif()
if(TARGET sensor_msgs_generate_messages_cpp)
  add_dependencies(coverage_path_planner_generate_messages_cpp sensor_msgs_generate_messages_cpp)
endif()
if(TARGET visualization_msgs_generate_messages_cpp)
  add_dependencies(coverage_path_planner_generate_messages_cpp visualization_msgs_generate_messages_cpp)
endif()

if(geneus_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/coverage_path_planner)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/coverage_path_planner
    DESTINATION ${geneus_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_eus)
  add_dependencies(coverage_path_planner_generate_messages_eus std_msgs_generate_messages_eus)
endif()
if(TARGET nav_msgs_generate_messages_eus)
  add_dependencies(coverage_path_planner_generate_messages_eus nav_msgs_generate_messages_eus)
endif()
if(TARGET geometry_msgs_generate_messages_eus)
  add_dependencies(coverage_path_planner_generate_messages_eus geometry_msgs_generate_messages_eus)
endif()
if(TARGET sensor_msgs_generate_messages_eus)
  add_dependencies(coverage_path_planner_generate_messages_eus sensor_msgs_generate_messages_eus)
endif()
if(TARGET visualization_msgs_generate_messages_eus)
  add_dependencies(coverage_path_planner_generate_messages_eus visualization_msgs_generate_messages_eus)
endif()

if(genlisp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/coverage_path_planner)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/coverage_path_planner
    DESTINATION ${genlisp_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_lisp)
  add_dependencies(coverage_path_planner_generate_messages_lisp std_msgs_generate_messages_lisp)
endif()
if(TARGET nav_msgs_generate_messages_lisp)
  add_dependencies(coverage_path_planner_generate_messages_lisp nav_msgs_generate_messages_lisp)
endif()
if(TARGET geometry_msgs_generate_messages_lisp)
  add_dependencies(coverage_path_planner_generate_messages_lisp geometry_msgs_generate_messages_lisp)
endif()
if(TARGET sensor_msgs_generate_messages_lisp)
  add_dependencies(coverage_path_planner_generate_messages_lisp sensor_msgs_generate_messages_lisp)
endif()
if(TARGET visualization_msgs_generate_messages_lisp)
  add_dependencies(coverage_path_planner_generate_messages_lisp visualization_msgs_generate_messages_lisp)
endif()

if(gennodejs_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/coverage_path_planner)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/coverage_path_planner
    DESTINATION ${gennodejs_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_nodejs)
  add_dependencies(coverage_path_planner_generate_messages_nodejs std_msgs_generate_messages_nodejs)
endif()
if(TARGET nav_msgs_generate_messages_nodejs)
  add_dependencies(coverage_path_planner_generate_messages_nodejs nav_msgs_generate_messages_nodejs)
endif()
if(TARGET geometry_msgs_generate_messages_nodejs)
  add_dependencies(coverage_path_planner_generate_messages_nodejs geometry_msgs_generate_messages_nodejs)
endif()
if(TARGET sensor_msgs_generate_messages_nodejs)
  add_dependencies(coverage_path_planner_generate_messages_nodejs sensor_msgs_generate_messages_nodejs)
endif()
if(TARGET visualization_msgs_generate_messages_nodejs)
  add_dependencies(coverage_path_planner_generate_messages_nodejs visualization_msgs_generate_messages_nodejs)
endif()

if(genpy_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/coverage_path_planner)
  install(CODE "execute_process(COMMAND \"/usr/bin/python3\" -m compileall \"${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/coverage_path_planner\")")
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/coverage_path_planner
    DESTINATION ${genpy_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_py)
  add_dependencies(coverage_path_planner_generate_messages_py std_msgs_generate_messages_py)
endif()
if(TARGET nav_msgs_generate_messages_py)
  add_dependencies(coverage_path_planner_generate_messages_py nav_msgs_generate_messages_py)
endif()
if(TARGET geometry_msgs_generate_messages_py)
  add_dependencies(coverage_path_planner_generate_messages_py geometry_msgs_generate_messages_py)
endif()
if(TARGET sensor_msgs_generate_messages_py)
  add_dependencies(coverage_path_planner_generate_messages_py sensor_msgs_generate_messages_py)
endif()
if(TARGET visualization_msgs_generate_messages_py)
  add_dependencies(coverage_path_planner_generate_messages_py visualization_msgs_generate_messages_py)
endif()
