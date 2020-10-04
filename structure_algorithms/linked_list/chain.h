#pragma once
#include "linked_list.h"

template <typename T>
struct ChainNode {
  T _element;
  ChainNode<T>* _next;

  ChainNode(const T& element) : _element(element) {}
  ChainNode(const T& element, ChainNode<T>* next)
      : _element(element), _next(next) {}
};

template <typename T>
class ChainIterator : public std::iterator<std::forward_iterator_tag, T> {
 public:
  ChainIterator(ChainNode<T>* theNode = nullptr) : _node(theNode) {}
  T& operator*() const { return _node->_element; }
  T* operator->() const { return &_node->_element; }

  ChainIterator<T>& operator++() {
    _node = _node->_next;
    return *this;
  }
  ChainIterator<T> operator++(int) {
    ChainIterator<T> old = *this;
    _node = _node->_next;
    return old;
  }

  bool operator==(const ChainIterator<T>& rhs) const {
    return _node == rhs._node;
  }
  bool operator!=(const ChainIterator<T>& rhs) const {
    return _node != rhs._node;
  }

 private:
  ChainNode<T>* _node;
};

template <typename T>
class Chain : public LinearList<T> {
 public:
  typedef ChainIterator<T> iterator;
  Chain(int initialCapacity = 10);
  Chain(const Chain<T>&);
  ~Chain();

  // ADT
  bool empty() const { return _listSize == 0; }
  int size() const { return _listSize; }
  T& get(int theIndex) const;
  int indexOf(const T& theEelement) const;
  void erase(int theIndex);
  void insert(int theIndex, const T& theElement);
  void output(std::ostream& out) const;
  iterator begin() { return iterator(_first_node); }
  iterator end() { return iterator(nullptr); }

 private:
  int _listSize;
  ChainNode<T>* _first_node;
  void checkIndex(int theIndex) const;
};
