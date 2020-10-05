INCLUDE_DIRECTORIES(${SOURCE_DIR})
#FILE(SOURCE_FILE
#    ${SOURCE_DIR)
add_executable(my_stack_test stack_test.cc stack.h)
add_executable(cluster_test cluster.cc stack.h)
add_executable(maze_test maze_test.cc stack.h)
