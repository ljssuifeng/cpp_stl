#include "sparse_matrix.h"
#include <iostream>

int main() {
  SparseMatrix<double> sparse_m;
  std::cin >> sparse_m;

  std::cout << sparse_m;
  SparseMatrix<double> sparse_m2;
  sparse_m.transpose(sparse_m2);
  std::cout << sparse_m2;
  SparseMatrix<double> sparse_m3;
  sparse_m.add(sparse_m2, sparse_m3);
  std::cout << sparse_m3;
}
