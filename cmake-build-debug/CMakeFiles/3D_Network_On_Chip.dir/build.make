# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
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
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /mnt/c/Users/chund/OneDrive/Desktop/3D-Network-On-Chip

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/c/Users/chund/OneDrive/Desktop/3D-Network-On-Chip/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/3D_Network_On_Chip.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/3D_Network_On_Chip.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/3D_Network_On_Chip.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/3D_Network_On_Chip.dir/flags.make

CMakeFiles/3D_Network_On_Chip.dir/src/noc/test/main.cpp.o: CMakeFiles/3D_Network_On_Chip.dir/flags.make
CMakeFiles/3D_Network_On_Chip.dir/src/noc/test/main.cpp.o: ../src/noc/test/main.cpp
CMakeFiles/3D_Network_On_Chip.dir/src/noc/test/main.cpp.o: CMakeFiles/3D_Network_On_Chip.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/chund/OneDrive/Desktop/3D-Network-On-Chip/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/3D_Network_On_Chip.dir/src/noc/test/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/3D_Network_On_Chip.dir/src/noc/test/main.cpp.o -MF CMakeFiles/3D_Network_On_Chip.dir/src/noc/test/main.cpp.o.d -o CMakeFiles/3D_Network_On_Chip.dir/src/noc/test/main.cpp.o -c /mnt/c/Users/chund/OneDrive/Desktop/3D-Network-On-Chip/src/noc/test/main.cpp

CMakeFiles/3D_Network_On_Chip.dir/src/noc/test/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/3D_Network_On_Chip.dir/src/noc/test/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Users/chund/OneDrive/Desktop/3D-Network-On-Chip/src/noc/test/main.cpp > CMakeFiles/3D_Network_On_Chip.dir/src/noc/test/main.cpp.i

CMakeFiles/3D_Network_On_Chip.dir/src/noc/test/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/3D_Network_On_Chip.dir/src/noc/test/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Users/chund/OneDrive/Desktop/3D-Network-On-Chip/src/noc/test/main.cpp -o CMakeFiles/3D_Network_On_Chip.dir/src/noc/test/main.cpp.s

CMakeFiles/3D_Network_On_Chip.dir/src/noc/topology/TopologyConfig.cpp.o: CMakeFiles/3D_Network_On_Chip.dir/flags.make
CMakeFiles/3D_Network_On_Chip.dir/src/noc/topology/TopologyConfig.cpp.o: ../src/noc/topology/TopologyConfig.cpp
CMakeFiles/3D_Network_On_Chip.dir/src/noc/topology/TopologyConfig.cpp.o: CMakeFiles/3D_Network_On_Chip.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/chund/OneDrive/Desktop/3D-Network-On-Chip/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/3D_Network_On_Chip.dir/src/noc/topology/TopologyConfig.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/3D_Network_On_Chip.dir/src/noc/topology/TopologyConfig.cpp.o -MF CMakeFiles/3D_Network_On_Chip.dir/src/noc/topology/TopologyConfig.cpp.o.d -o CMakeFiles/3D_Network_On_Chip.dir/src/noc/topology/TopologyConfig.cpp.o -c /mnt/c/Users/chund/OneDrive/Desktop/3D-Network-On-Chip/src/noc/topology/TopologyConfig.cpp

CMakeFiles/3D_Network_On_Chip.dir/src/noc/topology/TopologyConfig.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/3D_Network_On_Chip.dir/src/noc/topology/TopologyConfig.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Users/chund/OneDrive/Desktop/3D-Network-On-Chip/src/noc/topology/TopologyConfig.cpp > CMakeFiles/3D_Network_On_Chip.dir/src/noc/topology/TopologyConfig.cpp.i

CMakeFiles/3D_Network_On_Chip.dir/src/noc/topology/TopologyConfig.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/3D_Network_On_Chip.dir/src/noc/topology/TopologyConfig.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Users/chund/OneDrive/Desktop/3D-Network-On-Chip/src/noc/topology/TopologyConfig.cpp -o CMakeFiles/3D_Network_On_Chip.dir/src/noc/topology/TopologyConfig.cpp.s

CMakeFiles/3D_Network_On_Chip.dir/src/noc/topology/Topology.cpp.o: CMakeFiles/3D_Network_On_Chip.dir/flags.make
CMakeFiles/3D_Network_On_Chip.dir/src/noc/topology/Topology.cpp.o: ../src/noc/topology/Topology.cpp
CMakeFiles/3D_Network_On_Chip.dir/src/noc/topology/Topology.cpp.o: CMakeFiles/3D_Network_On_Chip.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/chund/OneDrive/Desktop/3D-Network-On-Chip/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/3D_Network_On_Chip.dir/src/noc/topology/Topology.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/3D_Network_On_Chip.dir/src/noc/topology/Topology.cpp.o -MF CMakeFiles/3D_Network_On_Chip.dir/src/noc/topology/Topology.cpp.o.d -o CMakeFiles/3D_Network_On_Chip.dir/src/noc/topology/Topology.cpp.o -c /mnt/c/Users/chund/OneDrive/Desktop/3D-Network-On-Chip/src/noc/topology/Topology.cpp

