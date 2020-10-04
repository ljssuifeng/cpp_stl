#pragma once
#include <iostream>
#include "structure_algorithms/linked_list/array_list.cc"
#include "structure_algorithms/linked_list/array_list.h"

using std::cout;
using std::endl;
template <typename T>
struct MatrixTerm {
  int row;
  int column;
  T value;

  void operator=(const MatrixTerm<T>& m) {
    row = m.row;
    column = m.column;
    value = m.value;
  }
  bool operator==(const MatrixTerm<T>& m) {
    return (row == m.row && column == m.column && value == m.value);
  }
  template <typename M>
  friend std::ostream& operator<<(std::ostream& out, const MatrixTerm<M>& m);
};

template <typename T>
std::ostream& operator<<(std::ostream& out, const MatrixTerm<T>& m) {
  out << "a(" << m.row << ',' << m.column << ") = " << m.value << endl;
  return out;
}

template <typename T>
class SparseMatrix {
 public:
  void transpose(SparseMatrix<T>& b);
  void add(SparseMatrix<T>& b, SparseMatrix<T>& c);
  template <typename M>
  friend std::ostream& operator<<(std::ostream& out, const SparseMatrix<M>& m);
  template <typename M>
  friend std::istream& operator>>(std::istream& in, SparseMatrix<M>& m);

 private:
  int _rows, _columns;              // row and column counts of the matrix
  ArrayList<MatrixTerm<T>> _terms;  // non-zero elements sheet
};

template <typename T>
std::ostream& operator<<(std::ostream& out, const SparseMatrix<T>& m) {
  out << "rows = " << m._rows << " columns = " << m._columns << endl;
  for (auto& elem : m._terms) {
    out << elem;
  }
  return out;
}

template <typename T>
std::istream& operator>>(std::istream& in, SparseMatrix<T>& m) {
  // input characters of the matrix
  int numOfTerms;
  cout << "Enter number of rows, columns, and #terms" << endl;
  in >> m._rows >> m._columns >> numOfTerms;
  //    TODO: here we should clarify the validity of inputs
  m._terms.reSet(numOfTerms);
  MatrixTerm<T> mTerm;
  for (int i = 0; i < numOfTerms; ++i) {
    cout << "Enter row, column, and value of term " << (i + 1) << endl;
    in >> mTerm.row >> mTerm.column >> mTerm.value;
    //    TODO: here we should clarify the validity of inputs
    m._terms.set(i, mTerm);
  }
  return in;
}
template <typename T>
void SparseMatrix<T>::transpose(SparseMatrix<T>& b) {
  // put transpose of *this in b
  b._rows = _columns;
  b._columns = _rows;
  b._terms.reSet(_terms.size());

  // init to relize transpose
  int* colSize =
      new int[_columns +
              1];  // to record the number of non-zero elements in each column
  int* rowNext =
      new int[_columns +
              1];  // to record the first non-zero element index in each column

  for (int i = 1; i <= _columns; ++i) {
    colSize[i] = 0;
  }
  for (ArrayIterator<MatrixTerm<T>> iter = _terms.begin(); iter != _terms.end();
       ++iter) {
    colSize[(*iter).column]++;
  }
  // find the start position of each rows in b
  rowNext[1] = 0;
  for (int i = 2; i <= _columns; ++i) {
    rowNext[i] = rowNext[i - 1] + colSize[i - 1];
  }

  // then copy
  MatrixTerm<T> mTerm;
  for (ArrayIterator<MatrixTerm<T>> iter = _terms.begin(); iter != _terms.end();
       ++iter) {
    int j = rowNext[(*iter).column]++;  // mark the first pos of each row, ++
    mTerm.row = (*iter).column;
    mTerm.column = (*iter).row;
    mTerm.value = (*iter).value;
    b._terms.set(j, mTerm);
  }
}

template <typename T>
void SparseMatrix<T>::add(SparseMatrix<T>& b, SparseMatrix<T>& c) {
  // caculate c = *this +b
  if (b._rows != _rows || b._columns != _columns) {
    throw std::invalid_argument("matrix mismatch!");
  }
  c._rows = _rows;
  c._columns = _columns;
  c._terms.clear();
  int cSize = 0;

  // define iterator of *this and b
  ArrayIterator<MatrixTerm<T>> it = _terms.begin();
  ArrayIterator<MatrixTerm<T>> ib = b._terms.begin();
  ArrayIterator<MatrixTerm<T>> itEnd = _terms.end();
  ArrayIterator<MatrixTerm<T>> ibEnd = b._terms.end();

  while (it != itEnd && ib != ibEnd) {
    int tIndex = (*it).row * _columns + (*it).column;
    int bIndex = (*ib).row * _columns + (*ib).column;

    if (tIndex < bIndex) {
      c._terms.insert(cSize++, *it);
      it++;
    } else {
      if (tIndex == bIndex) {
        // only if *it.value+*ib.value != 0, insert the result into c
        if ((*it).value + (*ib).value != 0) {
          MatrixTerm<T> mTerm;
          mTerm.row = (*it).row;
          mTerm.column = (*it).column;
          mTerm.value = (*it).value + (*ib).value;
          c._terms.insert(cSize++, mTerm);
        }
        it++;
        ib++;
      } else {
        c._terms.insert(cSize++, *ib);
        ib++;
      }
    }
  }
  // copy the rest of element in b or *this
  for (; it != itEnd; ++it) {
    c._terms.insert(cSize++, *it);
  }
  for (; ib != ibEnd; ++ib) {
    c._terms.insert(cSize++, *ib);
  }
}
