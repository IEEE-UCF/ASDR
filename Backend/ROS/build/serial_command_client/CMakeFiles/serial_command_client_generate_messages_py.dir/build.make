# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/casey/ASDR/Backend/ROS/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/casey/ASDR/Backend/ROS/build

# Utility rule file for serial_command_client_generate_messages_py.

# Include the progress variables for this target.
include serial_command_client/CMakeFiles/serial_command_client_generate_messages_py.dir/progress.make

serial_command_client/CMakeFiles/serial_command_client_generate_messages_py: /home/casey/ASDR/Backend/ROS/devel/lib/python3/dist-packages/serial_command_client/srv/_send_command.py
serial_command_client/CMakeFiles/serial_command_client_generate_messages_py: /home/casey/ASDR/Backend/ROS/devel/lib/python3/dist-packages/serial_command_client/srv/__init__.py


/home/casey/ASDR/Backend/ROS/devel/lib/python3/dist-packages/serial_command_client/srv/_send_command.py: /opt/ros/noetic/lib/genpy/gensrv_py.py
/home/casey/ASDR/Backend/ROS/devel/lib/python3/dist-packages/serial_command_client/srv/_send_command.py: /home/casey/ASDR/Backend/ROS/src/serial_command_client/srv/send_command.srv
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/casey/ASDR/Backend/ROS/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Generating Python code from SRV serial_command_client/send_command"
	cd /home/casey/ASDR/Backend/ROS/build/serial_command_client && ../catkin_generated/env_cached.sh /usr/bin/python3 /opt/ros/noetic/share/genpy/cmake/../../../lib/genpy/gensrv_py.py /home/casey/ASDR/Backend/ROS/src/serial_command_client/srv/send_command.srv -Istd_msgs:/opt/ros/noetic/share/std_msgs/cmake/../msg -p serial_command_client -o /home/casey/ASDR/Backend/ROS/devel/lib/python3/dist-packages/serial_command_client/srv

/home/casey/ASDR/Backend/ROS/devel/lib/python3/dist-packages/serial_command_client/srv/__init__.py: /opt/ros/noetic/lib/genpy/genmsg_py.py
/home/casey/ASDR/Backend/ROS/devel/lib/python3/dist-packages/serial_command_client/srv/__init__.py: /home/casey/ASDR/Backend/ROS/devel/lib/python3/dist-packages/serial_command_client/srv/_send_command.py
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/casey/ASDR/Backend/ROS/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Generating Python srv __init__.py for serial_command_client"
	cd /home/casey/ASDR/Backend/ROS/build/serial_command_client && ../catkin_generated/env_cached.sh /usr/bin/python3 /opt/ros/noetic/share/genpy/cmake/../../../lib/genpy/genmsg_py.py -o /home/casey/ASDR/Backend/ROS/devel/lib/python3/dist-packages/serial_command_client/srv --initpy

serial_command_client_generate_messages_py: serial_command_client/CMakeFiles/serial_command_client_generate_messages_py
serial_command_client_generate_messages_py: /home/casey/ASDR/Backend/ROS/devel/lib/python3/dist-packages/serial_command_client/srv/_send_command.py
serial_command_client_generate_messages_py: /home/casey/ASDR/Backend/ROS/devel/lib/python3/dist-packages/serial_command_client/srv/__init__.py
serial_command_client_generate_messages_py: serial_command_client/CMakeFiles/serial_command_client_generate_messages_py.dir/build.make

.PHONY : serial_command_client_generate_messages_py

# Rule to build all files generated by this target.
serial_command_client/CMakeFiles/serial_command_client_generate_messages_py.dir/build: serial_command_client_generate_messages_py

.PHONY : serial_command_client/CMakeFiles/serial_command_client_generate_messages_py.dir/build

serial_command_client/CMakeFiles/serial_command_client_generate_messages_py.dir/clean:
	cd /home/casey/ASDR/Backend/ROS/build/serial_command_client && $(CMAKE_COMMAND) -P CMakeFiles/serial_command_client_generate_messages_py.dir/cmake_clean.cmake
.PHONY : serial_command_client/CMakeFiles/serial_command_client_generate_messages_py.dir/clean

serial_command_client/CMakeFiles/serial_command_client_generate_messages_py.dir/depend:
	cd /home/casey/ASDR/Backend/ROS/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/casey/ASDR/Backend/ROS/src /home/casey/ASDR/Backend/ROS/src/serial_command_client /home/casey/ASDR/Backend/ROS/build /home/casey/ASDR/Backend/ROS/build/serial_command_client /home/casey/ASDR/Backend/ROS/build/serial_command_client/CMakeFiles/serial_command_client_generate_messages_py.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : serial_command_client/CMakeFiles/serial_command_client_generate_messages_py.dir/depend

