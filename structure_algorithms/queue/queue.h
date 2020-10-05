#include <sstream>
#include "structure_algorithms/linked_list/chain.h"
#include "structure_algorithms/my_exceptions.h"

template <typename T>
class Queue {
 public:
  virtual ~Queue() = default;
  virtual bool empty() const = 0;
  virtual int size() const = 0;
  virtual T& front() = 0;
  virtual T& back() = 0;
  virtual void pop() = 0;  // delete front element
  virtual void push(
      const T& theElement) = 0;  // add element to the back of queue
};

template <typename T>
class ArrayQueue : Queue<T> {
 public:
  ArrayQueue(int initialCapacity = 10);
  ~ArrayQueue() { delete[] _queue; }
  bool empty() const { return _theFront == _theBack; }
  int size() const {
    return (_theBack - _theFront + _arrayLength) % _arrayLength;
  }
  T& front() {
    if (empty()) {
      throw QueueEmpty();
    }
    return _queue[(_theFront + 1) % _arrayLength];
  }
  T& back() {
    if (empty()) {
      throw QueueEmpty();
    }
    return _queue[_theBack];
  }
  void pop() {
    // remove the front element
    if (empty()) {
      throw QueueEmpty();
    }
    _theFront = (_theFront + 1) % _arrayLength;
    _queue[_theFront].~T();
  }
  void push(const T& theElement);

 private:
  T* _queue;
  int _theFront;  // before the index of queue front element
  int _theBack;   // index of queue back element
  int _arrayLength;
};

template <typename T>
ArrayQueue<T>::ArrayQueue(int initialCapacity) {
  // constructor
  if (initialCapacity < 1) {
    std::ostringstream os;
    os << "Initial capacity = " << initialCapacity << " Must be > 0.";
    throw IllegalParameterValue(os.str());
  }
  _arrayLength = initialCapacity;
  _queue = new T[_arrayLength];
  _theFront = 0;
  _theBack = 0;
}

template <typename T>
void ArrayQueue<T>::push(const T& theElement) {
  // add element to queue
  // increase array length if necessary
  if ((_theBack + 1) % _arrayLength == _theFront) {
    T* newQueue = new T[2 * _arrayLength];
    // copy elements into new array
    int start = (_theFront + 1) % _arrayLength;
    if (start < 2) {
      // no wrap around
      std::copy(_queue + start, _queue + start + _arrayLength - 1, newQueue);
    } else {
      // queue was wrapped
      std::copy(_queue + start, _queue + _arrayLength, newQueue);
      std::copy(_queue, _queue + _theBack + 1, newQueue + _arrayLength - start);
    }
    // switch to new queue and set _theFront and _theBack
    _theFront = 2 * _arrayLength - 1;
    _theBack = _arrayLength - 2;  // queue size = _arrayLength - 1, it is full
    _arrayLength *= 2;
    _queue = newQueue;
  }
  // put theElement at _theBack of the queue
  _theBack = (_theBack + 1) % _arrayLength;
  _queue[_theBack] = theElement;
}

template <typename T>
class LinkedQueue : public Queue<T> {
 public:
  LinkedQueue(int initialCapacity = 10);
  ~LinkedQueue();
  bool empty() const { return _queueSize == 0; }
  int size() const { return _queueSize; }
  T& front() {
    if (empty()) {
      throw QueueEmpty();
    }
    return _queueFront->_element;
  }
  T& back() {
    if (empty()) {
      throw QueueEmpty();
    }
    return _queueBack->_element;
  }

  void pop();
  void push(const T& theElement);

 private:
  ChainNode<T>* _queueFront;
  ChainNode<T>* _queueBack;
  int _queueSize;
};

template <typename T>
LinkedQueue<T>::LinkedQueue(int initialCapacity) {
  _queueBack = nullptr;
  _queueFront = nullptr;
  _queueSize = 0;
}

template <typename T>
LinkedQueue<T>::~LinkedQueue() {
  while (_queueFront != nullptr) {
    ChainNode<T>* nextNode = _queueFront->_next;
    delete _queueFront;
    _queueFront = nextNode;
  }
}

template <typename T>
void LinkedQueue<T>::pop() {
  if (!_queueFront) {
    throw QueueEmpty();
  }
  ChainNode<T>* nextNode = _queueFront->_next;
  delete _queueFront;
  _queueFront = nextNode;
  _queueSize--;
}

template <typename T>
void LinkedQueue<T>::push(const T& theElement) {
  ChainNode<T>* newNode = new ChainNode<T>(theElement, nullptr);
  if (_queueSize == 0) {
    _queueFront = newNode;
  } else {
    _queueBack->_next = newNode;
  }
  _queueBack = newNode;
  _queueSize++;
}
