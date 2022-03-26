# generated from genmsg/cmake/pkg-genmsg.cmake.em

message(STATUS "asdr: 0 messages, 3 services")

set(MSG_I_FLAGS "-Istd_msgs:/opt/ros/noetic/share/std_msgs/cmake/../msg")

# Find all generators
find_package(gencpp REQUIRED)
find_package(geneus REQUIRED)
find_package(genlisp REQUIRED)
find_package(gennodejs REQUIRED)
find_package(genpy REQUIRED)

add_custom_target(asdr_generate_messages ALL)

# verify that message/service dependencies have not changed since configure



get_filename_component(_filename "/home/casey/ASDR/Backend/ROS/src/asdr/srv/get_state.srv" NAME_WE)
add_custom_target(_asdr_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "asdr" "/home/casey/ASDR/Backend/ROS/src/asdr/srv/get_state.srv" ""
)

get_filename_component(_filename "/home/casey/ASDR/Backend/ROS/src/asdr/srv/set_state.srv" NAME_WE)
add_custom_target(_asdr_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "asdr" "/home/casey/ASDR/Backend/ROS/src/asdr/srv/set_state.srv" ""
)

get_filename_component(_filename "/home/casey/ASDR/Backend/ROS/src/asdr/srv/set_velocity.srv" NAME_WE)
add_custom_target(_asdr_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "asdr" "/home/casey/ASDR/Backend/ROS/src/asdr/srv/set_velocity.srv" ""
)

#
#  langs = gencpp;geneus;genlisp;gennodejs;genpy
#

### Section generating for lang: gencpp
### Generating Messages

### Generating Services
_generate_srv_cpp(asdr
  "/home/casey/ASDR/Backend/ROS/src/asdr/srv/get_state.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/asdr
)
_generate_srv_cpp(asdr
  "/home/casey/ASDR/Backend/ROS/src/asdr/srv/set_state.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/asdr
)
_generate_srv_cpp(asdr
  "/home/casey/ASDR/Backend/ROS/src/asdr/srv/set_velocity.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/asdr
)

### Generating Module File
_generate_module_cpp(asdr
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/asdr
  "${ALL_GEN_OUTPUT_FILES_cpp}"
)