CMakeFiles/3D_Network_On_Chip.dir/src/noc/topology/Topology.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/3D_Network_On_Chip.dir/src/noc/topology/Topology.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Users/chund/OneDrive/Desktop/3D-Network-On-Chip/src/noc/topology/Topology.cpp > CMakeFiles/3D_Network_On_Chip.dir/src/noc/topology/Topology.cpp.i

CMakeFiles/3D_Network_On_Chip.dir/src/noc/topology/Topology.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/3D_Network_On_Chip.dir/src/noc/topology/Topology.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Users/chund/OneDrive/Desktop/3D-Network-On-Chip/src/noc/topology/Topology.cpp -o CMakeFiles/3D_Network_On_Chip.dir/src/noc/topology/Topology.cpp.s

CMakeFiles/3D_Network_On_Chip.dir/src/noc/node/node.cpp.o: CMakeFiles/3D_Network_On_Chip.dir/flags.make
CMakeFiles/3D_Network_On_Chip.dir/src/noc/node/node.cpp.o: ../src/noc/node/node.cpp
CMakeFiles/3D_Network_On_Chip.dir/src/noc/node/node.cpp.o: CMakeFiles/3D_Network_On_Chip.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/chund/OneDrive/Desktop/3D-Network-On-Chip/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/3D_Network_On_Chip.dir/src/noc/node/node.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/3D_Network_On_Chip.dir/src/noc/node/node.cpp.o -MF CMakeFiles/3D_Network_On_Chip.dir/src/noc/node/node.cpp.o.d -o CMakeFiles/3D_Network_On_Chip.dir/src/noc/node/node.cpp.o -c /mnt/c/Users/chund/OneDrive/Desktop/3D-Network-On-Chip/src/noc/node/node.cpp

CMakeFiles/3D_Network_On_Chip.dir/src/noc/node/node.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/3D_Network_On_Chip.dir/src/noc/node/node.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Users/chund/OneDrive/Desktop/3D-Network-On-Chip/src/noc/node/node.cpp > CMakeFiles/3D_Network_On_Chip.dir/src/noc/node/node.cpp.i

CMakeFiles/3D_Network_On_Chip.dir/src/noc/node/node.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/3D_Network_On_Chip.dir/src/noc/node/node.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Users/chund/OneDrive/Desktop/3D-Network-On-Chip/src/noc/node/node.cpp -o CMakeFiles/3D_Network_On_Chip.dir/src/noc/node/node.cpp.s

# Object files for target 3D_Network_On_Chip
3D_Network_On_Chip_OBJECTS = \
"CMakeFiles/3D_Network_On_Chip.dir/src/noc/test/main.cpp.o" \
"CMakeFiles/3D_Network_On_Chip.dir/src/noc/topology/TopologyConfig.cpp.o" \
"CMakeFiles/3D_Network_On_Chip.dir/src/noc/topology/Topology.cpp.o" \
"CMakeFiles/3D_Network_On_Chip.dir/src/noc/node/node.cpp.o"

# External object files for target 3D_Network_On_Chip
3D_Network_On_Chip_EXTERNAL_OBJECTS =

3D_Network_On_Chip: CMakeFiles/3D_Network_On_Chip.dir/src/noc/test/main.cpp.o
3D_Network_On_Chip: CMakeFiles/3D_Network_On_Chip.dir/src/noc/topology/TopologyConfig.cpp.o
3D_Network_On_Chip: CMakeFiles/3D_Network_On_Chip.dir/src/noc/topology/Topology.cpp.o
3D_Network_On_Chip: CMakeFiles/3D_Network_On_Chip.dir/src/noc/node/node.cpp.o
3D_Network_On_Chip: CMakeFiles/3D_Network_On_Chip.dir/build.make
3D_Network_On_Chip: CMakeFiles/3D_Network_On_Chip.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/c/Users/chund/OneDrive/Desktop/3D-Network-On-Chip/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable 3D_Network_On_Chip"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/3D_Network_On_Chip.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/3D_Network_On_Chip.dir/build: 3D_Network_On_Chip
.PHONY : CMakeFiles/3D_Network_On_Chip.dir/build

CMakeFiles/3D_Network_On_Chip.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/3D_Network_On_Chip.dir/cmake_clean.cmake
.PHONY : CMakeFiles/3D_Network_On_Chip.dir/clean

CMakeFiles/3D_Network_On_Chip.dir/depend:
	cd /mnt/c/Users/chund/OneDrive/Desktop/3D-Network-On-Chip/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/c/Users/chund/OneDrive/Desktop/3D-Network-On-Chip /mnt/c/Users/chund/OneDrive/Desktop/3D-Network-On-Chip /mnt/c/Users/chund/OneDrive/Desktop/3D-Network-On-Chip/cmake-build-debug /mnt/c/Users/chund/OneDrive/Desktop/3D-Network-On-Chip/cmake-build-debug /mnt/c/Users/chund/OneDrive/Desktop/3D-Network-On-Chip/cmake-build-debug/CMakeFiles/3D_Network_On_Chip.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/3D_Network_On_Chip.dir/depend
