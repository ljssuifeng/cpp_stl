// pair<OutputIterator1, OutputIterator2> partition_copy(
//    InputIterator sourceBeg, InputIterator sourceEnd,
//    OutputIterator1 destTrueBeg, OutputIterator2 destFalseBeg,
//    UnaryPredicate op);

#include "algorithm_test.hpp"

int main() {
  std::vector<int> coll = {1, 6, 33, 7, 22, 4, 11, 33, 2, 7, 0, 42, 5};
  PRINT_ELEMENTS(coll, "coll: ");
  // destination collections:
  std::vector<int> evenColl;
  std::vector<int> oddColl;

  // copy all elements partitionedaccordingly into even and odd elements
  std::partition_copy(coll.cbegin(), coll.cend(), std::back_inserter(evenColl),
                      std::back_inserter(oddColl),
                      [](int elem) { return elem % 2 == 0; });
  PRINT_ELEMENTS(evenColl, "evenColl: ");
  PRINT_ELEMENTS(oddColl, "oddColl: ");

}
