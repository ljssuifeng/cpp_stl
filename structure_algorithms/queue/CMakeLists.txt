INCLUDE_DIRECTORIES(${SOURCE_DIR})
add_executable(my_queue_test queue_test.cc queue.h ${SOURCE_DIR}/structure_algorithms/my_exceptions.h)
add_executable(queue_railroad_sort queue_railroad_sort.cc queue.h ${SOURCE_DIR}/structure_algorithms/my_exceptions.h)
add_executable(route_test route_test.cc queue.h ${SOURCE_DIR}/structure_algorithms/my_exceptions.h)
