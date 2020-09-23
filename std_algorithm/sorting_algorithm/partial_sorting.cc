// void partial_sort(RandomAccessIterator beg, RandomAccessIterator sortEnd,
//                  RandomAccessIterator end);
// void partial_sort(RandomAccessIterator beg, RandomAccessIterator sortEnd,
//                  RandomAccessIterator end, BinaryPredicate op);

#include "algorithm_test.hpp"

int main() {
  std::deque<int> coll;
  INSERT_ELEMENTS(coll, 3, 7);
  INSERT_ELEMENTS(coll, 2, 6);
  INSERT_ELEMENTS(coll, 1, 5);
  PRINT_ELEMENTS(coll);

  // sort until the first five element are sorted
  std::partial_sort(coll.begin(), coll.begin() + 5, coll.end());
  PRINT_ELEMENTS(coll);

  // sort inversely until the first five elements are sorted
  std::partial_sort(coll.begin(), coll.begin() + 5, coll.end(),
                    std::greater<int>());
  PRINT_ELEMENTS(coll);

  // sort all elements
  std::partial_sort(coll.begin(), coll.end(), coll.end());
  PRINT_ELEMENTS(coll);
}
