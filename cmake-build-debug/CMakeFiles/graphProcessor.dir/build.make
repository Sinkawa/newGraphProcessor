# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

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
CMAKE_COMMAND = /snap/clion/135/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/135/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/sinkawa/Development/Projects/CLion/newGraphProcessor

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/sinkawa/Development/Projects/CLion/newGraphProcessor/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/graphProcessor.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/graphProcessor.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/graphProcessor.dir/flags.make

CMakeFiles/graphProcessor.dir/gp/GraphHandler.cpp.o: CMakeFiles/graphProcessor.dir/flags.make
CMakeFiles/graphProcessor.dir/gp/GraphHandler.cpp.o: ../gp/GraphHandler.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sinkawa/Development/Projects/CLion/newGraphProcessor/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/graphProcessor.dir/gp/GraphHandler.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/graphProcessor.dir/gp/GraphHandler.cpp.o -c /home/sinkawa/Development/Projects/CLion/newGraphProcessor/gp/GraphHandler.cpp

CMakeFiles/graphProcessor.dir/gp/GraphHandler.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/graphProcessor.dir/gp/GraphHandler.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sinkawa/Development/Projects/CLion/newGraphProcessor/gp/GraphHandler.cpp > CMakeFiles/graphProcessor.dir/gp/GraphHandler.cpp.i

CMakeFiles/graphProcessor.dir/gp/GraphHandler.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/graphProcessor.dir/gp/GraphHandler.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sinkawa/Development/Projects/CLion/newGraphProcessor/gp/GraphHandler.cpp -o CMakeFiles/graphProcessor.dir/gp/GraphHandler.cpp.s

CMakeFiles/graphProcessor.dir/gp/Graph.cpp.o: CMakeFiles/graphProcessor.dir/flags.make
CMakeFiles/graphProcessor.dir/gp/Graph.cpp.o: ../gp/Graph.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sinkawa/Development/Projects/CLion/newGraphProcessor/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/graphProcessor.dir/gp/Graph.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/graphProcessor.dir/gp/Graph.cpp.o -c /home/sinkawa/Development/Projects/CLion/newGraphProcessor/gp/Graph.cpp

CMakeFiles/graphProcessor.dir/gp/Graph.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/graphProcessor.dir/gp/Graph.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sinkawa/Development/Projects/CLion/newGraphProcessor/gp/Graph.cpp > CMakeFiles/graphProcessor.dir/gp/Graph.cpp.i

CMakeFiles/graphProcessor.dir/gp/Graph.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/graphProcessor.dir/gp/Graph.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sinkawa/Development/Projects/CLion/newGraphProcessor/gp/Graph.cpp -o CMakeFiles/graphProcessor.dir/gp/Graph.cpp.s

CMakeFiles/graphProcessor.dir/gp/GraphNode.cpp.o: CMakeFiles/graphProcessor.dir/flags.make
CMakeFiles/graphProcessor.dir/gp/GraphNode.cpp.o: ../gp/GraphNode.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sinkawa/Development/Projects/CLion/newGraphProcessor/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/graphProcessor.dir/gp/GraphNode.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/graphProcessor.dir/gp/GraphNode.cpp.o -c /home/sinkawa/Development/Projects/CLion/newGraphProcessor/gp/GraphNode.cpp

CMakeFiles/graphProcessor.dir/gp/GraphNode.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/graphProcessor.dir/gp/GraphNode.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sinkawa/Development/Projects/CLion/newGraphProcessor/gp/GraphNode.cpp > CMakeFiles/graphProcessor.dir/gp/GraphNode.cpp.i

CMakeFiles/graphProcessor.dir/gp/GraphNode.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/graphProcessor.dir/gp/GraphNode.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sinkawa/Development/Projects/CLion/newGraphProcessor/gp/GraphNode.cpp -o CMakeFiles/graphProcessor.dir/gp/GraphNode.cpp.s

