// void make_heap(RandomAccessIterator beg, RandomAccessIterator end);
// void make_heap(RandomAccessIterator beg, RandomAccessIterator end,
//               BinaryPredicate op);

// void push_heap(RandomAccessIterator beg, RandomAccessIterator end);
// void push_heap(RandomAccessIterator beg, RandomAccessIterator end,
//               BinaryPredicate op);
// void pop_heap(RandomAccessIterator beg, RandomAccessIterator end);
// void pop_heap(RandomAccessIterator beg, RandomAccessIterator end,
//              BinaryAccessIterator op);
// void sort_heap(RandomAccessIterator beg, RandomAccessIterator end);
// void sort_heap(RandomAccessIterator beg, RandomAccessIterator end,
//               BinaryPredicate op);

#include "algorithm_test.hpp"

int main() {
  std::vector<int> coll;
  INSERT_ELEMENTS(coll, 3, 7);
  INSERT_ELEMENTS(coll, 5, 9);
  INSERT_ELEMENTS(coll, 1, 4);

  PRINT_ELEMENTS(coll, "on entry: ");
  // convert collection into a heap
  std::make_heap(coll.begin(), coll.end());
  PRINT_ELEMENTS(coll, "after make_heap(): ");
  // pop next element out of the heap
  pop_heap(coll.begin(), coll.end());
  coll.pop_back();
  PRINT_ELEMENTS(coll, "after pop_heap(): ");

  // push new element into the heap
  coll.push_back(17);
  std::push_heap(coll.begin(), coll.end());

  PRINT_ELEMENTS(coll, "after push_heap(): ");
  // convert heap into a sorted collection
  //-NOTE: after the call it is no longer a heap
  std::sort_heap(coll.begin(), coll.end());
  PRINT_ELEMENTS(coll, "after sort_heap: ");
}
