#include "matrix.h"
#include <algorithm>
#include <exception>
#include <iostream>
#include <iterator>

template <typename T>
Matrix<T>::Matrix(int theRows, int theColumns) {
  // check arguments
  if (theRows < 0 || theColumns < 0) {
    throw std::invalid_argument("Rows and columns must be >= 0!");
  }
  if ((theRows == 0 || theColumns == 0) && (theRows != 0 || theColumns != 0)) {
    throw std::invalid_argument(
        "Either both or neither rows and columns should be 0!");
  }
  // create matrix
  _theRows = theRows;
  _theColumns = theColumns;
  element = new T[_theRows * _theColumns];
}

template <typename T>
Matrix<T>::Matrix(const Matrix<T>& m) {
  // copy matrix
  _theRows = m._theRows;
  _theColumns = m._theColumns;
  element = new T[_theRows * _theColumns];

  std::copy(m.element, m.element + _theColumns * _theRows, element);
}

template <typename T>
Matrix<T>& Matrix<T>::operator=(const Matrix<T>& m) {
  if (*this != m) {
    delete[] element;
    _theColumns = m._theColumns;
    _theRows = m._theRows;
    element = new T[_theRows * _theColumns];
    std::copy(m.element, m.element + _theColumns * _theRows, element);
  }
  return *this;
}

template <typename T>
T& Matrix<T>::operator()(int i, int j) const {
  if (i < 1 || i > _theRows || j < 1 || j > _theColumns) {
    throw std::invalid_argument("Matrix index out of Bounds!");
  }
  return element[(i - 1) * _theColumns + (j - 1)];
}

template <typename T>
Matrix<T> Matrix<T>::operator+(const Matrix<T>& m) const {
  if (_theRows != m._theRows || _theColumns != m._theColumns) {
    throw std::invalid_argument("matrix size mismatch!");
  }
  Matrix<T> w(_theRows, _theColumns);
  for (int i = 0; i < _theRows * _theColumns; ++i) {
    w.element[i] = element[i] + m.element[i];
  }
  return w;
}

template <typename T>
Matrix<T> Matrix<T>::operator-(const Matrix<T>& m) const {
  if (_theRows != m._theRows || _theColumns != m._theColumns) {
    throw std::invalid_argument("matrix size mismatch!");
  }
  Matrix<T> w(_theRows, _theColumns);
  for (int i = 0; i < _theRows * _theColumns; ++i) {
    w.element[i] = element[i] - m.element[i];
  }
  return w;
}

template <typename T>
Matrix<T>& Matrix<T>::operator+=(const Matrix<T>& m) {
  if (_theRows != m._theRows || _theColumns != m._theColumns) {
    throw std::invalid_argument("matrix size mismatch!");
  }
  for (int i = 0; i < _theRows * _theColumns; ++i) {
    element[i] += m.element[i];
  }
  return *this;
}

template <typename T>
Matrix<T> Matrix<T>::operator*(const Matrix<T>& m) const {
  if (_theColumns != m._theRows) {
    throw std::invalid_argument("Matrix size mismatch when multiply!");
  }
  Matrix<T> w(_theRows, m._theColumns);
  int ct = 0, cm = 0, cw = 0;
  for (int i = 1; i <= _theRows; ++i) {
    for (int j = 1; j <= m._theColumns; ++j) {
      T sum = element[ct] * m.element[cm];
      for (int k = 2; k <= _theColumns; ++k) {
        ct++;
        cm += m._theColumns;
        sum += element[ct] * m.element[cm];
      }
      w.element[cw++] = sum;
      ct -= _theColumns - 1;  // return to the first element of the row i
      cm = j;                 // return to the first element of next column
    }
    ct += _theColumns;
    cm = 0;
  }
  return w;
}

template <typename M>
std::ostream& operator<<(std::ostream& out, const Matrix<M>& m) {
  out << "matrix rows: " << m.rows() << '\n';
  out << "matrix columns: " << m.columns() << '\n';
  out << "matrix elements:\n";
  for (int i = 0; i < m.rows(); ++i) {
    std::copy(m.element + i * m._theColumns,
              m.element + (i + 1) * m._theColumns,
              std::ostream_iterator<M>(out, "\t"));
    std::cout << std::endl;
  }
  return out;
}
