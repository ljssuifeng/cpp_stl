#include "array_list.h"
#include <algorithm>
#include <memory>
#include <sstream>
#include <stdexcept>

template <typename T>
void ArrayList<T>::changeLength1D(int oldLength, int newLength) {
  if (newLength < 0) {
    throw std::invalid_argument("newLength must be > 0!");
  }
  T* temp = new T[newLength];
  int number = std::min(oldLength, newLength);
  std::copy(element, element + number, temp);
  delete[] element;
  element = temp;
}

template <typename T>
void ArrayList<T>::reSet(int capacity) {
  if (capacity < 1) {
    throw std::invalid_argument("new length must be > 0!");
  }
  if (element) {
    delete[] element;
  }
  element = new T[capacity];
  listSize = capacity;
}

template <typename T>
void ArrayList<T>::set(int index, const T& value) {
  checkIndex(index);
  element[index] = value;
}

template <typename T>
void ArrayList<T>::clear() {
  while (listSize) element[--listSize].~T();
}

template <typename T>
ArrayList<T>::ArrayList(int initialCapacity) {
  if (initialCapacity < 1) {
    std::ostringstream s;
    s << "Initial capacity = " << initialCapacity << " Must be > 0!";
    throw std::invalid_argument(s.str());
  }
  arrayLength = initialCapacity;
  element = new T[arrayLength];
  listSize = 0;
}

template <typename T>
ArrayList<T>::ArrayList(const ArrayList<T>& theList) {
  arrayLength = theList.arrayLength;
  listSize = theList.listSize;
  element = new T[arrayLength];
  std::copy(theList.element, theList.element + theList.listSize, element);
}

template <typename T>
void ArrayList<T>::checkIndex(int theIndex) const {
  if (theIndex < 0 || theIndex >= listSize) {
    std::ostringstream s;
    s << "index = " << theIndex << " size = " << listSize;
    throw std::invalid_argument(s.str());
  }
}

template <typename T>
T& ArrayList<T>::get(int theIndex) const {
  checkIndex(theIndex);
  return element[theIndex];
}

template <typename T>
int ArrayList<T>::indexOf(const T& theElement) const {
  int theIndex =
      (int)(std::find(element, element + listSize, theElement) - element);
  if (theIndex == listSize) {
    return -1;
  }
  return theIndex;
}

template <typename T>
void ArrayList<T>::erase(int theIndex) {
  checkIndex(theIndex);
  std::copy(element + theIndex + 1, element + listSize, element + theIndex);
  element[--listSize].~T();
}

template <typename T>
void ArrayList<T>::insert(int theIndex, const T& theElement) {
  if (theIndex < 0 || theIndex > listSize) {
    std::ostringstream s;
    s << "index= " << theIndex << " size = " << listSize;
    throw std::invalid_argument(s.str());
  }
  if (listSize == arrayLength) {
    changeLength1D(arrayLength, 2 * arrayLength);
    arrayLength *= 2;
  }
  std::copy_backward(element + theIndex, element + listSize,
                     element + listSize + 1);
  element[theIndex] = theElement;
  listSize++;
}

template <typename T>
void ArrayList<T>::output(std::ostream& out) const {
  std::copy(element, element + listSize, std::ostream_iterator<T>(out, " "));
  out << std::endl;
}

template <typename T>
std::ostream& operator<<(std::ostream& out, const ArrayList<T>& x) {
  x.output(out);
  return out;
}
