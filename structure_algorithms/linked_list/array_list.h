#pragma once
#include <iostream>
#include <iterator>
#include "linked_list.h"

template <typename T>
class ArrayIterator : public std::iterator<std::bidirectional_iterator_tag, T> {
 public:
  ArrayIterator(T* p) { _ptr = p; }
  T& operator*() const { return *_ptr; }
  T* operator->() const { return &*_ptr; }

  ArrayIterator<T>& operator++() {  //++ before
    ++_ptr;
    return *this;
  }
  ArrayIterator<T> operator++(int) {  // ++ behind
    ArrayIterator old = *this;
    ++_ptr;
    return old;
  }

  ArrayIterator<T>& operator--() {
    --_ptr;
    return *this;
  }
  ArrayIterator<T> operator--(int) {
    ArrayIterator old = *this;
    --_ptr;
    return old;
  }

  // test whether equal
  bool operator!=(const ArrayIterator<T>& right) const {
    return _ptr != right._ptr;
  }
  bool operator==(const ArrayIterator<T>& right) const {
    return _ptr == right._ptr;
  }
  void operator=(const ArrayIterator<T>& right) {
    if (_ptr) delete _ptr;
    _ptr = right._ptr;
  }

 private:
  T* _ptr;
};

template <typename T>
class ArrayList : public LinearList<T> {
 public:
  typedef ArrayIterator<T> iterator;
  ArrayList(int initialCapcity = 10);
  ArrayList(const ArrayList<T>&);
  ~ArrayList() { delete[] element; }

  bool empty() const { return listSize == 0; }
  int size() const { return listSize; }
  T& get(int theIndex) const;
  int indexOf(const T& theElement) const;
  void erase(int theIndex);
  void insert(int theIndex, const T& theElement);
  void output(std::ostream& out) const;
  int capacity() const { return arrayLength; }
  void changeLength1D(int oldLength, int newLength);
  void reSet(int capacity);
  void set(int index, const T& value);
  void clear();

  iterator begin() const { return iterator(element); }
  iterator end() const { return iterator(element + listSize); }

 protected:
  void checkIndex(int theIndex) const;
  T* element;
  int arrayLength;  // capacity
  int listSize;     // element counts
};
