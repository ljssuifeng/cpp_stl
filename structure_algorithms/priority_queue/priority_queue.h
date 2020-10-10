#include <algorithm>
#include <iostream>
#include <iterator>
#include <sstream>
#include "structure_algorithms/my_exceptions.h"

template <typename T>
void changeLength1D(T*& old_ptr, int oldLength, int newLength) {
  T* new_ptr = new T[newLength];
  int length = std::min(oldLength, newLength);
  std::copy(old_ptr, old_ptr + length, new_ptr);
  delete[] old_ptr;
  old_ptr = new_ptr;
}

template <typename T>
class maxPriorityQueue {
 public:
  virtual ~maxPriorityQueue() {}
  virtual int size() const = 0;
  virtual const T& top() = 0;
  virtual void pop() = 0;
  virtual void push(const T& theElement) = 0;
};

template <typename T>
class MaxHeap : public maxPriorityQueue<T> {
 public:
  MaxHeap(int initialCapacity = 10);
  ~MaxHeap() { delete[] heap; }

  bool empty() const { return heapSize == 0; }
  int size() const { return heapSize; }
  const T& top() {
    // return max element
    if (heapSize == 0) {
      throw QueueEmpty();
    }
    return heap[1];
  }
  void pop();
  void push(const T& theElement);
  void initialize(T*&, int);
  void deactivateArray() {
    heap = nullptr;
    arrayLength = heapSize = 0;
  }
  void output(std::ostream& out) const;

 private:
  int heapSize;
  int arrayLength;
  T* heap;
};

template <typename T>
MaxHeap<T>::MaxHeap(int initialCapacity) {
  // constructor
  if (initialCapacity < 1) {
    std::ostringstream ss;
    ss << "Initial capacity = " << initialCapacity << "Must be > 0";
    throw IllegalParameterValue(ss.str());
  }
  arrayLength = initialCapacity + 1;
  heap = new T[arrayLength];
  heapSize = 0;
}

template <typename T>
void MaxHeap<T>::push(const T& theElement) {
  // add theElement to heap
  // increase array length if necessary
  if (heapSize == arrayLength - 1) {
    // double array length
    changeLength1D<T>(heap, arrayLength, 2 * arrayLength);
    arrayLength *= 2;
  }
  // find place for theElement
  // currentNode starts at new leaf and moves up tree
  int currentNode = ++heapSize;
  while (currentNode != 1 && heap[currentNode / 2] < theElement) {
    // cannot put theELement in heap[currentNode]
    heap[currentNode] = heap[currentNode / 2];  // move element down
    currentNode /= 2;
  }
  heap[currentNode] = theElement;
}

template <typename T>
void MaxHeap<T>::pop() {
  // remove max element
  // if heap is empty, return nullptr
  if (heapSize == 0) {
    return;
  }
  // delete max element
  heap[1].~T();
  // remove last element and reheapify
  T lastElement = heap[heapSize--];
  // find place for lastElement starting at root
  int currentNode = 1;
  int child = 2;
  while (child <= heapSize) {
    // heap[child] should be larger child of currentNode
    if (child < heapSize && heap[child] < heap[child + 1]) {
      child++;
    }
    // can we put lastElement in heap[currentNode]?
    if (lastElement >= heap[child]) {
      break;
    }
    // no
    heap[currentNode] = heap[child];  // move child up
    currentNode = child;
    child *= 2;
  }
  heap[currentNode] = lastElement;
}

template <typename T>
void MaxHeap<T>::initialize(T*& theHeap, int theSize) {
  // initilize max heap to element array theHeap[1:theSize]
  delete[] heap;
  heap = theHeap;
  heapSize = theSize;

  // heapify
  for (int root = heapSize / 2; root >= 1; root--) {
    T rootElement = heap[root];
    // find place to put rootElement
    int child = root * 2;  // parent of child is target location
                           // for rootElement
    while (child <= heapSize) {
      // heap[child] should be larger sibling
      if (child < heapSize && heap[child] < heap[child + 1]) {
        child++;
      }
      // can we put rootElement in heap[child/2]?
      if (rootElement >= heap[child]) {
        break;  // yes
      }
      // no
      heap[child / 2] = heap[child];  // move child up
      child *= 2;
    }
    heap[child / 2] = rootElement;
  }
}

template <typename T>
void MaxHeap<T>::output(std::ostream& out) const {
  // put the list into the stream out.
  std::copy(heap + 1, heap + heapSize + 1,
            std::ostream_iterator<T>(std::cout, " "));
  std::cout << std::endl;
}

template <typename T>
std::ostream& operator<<(std::ostream& out, const MaxHeap<T>& x) {
  x.output(out);
  return out;
}
