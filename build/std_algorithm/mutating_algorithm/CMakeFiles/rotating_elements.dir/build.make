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
include std_algorithm/mutating_algorithm/CMakeFiles/rotating_elements.dir/depend.make

# Include the progress variables for this target.
include std_algorithm/mutating_algorithm/CMakeFiles/rotating_elements.dir/progress.make

# Include the compile flags for this target's objects.
include std_algorithm/mutating_algorithm/CMakeFiles/rotating_elements.dir/flags.make

std_algorithm/mutating_algorithm/CMakeFiles/rotating_elements.dir/rotating_elements.cc.o: std_algorithm/mutating_algorithm/CMakeFiles/rotating_elements.dir/flags.make
std_algorithm/mutating_algorithm/CMakeFiles/rotating_elements.dir/rotating_elements.cc.o: ../std_algorithm/mutating_algorithm/rotating_elements.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ljs/study/c++_practice/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object std_algorithm/mutating_algorithm/CMakeFiles/rotating_elements.dir/rotating_elements.cc.o"
	cd /home/ljs/study/c++_practice/build/std_algorithm/mutating_algorithm && /usr/bin/g++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/rotating_elements.dir/rotating_elements.cc.o -c /home/ljs/study/c++_practice/std_algorithm/mutating_algorithm/rotating_elements.cc

std_algorithm/mutating_algorithm/CMakeFiles/rotating_elements.dir/rotating_elements.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/rotating_elements.dir/rotating_elements.cc.i"
	cd /home/ljs/study/c++_practice/build/std_algorithm/mutating_algorithm && /usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ljs/study/c++_practice/std_algorithm/mutating_algorithm/rotating_elements.cc > CMakeFiles/rotating_elements.dir/rotating_elements.cc.i

std_algorithm/mutating_algorithm/CMakeFiles/rotating_elements.dir/rotating_elements.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/rotating_elements.dir/rotating_elements.cc.s"
	cd /home/ljs/study/c++_practice/build/std_algorithm/mutating_algorithm && /usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ljs/study/c++_practice/std_algorithm/mutating_algorithm/rotating_elements.cc -o CMakeFiles/rotating_elements.dir/rotating_elements.cc.s

std_algorithm/mutating_algorithm/CMakeFiles/rotating_elements.dir/rotating_elements.cc.o.requires:

.PHONY : std_algorithm/mutating_algorithm/CMakeFiles/rotating_elements.dir/rotating_elements.cc.o.requires

std_algorithm/mutating_algorithm/CMakeFiles/rotating_elements.dir/rotating_elements.cc.o.provides: std_algorithm/mutating_algorithm/CMakeFiles/rotating_elements.dir/rotating_elements.cc.o.requires
	$(MAKE) -f std_algorithm/mutating_algorithm/CMakeFiles/rotating_elements.dir/build.make std_algorithm/mutating_algorithm/CMakeFiles/rotating_elements.dir/rotating_elements.cc.o.provides.build
.PHONY : std_algorithm/mutating_algorithm/CMakeFiles/rotating_elements.dir/rotating_elements.cc.o.provides

std_algorithm/mutating_algorithm/CMakeFiles/rotating_elements.dir/rotating_elements.cc.o.provides.build: std_algorithm/mutating_algorithm/CMakeFiles/rotating_elements.dir/rotating_elements.cc.o


# Object files for target rotating_elements
rotating_elements_OBJECTS = \
"CMakeFiles/rotating_elements.dir/rotating_elements.cc.o"

# External object files for target rotating_elements
rotating_elements_EXTERNAL_OBJECTS =

std_algorithm/mutating_algorithm/rotating_elements: std_algorithm/mutating_algorithm/CMakeFiles/rotating_elements.dir/rotating_elements.cc.o
std_algorithm/mutating_algorithm/rotating_elements: std_algorithm/mutating_algorithm/CMakeFiles/rotating_elements.dir/build.make
std_algorithm/mutating_algorithm/rotating_elements: std_algorithm/mutating_algorithm/CMakeFiles/rotating_elements.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ljs/study/c++_practice/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable rotating_elements"
	cd /home/ljs/study/c++_practice/build/std_algorithm/mutating_algorithm && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/rotating_elements.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
std_algorithm/mutating_algorithm/CMakeFiles/rotating_elements.dir/build: std_algorithm/mutating_algorithm/rotating_elements

.PHONY : std_algorithm/mutating_algorithm/CMakeFiles/rotating_elements.dir/build

std_algorithm/mutating_algorithm/CMakeFiles/rotating_elements.dir/requires: std_algorithm/mutating_algorithm/CMakeFiles/rotating_elements.dir/rotating_elements.cc.o.requires

.PHONY : std_algorithm/mutating_algorithm/CMakeFiles/rotating_elements.dir/requires

std_algorithm/mutating_algorithm/CMakeFiles/rotating_elements.dir/clean:
	cd /home/ljs/study/c++_practice/build/std_algorithm/mutating_algorithm && $(CMAKE_COMMAND) -P CMakeFiles/rotating_elements.dir/cmake_clean.cmake
.PHONY : std_algorithm/mutating_algorithm/CMakeFiles/rotating_elements.dir/clean

std_algorithm/mutating_algorithm/CMakeFiles/rotating_elements.dir/depend:
	cd /home/ljs/study/c++_practice/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ljs/study/c++_practice /home/ljs/study/c++_practice/std_algorithm/mutating_algorithm /home/ljs/study/c++_practice/build /home/ljs/study/c++_practice/build/std_algorithm/mutating_algorithm /home/ljs/study/c++_practice/build/std_algorithm/mutating_algorithm/CMakeFiles/rotating_elements.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : std_algorithm/mutating_algorithm/CMakeFiles/rotating_elements.dir/depend

