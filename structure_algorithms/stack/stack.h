#pragma once
#include <iostream>
#include "structure_algorithms/linked_list/array_list.cc"
#include "structure_algorithms/linked_list/array_list.h"
#include "structure_algorithms/linked_list/chain.cc"
#include "structure_algorithms/linked_list/chain.h"

template <typename T>
void changeLength1D(T*& source, int oldLength, int newLength) {
  if (newLength < 0) {
    throw std::invalid_argument("newLength must be > 0!");
  }
  T* temp = new T[newLength];
  int number = std::min(oldLength, newLength);
  std::copy(source, source + number, temp);
  delete[] source;
  source = temp;
}

// abstract class for stack
template <typename T>
class Stack {
 public:
  virtual ~Stack() {}
  virtual bool empty() const = 0;
  virtual int size() const = 0;
  virtual T& top() = 0;
  virtual void pop() = 0;
  virtual void push(const T& theElement) = 0;
};

template <typename T>
class DerivedArrayStack : private ArrayList<T>, public Stack<T> {
 public:
  DerivedArrayStack(int initialCapacity = 10) : ArrayList<T>(initialCapacity) {}
  bool empty() const { return ArrayList<T>::empty(); }
  int size() const { return ArrayList<T>::size(); }
  T& top() {
    try {
      return ArrayList<T>::get(size() - 1);
    } catch (std::invalid_argument) {
      throw std::invalid_argument("stack empty!");
    }
  }

  void pop() {
    try {
      ArrayList<T>::erase(size() - 1);
    } catch (std::invalid_argument) {
      throw std::invalid_argument("stack empty!");
    }
  }

  void push(const T& theElement) { ArrayList<T>::insert(size(), theElement); }
};

// no derived class has better effciency
template <typename T>
class ArrayStack : public Stack<T> {
 public:
  ArrayStack(int initialCapacity = 10);
  ~ArrayStack() { delete[] _stack; }
  bool empty() const { return _stackTop == -1; }
  int size() const { return _stackTop + 1; }
  T& top() {
    if (_stackTop == -1) {
      throw std::invalid_argument("stack empty!");
    }
    return _stack[_stackTop];
  }
  void pop() {
    if (_stackTop == -1) {
      throw std::invalid_argument("stack empty!");
    }
    _stack[_stackTop--].~T();
  }
  void push(const T& theElement);
  template <typename M>
  friend std::ostream& operator<<(std::ostream& out, ArrayStack<M>& as);

 private:
  T* _stack;
  int _stackTop;
  int _arrayLength;
};
template <typename T>
std::ostream& operator<<(std::ostream& out, ArrayStack<T>& as) {
  while (!as.empty()) {
    out << as.top();
    as.pop();
  }
  return out;
}

template <typename T>
ArrayStack<T>::ArrayStack(int initialCapacity) {
  if (initialCapacity < 1) {
    std::ostringstream s;
    s << "Initial capacity = " << initialCapacity << " must be > 0";
    throw std::invalid_argument(s.str());
  }
  _arrayLength = initialCapacity;
  _stack = new T[_arrayLength];
  _stackTop = -1;
}

template <typename T>
void ArrayStack<T>::push(const T& theElement) {
  if (_stackTop == _arrayLength - 1) {  // stack is full
    changeLength1D(_stack, _arrayLength, _arrayLength * 2);
    _arrayLength *= 2;
  }
  _stack[++_stackTop] = theElement;
}

template <typename T>
class DerivedLinkedStack : private Chain<T>, public Stack<T> {
 public:
  DerivedLinkedStack(int initialCapacity = 10) : Chain<T>(initialCapacity) {}
  bool empty() const { return Chain<T>::empty(); }
  int size() const { return Chain<T>::size(); }
  T& top() {
    try {
      return Chain<T>::get(size() - 1);
    } catch (std::invalid_argument) {
      throw std::invalid_argument("stack empty!");
    }
  }

  void pop() {
    try {
      Chain<T>::erase(size() - 1);
    } catch (std::invalid_argument) {
      throw std::invalid_argument("stack empty!");
    }
  }

  void push(const T& theElement) { Chain<T>::insert(size(), theElement); }
};

template <typename T>
class LinkedStack : public Stack<T> {
 public:
  LinkedStack(int initialCapacity = 10) {
    _stackTop = nullptr;
    _stackSize = 0;
  }
  ~LinkedStack();
  bool empty() const { return _stackSize == 0; }
  int size() const { return _stackSize; }
  T& top() {
    if (_stackSize == 0) {
      throw std::invalid_argument("stack is empty!");
    }
    return _stackTop->_element;
  }
  void pop();
  void push(const T& theElement) {
    _stackTop = new ChainNode<T>(theElement, _stackTop);
    _stackSize++;
  }

 private:
  ChainNode<T>* _stackTop;
  int _stackSize;
};

template <typename T>
LinkedStack<T>::~LinkedStack() {
  while (_stackTop) {
    ChainNode<T>* nextNode = _stackTop->_next;
    delete _stackTop;
    _stackTop = nextNode;
    _stackSize--;
  }
}

template <typename T>
void LinkedStack<T>::pop() {
  if (_stackSize == 0) {
    throw std::invalid_argument("stack is empty!");
  }
  ChainNode<T>* nextNode = _stackTop->_next;
  delete _stackTop;
  _stackTop = nextNode;
  _stackSize--;
}