CMakeFiles/graphProcessor.dir/source.cpp.o: CMakeFiles/graphProcessor.dir/flags.make
CMakeFiles/graphProcessor.dir/source.cpp.o: ../source.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sinkawa/Development/Projects/CLion/newGraphProcessor/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/graphProcessor.dir/source.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/graphProcessor.dir/source.cpp.o -c /home/sinkawa/Development/Projects/CLion/newGraphProcessor/source.cpp

CMakeFiles/graphProcessor.dir/source.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/graphProcessor.dir/source.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sinkawa/Development/Projects/CLion/newGraphProcessor/source.cpp > CMakeFiles/graphProcessor.dir/source.cpp.i

CMakeFiles/graphProcessor.dir/source.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/graphProcessor.dir/source.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sinkawa/Development/Projects/CLion/newGraphProcessor/source.cpp -o CMakeFiles/graphProcessor.dir/source.cpp.s

CMakeFiles/graphProcessor.dir/gp/GraphLib.cpp.o: CMakeFiles/graphProcessor.dir/flags.make
CMakeFiles/graphProcessor.dir/gp/GraphLib.cpp.o: ../gp/GraphLib.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sinkawa/Development/Projects/CLion/newGraphProcessor/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/graphProcessor.dir/gp/GraphLib.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/graphProcessor.dir/gp/GraphLib.cpp.o -c /home/sinkawa/Development/Projects/CLion/newGraphProcessor/gp/GraphLib.cpp

CMakeFiles/graphProcessor.dir/gp/GraphLib.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/graphProcessor.dir/gp/GraphLib.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sinkawa/Development/Projects/CLion/newGraphProcessor/gp/GraphLib.cpp > CMakeFiles/graphProcessor.dir/gp/GraphLib.cpp.i

CMakeFiles/graphProcessor.dir/gp/GraphLib.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/graphProcessor.dir/gp/GraphLib.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sinkawa/Development/Projects/CLion/newGraphProcessor/gp/GraphLib.cpp -o CMakeFiles/graphProcessor.dir/gp/GraphLib.cpp.s

# Object files for target graphProcessor
graphProcessor_OBJECTS = \
"CMakeFiles/graphProcessor.dir/gp/GraphHandler.cpp.o" \
"CMakeFiles/graphProcessor.dir/gp/Graph.cpp.o" \
"CMakeFiles/graphProcessor.dir/gp/GraphNode.cpp.o" \
"CMakeFiles/graphProcessor.dir/source.cpp.o" \
"CMakeFiles/graphProcessor.dir/gp/GraphLib.cpp.o"

# External object files for target graphProcessor
graphProcessor_EXTERNAL_OBJECTS =

graphProcessor: CMakeFiles/graphProcessor.dir/gp/GraphHandler.cpp.o
graphProcessor: CMakeFiles/graphProcessor.dir/gp/Graph.cpp.o
graphProcessor: CMakeFiles/graphProcessor.dir/gp/GraphNode.cpp.o
graphProcessor: CMakeFiles/graphProcessor.dir/source.cpp.o
graphProcessor: CMakeFiles/graphProcessor.dir/gp/GraphLib.cpp.o
graphProcessor: CMakeFiles/graphProcessor.dir/build.make
graphProcessor: CMakeFiles/graphProcessor.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/sinkawa/Development/Projects/CLion/newGraphProcessor/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable graphProcessor"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/graphProcessor.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/graphProcessor.dir/build: graphProcessor

.PHONY : CMakeFiles/graphProcessor.dir/build

CMakeFiles/graphProcessor.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/graphProcessor.dir/cmake_clean.cmake
.PHONY : CMakeFiles/graphProcessor.dir/clean

CMakeFiles/graphProcessor.dir/depend:
	cd /home/sinkawa/Development/Projects/CLion/newGraphProcessor/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/sinkawa/Development/Projects/CLion/newGraphProcessor /home/sinkawa/Development/Projects/CLion/newGraphProcessor /home/sinkawa/Development/Projects/CLion/newGraphProcessor/cmake-build-debug /home/sinkawa/Development/Projects/CLion/newGraphProcessor/cmake-build-debug /home/sinkawa/Development/Projects/CLion/newGraphProcessor/cmake-build-debug/CMakeFiles/graphProcessor.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/graphProcessor.dir/depend
