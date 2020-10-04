#pragma once
#include <vector>
#include "linked_list.h"

template <typename T>
class VectorList : public LinearList<T> {
 public:
  VectorList(int initialCapacity = 10);
  VectorList(const VectorList<T>&);
  ~VectorList() { delete element; }

  bool empty() const { return element->empty(); }
  int size() const { return static_cast<int>(element->size()); }
  T& get(int theIndex) const;
  int indexOf(const T& theEelement) const;
  void erase(int theIndex);
  void insert(int theIndex, const T& theElement);
  void output(std::ostream& out) const;
  int capacity() const { return element->capacity(); }

  typedef typename std::vector<T>::iterator iterator;
  iterator begin() { return element->begin(); }
  iterator end() { return element->end(); }

 private:
  void checkIndex(int theIndex) const;
  std::vector<T>* element;
};
