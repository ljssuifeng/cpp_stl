#pragma once
#include <utility>
#include "structure_algorithms/my_exceptions.h"

template <typename K, typename E>
struct PairNode {
  std::pair<const K, E> element;
  PairNode<K, E>* next;
  PairNode() = default;
  PairNode(std::pair<const K, E>& thePair, PairNode<K, E>* theNext)
      : element(thePair), next(theNext) {}
};

template <typename K, typename E>
class Dictionary {
 public:
  virtual ~Dictionary() {}
  virtual bool empty() const = 0;
  virtual int size() const = 0;
  virtual std::pair<const K, E>* find(const K&) const = 0;
  virtual void erase(const K&) = 0;
  virtual void insert(std::pair<const K, E>&) = 0;
};

template <typename K, typename E>
class SortedChain : public Dictionary<K, E> {
 public:
  SortedChain(int initialCapacity) {
    _capacity = initialCapacity;
    _front = nullptr;
    _length = 0;
  }
  bool empty() const { return _length == 0; }
  int size() const { return _length; }
  std::pair<const K, E>* find(const K&) const;
  void erase(const K&);
  void insert(std::pair<const K, E>&);

 private:
  int _capacity;
  int _length;
  PairNode<K, E>* _front;
};

template <typename K, typename E>
std::pair<const K, E>* SortedChain<K, E>::find(const K& theKey) const {
  PairNode<K, E>* currentNode = _front;
  while (currentNode != nullptr && currentNode->element.first != theKey) {
    currentNode = currentNode->next;
  }
  if (currentNode != nullptr) {
    return &(currentNode->element);
  }
  return nullptr;
}

template <typename K, typename E>
void SortedChain<K, E>::erase(const K& theKey) {
  PairNode<K, E> *p = _front, *tp = nullptr;
  while (p != nullptr && p->element.first < theKey) {
    tp = p;  // mark the node befor aim node
    p = p->next;
  }
  if (p != nullptr && p->element.first == theKey) {
    if (tp == nullptr) {  // p is the first node
      _front = p->next;
    } else {
      tp->next = p->next;
    }
    delete p;
    _length--;
  }
}

template <typename K, typename E>
void SortedChain<K, E>::insert(std::pair<const K, E>& thePair) {
  PairNode<K, E> *p = _front, *tp = nullptr;
  while (p != nullptr && p->element.first < thePair.first) {
    tp = p;
    p = p->next;
  }
  if (p != nullptr && p->element.first == thePair.first) {
    // replace the old value
    p->element.second = thePair.second;
    return;
  } else {
    PairNode<K, E>* newNode = new PairNode<K, E>(thePair, p);
    // insert new node after tp
    if (tp == nullptr) {
      _front = newNode;
    } else {
      tp->next = newNode;
    }
    _length++;
    return;
  }
}

template <typename K, typename E>
class SortedArray : public Dictionary<K, E> {
 public:
  SortedArray(int initialCapacity) {
    if (initialCapacity < 1) {
      throw IllegalParameterValue("sorted array size must be > 0");
    }
    _capacity = initialCapacity;
    _length = 0;
    _dict = new std::pair<const K, E>*[_capacity];
  }
  bool empty() const { return _length == 0; }
  int size() const { return _length; }
  std::pair<const K, E>* find(const K&) const;
  void erase(const K&);
  void insert(std::pair<const K, E>&);
  template <typename M, typename N>
  friend std::ostream& operator<<(std::ostream& out, SortedArray<M, N>& sarry);

 private:
  std::pair<const K, E>** _dict;
  int _capacity;
  int _length;
};

template <typename K, typename E>
std::ostream& operator<<(std::ostream& out, SortedArray<K, E>& sarry) {
  for (int i = 0; i < sarry._length; ++i) {
    out << sarry._dict[i]->first << ": " << sarry._dict[i]->second << std::endl;
  }
  return out;
}

template <typename K, typename E>
std::pair<const K, E>* SortedArray<K, E>::find(const K& theKey) const {
  for (int i = 0; i < _length; ++i) {
    if (_dict[i]->first == theKey) {
      return _dict[i];
    }
  }
  return nullptr;
}

template <typename K, typename E>
void SortedArray<K, E>::erase(const K& theKey) {
  for (int i = 0; i < _length; ++i) {
    if (_dict[i]->first == theKey) {
      delete _dict[i];
      if (i < _length - 1) {
        std::copy(_dict + i + 1, _dict + _length, _dict + i);
      }
      _length--;
    }
  }
}

template <typename K, typename E>
void SortedArray<K, E>::insert(std::pair<const K, E>& thePair) {
  if (_length == 0) {
    //    _dict[0].first = const_cast<K&>(thePair.first);
    _dict[0] = new std::pair<const K, E>(thePair);
    _length++;
    return;
  }
  for (int i = 0; i < _length; ++i) {
    if (thePair.first == _dict[i]->first) {
      // overwrite the same key-value
      _dict[i]->second = thePair.second;
      return;
    } else if (thePair.first < _dict[i]->first) {
      if (_length + 1 > _capacity) {
        // double capacity
        std::pair<const K, E>** temp =
            new std::pair<const K, E>*[2 * _capacity];
        _capacity *= 2;
        for (int i = 0; i < _length; ++i) {
          temp[i] = _dict[i];
        }
        delete[] _dict;
        _dict = new std::pair<const K, E>*[_capacity];
        for (int i = 0; i < _length; ++i) {
          _dict[i] = temp[i];
        }
        delete[] temp;
      }
      std::copy(_dict + i, _dict + _length, _dict + i + 1);
      _dict[i] = new std::pair<const K, E>(thePair);
      _length++;
      return;
    }
  }
  // append last
  if (_length + 1 > _capacity) {
    // double capacity
    std::pair<const K, E>** temp = new std::pair<const K, E>*[2 * _capacity];
    _capacity *= 2;
    for (int i = 0; i < _length; ++i) {
      temp[i] = new std::pair<const K, E>(_dict[i]->first, _dict[i]->second);
      delete _dict[i];
    }
    delete[] _dict;
    _dict = new std::pair<const K, E>*[_capacity];
    for (int i = 0; i < _length; ++i) {
      _dict[i] = new std::pair<const K, E>(temp[i]->first, temp[i]->second);
      delete temp[i];
    }
    delete[] temp;
  }
  _dict[_length++] = new std::pair<const K, E>(thePair);
  return;
}
