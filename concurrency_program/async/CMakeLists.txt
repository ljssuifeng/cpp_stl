add_executable(async_future async_future.cc)
add_executable(async_exception async_exception.cc)
add_executable(async_wait async_wait.cc)
add_executable(shared_future shared_future.cc)

target_link_libraries(async_wait pthread)
target_link_libraries(async_future pthread)
target_link_libraries(async_exception pthread)
target_link_libraries(shared_future pthread)
