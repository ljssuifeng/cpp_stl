include_directories(${COURRENCT_SOURCE_DIR})
add_executable(singleton singleton.cc singleton_main.cc)
add_executable(singleton_logger logger_test.cc logger.cc logger.h)

