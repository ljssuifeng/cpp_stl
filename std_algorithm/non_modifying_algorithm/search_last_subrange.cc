#include "algorithm_test.hpp"

// ForwardIterator find_end(ForwardIterator1 beg, ForwardIterator1 end,
//                         ForwardIterator2 searchBeg,
//                         ForwardIterator2 searchEnd);

// ForwardIterator find_end(ForwardIterator1 beg, ForwardIterator1 end,
//                         ForwardIterator2 searchBeg, ForwardIterator2
//                         searchEnd,
//                         BinaryPredicate op);

int main() {
  std::deque<int> coll;
  std::list<int> subcoll;

  INSERT_ELEMENTS(coll, 1, 7);
  INSERT_ELEMENTS(coll, 1, 7);
  INSERT_ELEMENTS(subcoll, 3, 6);

  PRINT_ELEMENTS(coll, "coll: ");
  PRINT_ELEMENTS(subcoll, "subcoll: ");

  // search last occurance of subcoll in coll
  std::deque<int>::iterator pos;
  pos = std::find_end(coll.begin(), coll.end(), subcoll.begin(), subcoll.end());

  // loop while subcoll found as subrange of coll
  std::deque<int>::iterator end(coll.end());
  while (pos != end) {
    // print position of first element
    std::cout << "subcoll found starting with element "
              << std::distance(coll.begin(), pos) + 1 << std::endl;
    //search next occurance of subcoll
    end = pos;
    pos = std::find_end(coll.begin(), end, subcoll.begin(), subcoll.end());
  }
}
