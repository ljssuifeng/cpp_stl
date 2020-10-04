#pragma once
#include <iostream>

template <typename T>
class Matrix {
 public:
  Matrix(int theRows = 0, int theColumns = 0);
  Matrix(const Matrix<T>&);
  virtual ~Matrix() { delete[] element; }
  int rows() const { return _theRows; }
  int columns() const { return _theColumns; }
  T& operator()(int i, int j) const;
  Matrix<T>& operator=(const Matrix<T>&);
  //  Matrix<T> operator+() const;  // unary +
  Matrix<T> operator+(const Matrix<T>&) const;
  //  Matrix<T> operator-() const;  // unary -
  Matrix<T> operator-(const Matrix<T>&) const;
  Matrix<T> operator*(const Matrix<T>&)const;
  Matrix<T>& operator+=(const Matrix<T>&);
  template <typename M>
  friend std::ostream& operator<<(std::ostream& out, const Matrix<M>&);

 private:
  int _theRows, _theColumns;
  T* element;
};
