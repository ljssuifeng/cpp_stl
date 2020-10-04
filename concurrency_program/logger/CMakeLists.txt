add_executable(logger logger_test.cc logger.cc logger.h)
target_link_libraries(logger pthread)
