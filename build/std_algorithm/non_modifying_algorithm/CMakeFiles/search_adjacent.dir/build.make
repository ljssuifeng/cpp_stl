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
include std_algorithm/non_modifying_algorithm/CMakeFiles/search_adjacent.dir/depend.make

# Include the progress variables for this target.
include std_algorithm/non_modifying_algorithm/CMakeFiles/search_adjacent.dir/progress.make

# Include the compile flags for this target's objects.
include std_algorithm/non_modifying_algorithm/CMakeFiles/search_adjacent.dir/flags.make

std_algorithm/non_modifying_algorithm/CMakeFiles/search_adjacent.dir/search_adjacent.cc.o: std_algorithm/non_modifying_algorithm/CMakeFiles/search_adjacent.dir/flags.make
std_algorithm/non_modifying_algorithm/CMakeFiles/search_adjacent.dir/search_adjacent.cc.o: ../std_algorithm/non_modifying_algorithm/search_adjacent.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ljs/study/c++_practice/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object std_algorithm/non_modifying_algorithm/CMakeFiles/search_adjacent.dir/search_adjacent.cc.o"
	cd /home/ljs/study/c++_practice/build/std_algorithm/non_modifying_algorithm && /usr/bin/g++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/search_adjacent.dir/search_adjacent.cc.o -c /home/ljs/study/c++_practice/std_algorithm/non_modifying_algorithm/search_adjacent.cc

std_algorithm/non_modifying_algorithm/CMakeFiles/search_adjacent.dir/search_adjacent.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/search_adjacent.dir/search_adjacent.cc.i"
	cd /home/ljs/study/c++_practice/build/std_algorithm/non_modifying_algorithm && /usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ljs/study/c++_practice/std_algorithm/non_modifying_algorithm/search_adjacent.cc > CMakeFiles/search_adjacent.dir/search_adjacent.cc.i

std_algorithm/non_modifying_algorithm/CMakeFiles/search_adjacent.dir/search_adjacent.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/search_adjacent.dir/search_adjacent.cc.s"
	cd /home/ljs/study/c++_practice/build/std_algorithm/non_modifying_algorithm && /usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ljs/study/c++_practice/std_algorithm/non_modifying_algorithm/search_adjacent.cc -o CMakeFiles/search_adjacent.dir/search_adjacent.cc.s

std_algorithm/non_modifying_algorithm/CMakeFiles/search_adjacent.dir/search_adjacent.cc.o.requires:

.PHONY : std_algorithm/non_modifying_algorithm/CMakeFiles/search_adjacent.dir/search_adjacent.cc.o.requires

std_algorithm/non_modifying_algorithm/CMakeFiles/search_adjacent.dir/search_adjacent.cc.o.provides: std_algorithm/non_modifying_algorithm/CMakeFiles/search_adjacent.dir/search_adjacent.cc.o.requires
	$(MAKE) -f std_algorithm/non_modifying_algorithm/CMakeFiles/search_adjacent.dir/build.make std_algorithm/non_modifying_algorithm/CMakeFiles/search_adjacent.dir/search_adjacent.cc.o.provides.build
.PHONY : std_algorithm/non_modifying_algorithm/CMakeFiles/search_adjacent.dir/search_adjacent.cc.o.provides

std_algorithm/non_modifying_algorithm/CMakeFiles/search_adjacent.dir/search_adjacent.cc.o.provides.build: std_algorithm/non_modifying_algorithm/CMakeFiles/search_adjacent.dir/search_adjacent.cc.o


# Object files for target search_adjacent
search_adjacent_OBJECTS = \
"CMakeFiles/search_adjacent.dir/search_adjacent.cc.o"

# External object files for target search_adjacent
search_adjacent_EXTERNAL_OBJECTS =

std_algorithm/non_modifying_algorithm/search_adjacent: std_algorithm/non_modifying_algorithm/CMakeFiles/search_adjacent.dir/search_adjacent.cc.o
std_algorithm/non_modifying_algorithm/search_adjacent: std_algorithm/non_modifying_algorithm/CMakeFiles/search_adjacent.dir/build.make
std_algorithm/non_modifying_algorithm/search_adjacent: std_algorithm/non_modifying_algorithm/CMakeFiles/search_adjacent.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ljs/study/c++_practice/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable search_adjacent"
	cd /home/ljs/study/c++_practice/build/std_algorithm/non_modifying_algorithm && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/search_adjacent.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
std_algorithm/non_modifying_algorithm/CMakeFiles/search_adjacent.dir/build: std_algorithm/non_modifying_algorithm/search_adjacent

.PHONY : std_algorithm/non_modifying_algorithm/CMakeFiles/search_adjacent.dir/build

std_algorithm/non_modifying_algorithm/CMakeFiles/search_adjacent.dir/requires: std_algorithm/non_modifying_algorithm/CMakeFiles/search_adjacent.dir/search_adjacent.cc.o.requires

.PHONY : std_algorithm/non_modifying_algorithm/CMakeFiles/search_adjacent.dir/requires

std_algorithm/non_modifying_algorithm/CMakeFiles/search_adjacent.dir/clean:
	cd /home/ljs/study/c++_practice/build/std_algorithm/non_modifying_algorithm && $(CMAKE_COMMAND) -P CMakeFiles/search_adjacent.dir/cmake_clean.cmake
.PHONY : std_algorithm/non_modifying_algorithm/CMakeFiles/search_adjacent.dir/clean

std_algorithm/non_modifying_algorithm/CMakeFiles/search_adjacent.dir/depend:
	cd /home/ljs/study/c++_practice/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ljs/study/c++_practice /home/ljs/study/c++_practice/std_algorithm/non_modifying_algorithm /home/ljs/study/c++_practice/build /home/ljs/study/c++_practice/build/std_algorithm/non_modifying_algorithm /home/ljs/study/c++_practice/build/std_algorithm/non_modifying_algorithm/CMakeFiles/search_adjacent.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : std_algorithm/non_modifying_algorithm/CMakeFiles/search_adjacent.dir/depend

