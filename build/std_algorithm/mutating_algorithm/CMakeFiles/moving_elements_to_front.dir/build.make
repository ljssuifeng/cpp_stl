# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

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
CMAKE_SOURCE_DIR = /home/ljs/study/c++_practice

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ljs/study/c++_practice/build

# Include any dependencies generated for this target.
include std_algorithm/mutating_algorithm/CMakeFiles/moving_elements_to_front.dir/depend.make

# Include the progress variables for this target.
include std_algorithm/mutating_algorithm/CMakeFiles/moving_elements_to_front.dir/progress.make

# Include the compile flags for this target's objects.
include std_algorithm/mutating_algorithm/CMakeFiles/moving_elements_to_front.dir/flags.make

std_algorithm/mutating_algorithm/CMakeFiles/moving_elements_to_front.dir/moving_elements_to_front.cc.o: std_algorithm/mutating_algorithm/CMakeFiles/moving_elements_to_front.dir/flags.make
std_algorithm/mutating_algorithm/CMakeFiles/moving_elements_to_front.dir/moving_elements_to_front.cc.o: ../std_algorithm/mutating_algorithm/moving_elements_to_front.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ljs/study/c++_practice/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object std_algorithm/mutating_algorithm/CMakeFiles/moving_elements_to_front.dir/moving_elements_to_front.cc.o"
	cd /home/ljs/study/c++_practice/build/std_algorithm/mutating_algorithm && /usr/bin/g++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/moving_elements_to_front.dir/moving_elements_to_front.cc.o -c /home/ljs/study/c++_practice/std_algorithm/mutating_algorithm/moving_elements_to_front.cc

std_algorithm/mutating_algorithm/CMakeFiles/moving_elements_to_front.dir/moving_elements_to_front.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/moving_elements_to_front.dir/moving_elements_to_front.cc.i"
	cd /home/ljs/study/c++_practice/build/std_algorithm/mutating_algorithm && /usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ljs/study/c++_practice/std_algorithm/mutating_algorithm/moving_elements_to_front.cc > CMakeFiles/moving_elements_to_front.dir/moving_elements_to_front.cc.i

std_algorithm/mutating_algorithm/CMakeFiles/moving_elements_to_front.dir/moving_elements_to_front.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/moving_elements_to_front.dir/moving_elements_to_front.cc.s"
	cd /home/ljs/study/c++_practice/build/std_algorithm/mutating_algorithm && /usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ljs/study/c++_practice/std_algorithm/mutating_algorithm/moving_elements_to_front.cc -o CMakeFiles/moving_elements_to_front.dir/moving_elements_to_front.cc.s

std_algorithm/mutating_algorithm/CMakeFiles/moving_elements_to_front.dir/moving_elements_to_front.cc.o.requires:

.PHONY : std_algorithm/mutating_algorithm/CMakeFiles/moving_elements_to_front.dir/moving_elements_to_front.cc.o.requires

std_algorithm/mutating_algorithm/CMakeFiles/moving_elements_to_front.dir/moving_elements_to_front.cc.o.provides: std_algorithm/mutating_algorithm/CMakeFiles/moving_elements_to_front.dir/moving_elements_to_front.cc.o.requires
	$(MAKE) -f std_algorithm/mutating_algorithm/CMakeFiles/moving_elements_to_front.dir/build.make std_algorithm/mutating_algorithm/CMakeFiles/moving_elements_to_front.dir/moving_elements_to_front.cc.o.provides.build
.PHONY : std_algorithm/mutating_algorithm/CMakeFiles/moving_elements_to_front.dir/moving_elements_to_front.cc.o.provides

std_algorithm/mutating_algorithm/CMakeFiles/moving_elements_to_front.dir/moving_elements_to_front.cc.o.provides.build: std_algorithm/mutating_algorithm/CMakeFiles/moving_elements_to_front.dir/moving_elements_to_front.cc.o


# Object files for target moving_elements_to_front
moving_elements_to_front_OBJECTS = \
"CMakeFiles/moving_elements_to_front.dir/moving_elements_to_front.cc.o"

# External object files for target moving_elements_to_front
moving_elements_to_front_EXTERNAL_OBJECTS =

std_algorithm/mutating_algorithm/moving_elements_to_front: std_algorithm/mutating_algorithm/CMakeFiles/moving_elements_to_front.dir/moving_elements_to_front.cc.o
std_algorithm/mutating_algorithm/moving_elements_to_front: std_algorithm/mutating_algorithm/CMakeFiles/moving_elements_to_front.dir/build.make
std_algorithm/mutating_algorithm/moving_elements_to_front: std_algorithm/mutating_algorithm/CMakeFiles/moving_elements_to_front.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ljs/study/c++_practice/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable moving_elements_to_front"
	cd /home/ljs/study/c++_practice/build/std_algorithm/mutating_algorithm && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/moving_elements_to_front.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
std_algorithm/mutating_algorithm/CMakeFiles/moving_elements_to_front.dir/build: std_algorithm/mutating_algorithm/moving_elements_to_front

.PHONY : std_algorithm/mutating_algorithm/CMakeFiles/moving_elements_to_front.dir/build

std_algorithm/mutating_algorithm/CMakeFiles/moving_elements_to_front.dir/requires: std_algorithm/mutating_algorithm/CMakeFiles/moving_elements_to_front.dir/moving_elements_to_front.cc.o.requires

.PHONY : std_algorithm/mutating_algorithm/CMakeFiles/moving_elements_to_front.dir/requires

std_algorithm/mutating_algorithm/CMakeFiles/moving_elements_to_front.dir/clean:
	cd /home/ljs/study/c++_practice/build/std_algorithm/mutating_algorithm && $(CMAKE_COMMAND) -P CMakeFiles/moving_elements_to_front.dir/cmake_clean.cmake
.PHONY : std_algorithm/mutating_algorithm/CMakeFiles/moving_elements_to_front.dir/clean

std_algorithm/mutating_algorithm/CMakeFiles/moving_elements_to_front.dir/depend:
	cd /home/ljs/study/c++_practice/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ljs/study/c++_practice /home/ljs/study/c++_practice/std_algorithm/mutating_algorithm /home/ljs/study/c++_practice/build /home/ljs/study/c++_practice/build/std_algorithm/mutating_algorithm /home/ljs/study/c++_practice/build/std_algorithm/mutating_algorithm/CMakeFiles/moving_elements_to_front.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : std_algorithm/mutating_algorithm/CMakeFiles/moving_elements_to_front.dir/depend