add_custom_target(asdr_generate_messages_cpp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_cpp}
)
add_dependencies(asdr_generate_messages asdr_generate_messages_cpp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/casey/ASDR/Backend/ROS/src/asdr/srv/get_state.srv" NAME_WE)
add_dependencies(asdr_generate_messages_cpp _asdr_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/casey/ASDR/Backend/ROS/src/asdr/srv/set_state.srv" NAME_WE)
add_dependencies(asdr_generate_messages_cpp _asdr_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/casey/ASDR/Backend/ROS/src/asdr/srv/set_velocity.srv" NAME_WE)
add_dependencies(asdr_generate_messages_cpp _asdr_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(asdr_gencpp)
add_dependencies(asdr_gencpp asdr_generate_messages_cpp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS asdr_generate_messages_cpp)

### Section generating for lang: geneus
### Generating Messages

### Generating Services
_generate_srv_eus(asdr
  "/home/casey/ASDR/Backend/ROS/src/asdr/srv/get_state.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/asdr
)
_generate_srv_eus(asdr
  "/home/casey/ASDR/Backend/ROS/src/asdr/srv/set_state.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/asdr
)
_generate_srv_eus(asdr
  "/home/casey/ASDR/Backend/ROS/src/asdr/srv/set_velocity.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/asdr
)

### Generating Module File
_generate_module_eus(asdr
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/asdr
  "${ALL_GEN_OUTPUT_FILES_eus}"
)

add_custom_target(asdr_generate_messages_eus
  DEPENDS ${ALL_GEN_OUTPUT_FILES_eus}
)
add_dependencies(asdr_generate_messages asdr_generate_messages_eus)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/casey/ASDR/Backend/ROS/src/asdr/srv/get_state.srv" NAME_WE)
add_dependencies(asdr_generate_messages_eus _asdr_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/casey/ASDR/Backend/ROS/src/asdr/srv/set_state.srv" NAME_WE)
add_dependencies(asdr_generate_messages_eus _asdr_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/casey/ASDR/Backend/ROS/src/asdr/srv/set_velocity.srv" NAME_WE)
add_dependencies(asdr_generate_messages_eus _asdr_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(asdr_geneus)
add_dependencies(asdr_geneus asdr_generate_messages_eus)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS asdr_generate_messages_eus)

### Section generating for lang: genlisp
### Generating Messages

### Generating Services
_generate_srv_lisp(asdr
  "/home/casey/ASDR/Backend/ROS/src/asdr/srv/get_state.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/asdr
)
_generate_srv_lisp(asdr
  "/home/casey/ASDR/Backend/ROS/src/asdr/srv/set_state.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/asdr
)
_generate_srv_lisp(asdr
  "/home/casey/ASDR/Backend/ROS/src/asdr/srv/set_velocity.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/asdr
)

### Generating Module File
_generate_module_lisp(asdr
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/asdr
  "${ALL_GEN_OUTPUT_FILES_lisp}"
)

add_custom_target(asdr_generate_messages_lisp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_lisp}
)
add_dependencies(asdr_generate_messages asdr_generate_messages_lisp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/casey/ASDR/Backend/ROS/src/asdr/srv/get_state.srv" NAME_WE)
add_dependencies(asdr_generate_messages_lisp _asdr_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/casey/ASDR/Backend/ROS/src/asdr/srv/set_state.srv" NAME_WE)
add_dependencies(asdr_generate_messages_lisp _asdr_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/casey/ASDR/Backend/ROS/src/asdr/srv/set_velocity.srv" NAME_WE)
add_dependencies(asdr_generate_messages_lisp _asdr_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(asdr_genlisp)
add_dependencies(asdr_genlisp asdr_generate_messages_lisp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS asdr_generate_messages_lisp)

### Section generating for lang: gennodejs
### Generating Messages

### Generating Services
_generate_srv_nodejs(asdr
  "/home/casey/ASDR/Backend/ROS/src/asdr/srv/get_state.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/asdr
)
_generate_srv_nodejs(asdr
  "/home/casey/ASDR/Backend/ROS/src/asdr/srv/set_state.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/asdr
)
_generate_srv_nodejs(asdr
  "/home/casey/ASDR/Backend/ROS/src/asdr/srv/set_velocity.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/asdr
)

### Generating Module File
_generate_module_nodejs(asdr
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/asdr
  "${ALL_GEN_OUTPUT_FILES_nodejs}"
)

add_custom_target(asdr_generate_messages_nodejs
  DEPENDS ${ALL_GEN_OUTPUT_FILES_nodejs}
)
add_dependencies(asdr_generate_messages asdr_generate_messages_nodejs)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/casey/ASDR/Backend/ROS/src/asdr/srv/get_state.srv" NAME_WE)
add_dependencies(asdr_generate_messages_nodejs _asdr_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/casey/ASDR/Backend/ROS/src/asdr/srv/set_state.srv" NAME_WE)
add_dependencies(asdr_generate_messages_nodejs _asdr_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/casey/ASDR/Backend/ROS/src/asdr/srv/set_velocity.srv" NAME_WE)
add_dependencies(asdr_generate_messages_nodejs _asdr_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(asdr_gennodejs)
add_dependencies(asdr_gennodejs asdr_generate_messages_nodejs)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS asdr_generate_messages_nodejs)

### Section generating for lang: genpy
### Generating Messages

### Generating Services
_generate_srv_py(asdr
  "/home/casey/ASDR/Backend/ROS/src/asdr/srv/get_state.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/asdr
)
_generate_srv_py(asdr
  "/home/casey/ASDR/Backend/ROS/src/asdr/srv/set_state.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/asdr
)
_generate_srv_py(asdr
  "/home/casey/ASDR/Backend/ROS/src/asdr/srv/set_velocity.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/asdr
)

### Generating Module File
_generate_module_py(asdr
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/asdr
  "${ALL_GEN_OUTPUT_FILES_py}"
)

add_custom_target(asdr_generate_messages_py
  DEPENDS ${ALL_GEN_OUTPUT_FILES_py}
)
add_dependencies(asdr_generate_messages asdr_generate_messages_py)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/casey/ASDR/Backend/ROS/src/asdr/srv/get_state.srv" NAME_WE)
add_dependencies(asdr_generate_messages_py _asdr_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/casey/ASDR/Backend/ROS/src/asdr/srv/set_state.srv" NAME_WE)
add_dependencies(asdr_generate_messages_py _asdr_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/casey/ASDR/Backend/ROS/src/asdr/srv/set_velocity.srv" NAME_WE)
add_dependencies(asdr_generate_messages_py _asdr_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(asdr_genpy)
add_dependencies(asdr_genpy asdr_generate_messages_py)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS asdr_generate_messages_py)



if(gencpp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/asdr)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/asdr
    DESTINATION ${gencpp_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_cpp)
  add_dependencies(asdr_generate_messages_cpp std_msgs_generate_messages_cpp)
endif()

if(geneus_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/asdr)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/asdr
    DESTINATION ${geneus_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_eus)
  add_dependencies(asdr_generate_messages_eus std_msgs_generate_messages_eus)
endif()

if(genlisp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/asdr)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/asdr
    DESTINATION ${genlisp_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_lisp)
  add_dependencies(asdr_generate_messages_lisp std_msgs_generate_messages_lisp)
endif()

if(gennodejs_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/asdr)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/asdr
    DESTINATION ${gennodejs_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_nodejs)
  add_dependencies(asdr_generate_messages_nodejs std_msgs_generate_messages_nodejs)
endif()

if(genpy_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/asdr)
  install(CODE "execute_process(COMMAND \"/usr/bin/python3\" -m compileall \"${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/asdr\")")
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/asdr
    DESTINATION ${genpy_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_py)
  add_dependencies(asdr_generate_messages_py std_msgs_generate_messages_py)
endif()
