#include "matrix.h"
#include "matrix.cc"

int main() {
  Matrix<double> m(5, 3);
  for (int i = 1; i <= m.rows(); ++i) {
    for (int j = 1; j <= m.columns(); ++j) {
      m(i, j) = i * j;
    }
  }
  std::cout << m << std::endl;

  Matrix<double> m2(m);
  std::cout << "matrix2 :\n";
  std::cout << m2 << std::endl;
}
