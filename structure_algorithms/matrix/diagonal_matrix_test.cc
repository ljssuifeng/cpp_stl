#include "diagonal_matrix.h"

int main() {
  DiagonalMatrix<int> diag_m(5);
  diag_m.set(5, 5, 3);
  diag_m.set(2, 2, 2);
  diag_m.set(1, 1, 13);
  diag_m.set(4, 4, 1);
  diag_m.set(3, 3, 3);

  std::cout << diag_m.get(1, 1) << std::endl;

  TriDiagonalMatrix<int> tridia_m(3);
  tridia_m.set(3, 2, 1);
  tridia_m.set(2, 1, 5);
  tridia_m.set(1, 2, 3);
  tridia_m.set(2, 3, 13);

  std::cout << tridia_m.get(2, 1) << std::endl;

  LowerTriangularMatrix<float> lower_triangle_m(4);
  lower_triangle_m.set(1, 1, 1);
  lower_triangle_m.set(2, 1, 23);
  lower_triangle_m.set(3, 2, 2);
  lower_triangle_m.set(4, 3, 3);
  lower_triangle_m.set(4, 4, 4);
  std::cout << lower_triangle_m.get(3, 2) << std::endl;
}
