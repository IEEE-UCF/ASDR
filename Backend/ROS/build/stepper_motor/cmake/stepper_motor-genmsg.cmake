# generated from genmsg/cmake/pkg-genmsg.cmake.em

message(STATUS "stepper_motor: 0 messages, 1 services")

set(MSG_I_FLAGS "-Istd_msgs:/opt/ros/noetic/share/std_msgs/cmake/../msg")

# Find all generators
find_package(gencpp REQUIRED)
find_package(geneus REQUIRED)
find_package(genlisp REQUIRED)
find_package(gennodejs REQUIRED)
find_package(genpy REQUIRED)

add_custom_target(stepper_motor_generate_messages ALL)

# verify that message/service dependencies have not changed since configure



get_filename_component(_filename "/home/casey/ASDR/Backend/ROS/src/stepper_motor/srv/set_stepper_motor.srv" NAME_WE)
add_custom_target(_stepper_motor_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "stepper_motor" "/home/casey/ASDR/Backend/ROS/src/stepper_motor/srv/set_stepper_motor.srv" ""
)

#
#  langs = gencpp;geneus;genlisp;gennodejs;genpy
#

### Section generating for lang: gencpp
### Generating Messages

### Generating Services
_generate_srv_cpp(stepper_motor
  "/home/casey/ASDR/Backend/ROS/src/stepper_motor/srv/set_stepper_motor.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/stepper_motor
)

### Generating Module File
_generate_module_cpp(stepper_motor
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/stepper_motor
  "${ALL_GEN_OUTPUT_FILES_cpp}"
)

add_custom_target(stepper_motor_generate_messages_cpp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_cpp}
)
add_dependencies(stepper_motor_generate_messages stepper_motor_generate_messages_cpp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/casey/ASDR/Backend/ROS/src/stepper_motor/srv/set_stepper_motor.srv" NAME_WE)
add_dependencies(stepper_motor_generate_messages_cpp _stepper_motor_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(stepper_motor_gencpp)
add_dependencies(stepper_motor_gencpp stepper_motor_generate_messages_cpp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS stepper_motor_generate_messages_cpp)

### Section generating for lang: geneus
### Generating Messages

### Generating Services
_generate_srv_eus(stepper_motor
  "/home/casey/ASDR/Backend/ROS/src/stepper_motor/srv/set_stepper_motor.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/stepper_motor
)

### Generating Module File
_generate_module_eus(stepper_motor
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/stepper_motor
  "${ALL_GEN_OUTPUT_FILES_eus}"
)

add_custom_target(stepper_motor_generate_messages_eus
  DEPENDS ${ALL_GEN_OUTPUT_FILES_eus}
)
add_dependencies(stepper_motor_generate_messages stepper_motor_generate_messages_eus)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/casey/ASDR/Backend/ROS/src/stepper_motor/srv/set_stepper_motor.srv" NAME_WE)
add_dependencies(stepper_motor_generate_messages_eus _stepper_motor_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(stepper_motor_geneus)
add_dependencies(stepper_motor_geneus stepper_motor_generate_messages_eus)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS stepper_motor_generate_messages_eus)

### Section generating for lang: genlisp
### Generating Messages

### Generating Services
_generate_srv_lisp(stepper_motor
  "/home/casey/ASDR/Backend/ROS/src/stepper_motor/srv/set_stepper_motor.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/stepper_motor
)

### Generating Module File
_generate_module_lisp(stepper_motor
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/stepper_motor
  "${ALL_GEN_OUTPUT_FILES_lisp}"
)

add_custom_target(stepper_motor_generate_messages_lisp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_lisp}
)
add_dependencies(stepper_motor_generate_messages stepper_motor_generate_messages_lisp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/casey/ASDR/Backend/ROS/src/stepper_motor/srv/set_stepper_motor.srv" NAME_WE)
add_dependencies(stepper_motor_generate_messages_lisp _stepper_motor_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(stepper_motor_genlisp)
add_dependencies(stepper_motor_genlisp stepper_motor_generate_messages_lisp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS stepper_motor_generate_messages_lisp)

### Section generating for lang: gennodejs
### Generating Messages

### Generating Services
_generate_srv_nodejs(stepper_motor
  "/home/casey/ASDR/Backend/ROS/src/stepper_motor/srv/set_stepper_motor.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/stepper_motor
)

### Generating Module File
_generate_module_nodejs(stepper_motor
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/stepper_motor
  "${ALL_GEN_OUTPUT_FILES_nodejs}"
)

add_custom_target(stepper_motor_generate_messages_nodejs
  DEPENDS ${ALL_GEN_OUTPUT_FILES_nodejs}
)
add_dependencies(stepper_motor_generate_messages stepper_motor_generate_messages_nodejs)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/casey/ASDR/Backend/ROS/src/stepper_motor/srv/set_stepper_motor.srv" NAME_WE)
add_dependencies(stepper_motor_generate_messages_nodejs _stepper_motor_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(stepper_motor_gennodejs)
add_dependencies(stepper_motor_gennodejs stepper_motor_generate_messages_nodejs)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS stepper_motor_generate_messages_nodejs)

### Section generating for lang: genpy
### Generating Messages

### Generating Services
_generate_srv_py(stepper_motor
  "/home/casey/ASDR/Backend/ROS/src/stepper_motor/srv/set_stepper_motor.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/stepper_motor
)

### Generating Module File
_generate_module_py(stepper_motor
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/stepper_motor
  "${ALL_GEN_OUTPUT_FILES_py}"
)

add_custom_target(stepper_motor_generate_messages_py
  DEPENDS ${ALL_GEN_OUTPUT_FILES_py}
)
add_dependencies(stepper_motor_generate_messages stepper_motor_generate_messages_py)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/casey/ASDR/Backend/ROS/src/stepper_motor/srv/set_stepper_motor.srv" NAME_WE)
add_dependencies(stepper_motor_generate_messages_py _stepper_motor_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(stepper_motor_genpy)
add_dependencies(stepper_motor_genpy stepper_motor_generate_messages_py)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS stepper_motor_generate_messages_py)



if(gencpp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/stepper_motor)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/stepper_motor
    DESTINATION ${gencpp_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_cpp)
  add_dependencies(stepper_motor_generate_messages_cpp std_msgs_generate_messages_cpp)
endif()

if(geneus_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/stepper_motor)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/stepper_motor
    DESTINATION ${geneus_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_eus)
  add_dependencies(stepper_motor_generate_messages_eus std_msgs_generate_messages_eus)
endif()

if(genlisp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/stepper_motor)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/stepper_motor
    DESTINATION ${genlisp_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_lisp)
  add_dependencies(stepper_motor_generate_messages_lisp std_msgs_generate_messages_lisp)
endif()

if(gennodejs_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/stepper_motor)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/stepper_motor
    DESTINATION ${gennodejs_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_nodejs)
  add_dependencies(stepper_motor_generate_messages_nodejs std_msgs_generate_messages_nodejs)
endif()

if(genpy_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/stepper_motor)
  install(CODE "execute_process(COMMAND \"/usr/bin/python3\" -m compileall \"${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/stepper_motor\")")
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/stepper_motor
    DESTINATION ${genpy_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_py)
  add_dependencies(stepper_motor_generate_messages_py std_msgs_generate_messages_py)
endif()
