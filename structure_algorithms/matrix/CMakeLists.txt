INCLUDE_DIRECTORIES(${SOURCE_DIR})
add_executable(matrix_test matrix.h matrix.cc matrix_test.cc)
add_executable(diagonal_matrix_test diagonal_matrix_test.cc diagonal_matrix.h)
add_executable(sparse_matrix_test sparse_matrix_test.cc sparse_matrix.h)

