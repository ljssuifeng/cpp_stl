#include "algorithm_test.hpp"

// bool is_heap(RandomAccessIterator beg, RandomAccessIterator end);
// bool is_heap(RandomAccessIterator beg, RandomAccessIterator end,
//             BinaryPredicate op);
// RandomAccessIterator is_heap_until(RandomAccessIterator beg,
//                                   RandomAccessIterator end);
// RandomAccessIterator is_heap_until(RandomAccessIterator beg,
//                                   RandomAccessIterator end,
//                                   BinaryPredicate op);

int main() {
  std::vector<int> coll1 = {9, 8, 7, 7, 7, 5, 4, 2, 1};
  std::vector<int> coll2 = {5, 3, 2, 1, 4, 7, 9, 8, 6};
  PRINT_ELEMENTS(coll1, "coll1: ");
  PRINT_ELEMENTS(coll2, "coll2: ");

  // check whethre the collections are heaps
  std::cout << std::boolalpha
            << "coll is heap: " << std::is_heap(coll1.cbegin(), coll1.cend())
            << std::endl;
}
