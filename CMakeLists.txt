set(SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR})
cmake_minimum_required(VERSION 3.1)
project(cpp_practice)

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -O3 -msse4.1 -fopenmp")
#set debug mode
SET (CMAKE_BUILD_TYPE Release CACHE INTERNAL "" FORCE)

add_definitions(-std=c++11)

add_subdirectory(${SOURCE_DIR}/const_keyword)
add_subdirectory(${SOURCE_DIR}/friend_class)
add_subdirectory(${SOURCE_DIR}/smart_pointer)
add_subdirectory(${SOURCE_DIR}/std_pair)
add_subdirectory(${SOURCE_DIR}/std_tuple)
add_subdirectory(${SOURCE_DIR}/std_numeric_limits)
add_subdirectory(${SOURCE_DIR}/std_type_trait)
add_subdirectory(${SOURCE_DIR}/container)
add_subdirectory(${SOURCE_DIR}/std_algorithm)
add_subdirectory(${SOURCE_DIR}/std_iterator)
add_subdirectory(${SOURCE_DIR}/function_object)
add_subdirectory(${SOURCE_DIR}/std_io)
add_subdirectory(${SOURCE_DIR}/std_number)
add_subdirectory(${SOURCE_DIR}/concurrency_program)
add_subdirectory(${SOURCE_DIR}/design_pattern)
add_subdirectory(${SOURCE_DIR}/variadic_templates)
add_subdirectory(${SOURCE_DIR}/debug)
add_subdirectory(${SOURCE_DIR}/structure_algorithms)
