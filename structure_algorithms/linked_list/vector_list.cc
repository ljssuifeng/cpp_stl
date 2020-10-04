#include "vector_list.h"
#include <exception>
#include <sstream>

template <typename T>
VectorList<T>::VectorList(int initialCapacity) {
  if (initialCapacity < 0) {
    std::ostringstream s;
    s << "initial capacity = " << initialCapacity << " must be > 0!\n";
    throw std::invalid_argument(s.str());
  }

  element = new std::vector<T>;
  element->reserve(initialCapacity);
}

template <typename T>
VectorList<T>::VectorList(const VectorList<T> &theList) {
  element = new std::vector<T>(*theList.element);
}

template <typename T>
void VectorList<T>::erase(int theIndex) {
  checkIndex(theIndex);
  element->erase(begin() + theIndex);
}

template <class T>
void VectorList<T>::insert(int theIndex, const T &theElement) {
  if (theIndex < 0 || theIndex > size()) {
    std::ostringstream s;
    s << "index = " << theIndex << " size= " << size();
    throw std::invalid_argument(s.str());
  }
  element->insert(begin() + theIndex, theElement);
}

template <typename T>
void VectorList<T>::checkIndex(int theIndex) const {
  if (theIndex < 0 || theIndex >= size()) {
    std::ostringstream s;
    s << "index = " << theIndex << " size = " << size();
    throw std::invalid_argument(s.str());
  }
}
