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
include std_numeric_limits/CMakeFiles/numeric_limits_test.dir/depend.make

# Include the progress variables for this target.
include std_numeric_limits/CMakeFiles/numeric_limits_test.dir/progress.make

# Include the compile flags for this target's objects.
include std_numeric_limits/CMakeFiles/numeric_limits_test.dir/flags.make

std_numeric_limits/CMakeFiles/numeric_limits_test.dir/numeric_limits_test.cpp.o: std_numeric_limits/CMakeFiles/numeric_limits_test.dir/flags.make
std_numeric_limits/CMakeFiles/numeric_limits_test.dir/numeric_limits_test.cpp.o: ../std_numeric_limits/numeric_limits_test.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ljs/study/c++_practice/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object std_numeric_limits/CMakeFiles/numeric_limits_test.dir/numeric_limits_test.cpp.o"
	cd /home/ljs/study/c++_practice/build/std_numeric_limits && /usr/bin/g++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/numeric_limits_test.dir/numeric_limits_test.cpp.o -c /home/ljs/study/c++_practice/std_numeric_limits/numeric_limits_test.cpp

std_numeric_limits/CMakeFiles/numeric_limits_test.dir/numeric_limits_test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/numeric_limits_test.dir/numeric_limits_test.cpp.i"
	cd /home/ljs/study/c++_practice/build/std_numeric_limits && /usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ljs/study/c++_practice/std_numeric_limits/numeric_limits_test.cpp > CMakeFiles/numeric_limits_test.dir/numeric_limits_test.cpp.i

std_numeric_limits/CMakeFiles/numeric_limits_test.dir/numeric_limits_test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/numeric_limits_test.dir/numeric_limits_test.cpp.s"
	cd /home/ljs/study/c++_practice/build/std_numeric_limits && /usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ljs/study/c++_practice/std_numeric_limits/numeric_limits_test.cpp -o CMakeFiles/numeric_limits_test.dir/numeric_limits_test.cpp.s

std_numeric_limits/CMakeFiles/numeric_limits_test.dir/numeric_limits_test.cpp.o.requires:

.PHONY : std_numeric_limits/CMakeFiles/numeric_limits_test.dir/numeric_limits_test.cpp.o.requires

std_numeric_limits/CMakeFiles/numeric_limits_test.dir/numeric_limits_test.cpp.o.provides: std_numeric_limits/CMakeFiles/numeric_limits_test.dir/numeric_limits_test.cpp.o.requires
	$(MAKE) -f std_numeric_limits/CMakeFiles/numeric_limits_test.dir/build.make std_numeric_limits/CMakeFiles/numeric_limits_test.dir/numeric_limits_test.cpp.o.provides.build
.PHONY : std_numeric_limits/CMakeFiles/numeric_limits_test.dir/numeric_limits_test.cpp.o.provides

std_numeric_limits/CMakeFiles/numeric_limits_test.dir/numeric_limits_test.cpp.o.provides.build: std_numeric_limits/CMakeFiles/numeric_limits_test.dir/numeric_limits_test.cpp.o


# Object files for target numeric_limits_test
numeric_limits_test_OBJECTS = \
"CMakeFiles/numeric_limits_test.dir/numeric_limits_test.cpp.o"

# External object files for target numeric_limits_test
numeric_limits_test_EXTERNAL_OBJECTS =

std_numeric_limits/numeric_limits_test: std_numeric_limits/CMakeFiles/numeric_limits_test.dir/numeric_limits_test.cpp.o
std_numeric_limits/numeric_limits_test: std_numeric_limits/CMakeFiles/numeric_limits_test.dir/build.make
std_numeric_limits/numeric_limits_test: std_numeric_limits/CMakeFiles/numeric_limits_test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ljs/study/c++_practice/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable numeric_limits_test"
	cd /home/ljs/study/c++_practice/build/std_numeric_limits && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/numeric_limits_test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
std_numeric_limits/CMakeFiles/numeric_limits_test.dir/build: std_numeric_limits/numeric_limits_test

.PHONY : std_numeric_limits/CMakeFiles/numeric_limits_test.dir/build

std_numeric_limits/CMakeFiles/numeric_limits_test.dir/requires: std_numeric_limits/CMakeFiles/numeric_limits_test.dir/numeric_limits_test.cpp.o.requires

.PHONY : std_numeric_limits/CMakeFiles/numeric_limits_test.dir/requires

std_numeric_limits/CMakeFiles/numeric_limits_test.dir/clean:
	cd /home/ljs/study/c++_practice/build/std_numeric_limits && $(CMAKE_COMMAND) -P CMakeFiles/numeric_limits_test.dir/cmake_clean.cmake
.PHONY : std_numeric_limits/CMakeFiles/numeric_limits_test.dir/clean

std_numeric_limits/CMakeFiles/numeric_limits_test.dir/depend:
	cd /home/ljs/study/c++_practice/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ljs/study/c++_practice /home/ljs/study/c++_practice/std_numeric_limits /home/ljs/study/c++_practice/build /home/ljs/study/c++_practice/build/std_numeric_limits /home/ljs/study/c++_practice/build/std_numeric_limits/CMakeFiles/numeric_limits_test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : std_numeric_limits/CMakeFiles/numeric_limits_test.dir/depend

