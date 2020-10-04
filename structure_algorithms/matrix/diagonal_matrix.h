#include <exception>
#include <iostream>

template <typename T>
class DiagonalMatrix {
 public:
  DiagonalMatrix() = default;
  DiagonalMatrix(int theN);
  ~DiagonalMatrix() { delete[] element; }
  virtual T get(int, int) const;
  virtual void set(int, int, const T&);

 protected:
  int n;
  T* element;
};

template <typename T>
DiagonalMatrix<T>::DiagonalMatrix(int theN) {
  if (theN < 1) {
    throw std::invalid_argument("Matrix size must be > 0!");
  }
  n = theN;
  element = new T[n];
}

template <typename T>
T DiagonalMatrix<T>::get(int i, int j) const {
  if (i < 1 || j < 1 || i > n || j > n) {
    throw std::invalid_argument("Matrix index out of Bounds!");
  }
  if (i == j) {
    return element[i - 1];
  } else {
    return 0;
  }
}

template <typename T>
void DiagonalMatrix<T>::set(int i, int j, const T& newValue) {
  if (i < 1 || j < 1 || i > n || j > n) {
    throw std::invalid_argument("Matrix index out of Bounds!");
  }
  if (i == j) {
    element[i - 1] = newValue;
  } else {
    if (newValue != 0) {
      throw std::invalid_argument("nondiagonal elements must be zero!");
    }
  }
}

template <typename T>
class TriDiagonalMatrix : public DiagonalMatrix<T> {
 public:
  TriDiagonalMatrix(int theN);
  ~TriDiagonalMatrix() {}

  virtual T get(int, int) const override;
  virtual void set(int, int, const T&) override;
};

template <typename T>
TriDiagonalMatrix<T>::TriDiagonalMatrix(int theN) {
  if (theN < 1) {
    throw std::invalid_argument("Matrix size must be > 0!");
  }
  this->n = theN;
  this->element = new T[3 * this->n - 2];
}

template <typename T>
T TriDiagonalMatrix<T>::get(int i, int j) const {
  if (i < 1 || j < 1 || i > this->n || j > this->n) {
    throw std::invalid_argument("Matrix index out of Bounds!");
  }
  switch (i - j) {
    case 1:
      return this->element[i - 2];
    case 0:
      return this->element[this->n + i - 2];
    case -1:
      return this->element[2 * this->n + i - 2];
    default:
      return 0;
  }
}

template <typename T>
void TriDiagonalMatrix<T>::set(int i, int j, const T& newValue) {
  if (i < 1 || j < 1 || i > this->n || j > this->n) {
    throw std::invalid_argument("Matrix index out of Bounds!");
  }
  switch (i - j) {
    case 1:
      this->element[i - 2] = newValue;
      break;
    case 0:
      this->element[this->n + i - 2] = newValue;
      break;
    case -1:
      this->element[2 * this->n + i - 2] = newValue;
      break;
    default:
      if (newValue != 0) {
        throw std::invalid_argument("element not in tridiagonal must be zero.");
      }
      break;
  }
}

template <typename T>
class LowerTriangularMatrix : public DiagonalMatrix<T> {
 public:
  LowerTriangularMatrix(int theN);
  ~LowerTriangularMatrix() {}
  virtual T get(int, int) const override;
  virtual void set(int, int, const T&) override;
};

template <typename T>
LowerTriangularMatrix<T>::LowerTriangularMatrix(int theN) {
  if (theN < 1) {
    throw std::invalid_argument("Matrix size must be > 0!");
  }
  this->n = theN;
  this->element = new T[this->n * (this->n + 1) / 2];
}

template <typename T>
T LowerTriangularMatrix<T>::get(int i, int j) const {
  if (i < 1 || j < 1 || i > this->n || j > this->n) {
    throw std::invalid_argument("Matrix index out of Bound!");
  }

  if (i >= j) {
    return this->element[i * (i - 1) / 2 + j - 1];
  } else {
    return 0;
  }
}

template <typename T>
void LowerTriangularMatrix<T>::set(int i, int j, const T& newValue) {
  if (i < 1 || j < 1 || i > this->n || j > this->n) {
    throw std::invalid_argument("Matrix index out of Bound!");
  }

  if (i >= j) {
    this->element[i * (i - 1) / 2 + j - 1] = newValue;
  } else if (newValue != 0) {
    throw std::invalid_argument("elements not in triangule must be zero.");
  }
}
