#include "chain.h"
#include <exception>
#include <sstream>

template <typename T>
Chain<T>::Chain(int initialCapcity) {
  if (initialCapcity < 0) {
    std::stringstream s;
    s << "Initial capacity = " << initialCapcity << " Must be > 0!\n";
    throw std::invalid_argument(s.str());
  }
  _first_node = nullptr;
  _listSize = 0;
}

template <typename T>
Chain<T>::Chain(const Chain<T>& theList) {
  _listSize = theList._listSize;
  if (_listSize == 0) {
    _first_node = nullptr;
    return;
  }
  ChainNode<T>* sourceNode = theList._first_node;
  _first_node = new ChainNode<T>(sourceNode->_element);
  sourceNode = sourceNode->_next;
  ChainNode<T>* targetNode = _first_node;
  while (sourceNode != nullptr) {
    targetNode->_next = new ChainNode<T>(sourceNode->_element);
    targetNode = targetNode->_next;
    sourceNode = sourceNode->_next;
  }
  targetNode->_next = nullptr;
}

template <typename T>
Chain<T>::~Chain() {
  while (_first_node) {
    ChainNode<T>* nextNode = _first_node->_next;
    delete _first_node;
    _first_node = nextNode;
  }
}

template <typename T>
T& Chain<T>::get(int theIndex) const {
  checkIndex(theIndex);
  ChainNode<T>* currentNode = _first_node;
  for (int i = 0; i < theIndex; ++i) {
    currentNode = currentNode->_next;
  }
  return currentNode->_element;
}

template <typename T>
int Chain<T>::indexOf(const T& theEelement) const {
  ChainNode<T>* currentNode = _first_node;
  int index = 0;
  while (currentNode->_element != theEelement && currentNode) {
    currentNode = currentNode->_next;
    index++;
  }
  if (!currentNode) return -1;
  return index;
}

template <typename T>
void Chain<T>::erase(int theIndex) {
  checkIndex(theIndex);
  ChainNode<T>* deleteNode;
  if (theIndex == 0) {
    deleteNode = _first_node;
    _first_node = _first_node->_next;
  } else {
    ChainNode<T>* p = _first_node;
    for (int i = 0; i < theIndex - 1; ++i) {
      p = p->_next;
    }
    deleteNode = p->_next;
    p->_next = p->_next->_next;
  }
  _listSize--;
  delete deleteNode;
}

template <typename T>
void Chain<T>::insert(int theIndex, const T& theElement) {
  if (theIndex < 0 || theIndex > _listSize) {
    std::ostringstream s;
    s << "index= " << theIndex << " size= " << _listSize;
    throw std::invalid_argument(s.str());
  }

  if (theIndex == 0) {
    //        ChainNode<T>* insertNode = new ChainNode<T>(theElement);
    //        insertNode->_next = _first_node;
    //        _first_node = insertNode;
    _first_node = new ChainNode<T>(theElement, _first_node);
  } else {
    ChainNode<T>* p = _first_node;
    for (int i = 0; i < theIndex - 1; ++i) {
      p = p->_next;
    }
    //        ChainNode<T>* insertNode = new ChainNode<T>(theElement);
    //        insertNode->_next = p->_next;
    //        p->_next = insertNode;
    p->_next = new ChainNode<T>(theElement, p->_next);
  }
  _listSize += 1;
}

template <typename T>
void Chain<T>::output(std::ostream& out) const {
  for (ChainNode<T>* currentNode = _first_node; currentNode;
       currentNode = currentNode->_next) {
    out << currentNode->_element << " ";
  }
  out << '\n';
}

template <typename T>
std::ostream& operator<<(std::ostream& out, const Chain<T>& x) {
  x.output(out);
  return out;
}

template <typename T>
void Chain<T>::checkIndex(int theIndex) const {
  if (theIndex < 0 || theIndex >= _listSize) {
    std::ostringstream s;
    s << "index = " << theIndex << " size = " << _listSize;
    throw std::invalid_argument(s.str());
  }
}
