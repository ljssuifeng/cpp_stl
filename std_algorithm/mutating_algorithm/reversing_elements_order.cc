// void reverse(BidirectionalIterator beg, BidirectionalIterator end);
// OutputIterator reverse_copy(BidirectionalIterator sourceBeg,
//                            BidirectionalIterator sourceEnd,
//                            OutputIterator destBeg);

#include "algorithm_test.hpp"

int main() {
  std::vector<int> coll;
  INSERT_ELEMENTS(coll, 1, 9);
  PRINT_ELEMENTS(coll, "coll: ");

  // reverse order of elements
  std::reverse(coll.begin(), coll.end());
  PRINT_ELEMENTS(coll, "coll reverse: ");

  // reverse order from second to last element but one
  std::reverse(coll.begin() + 1, coll.end() - 1);
  PRINT_ELEMENTS(coll, "coll: ");

  // print all of them in reverse order
  std::reverse_copy(coll.begin(), coll.end(),
                    std::ostream_iterator<int>(std::cout, " "));
  std::cout << std::endl;
}
