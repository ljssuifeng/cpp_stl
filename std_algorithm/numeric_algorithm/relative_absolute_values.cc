// OutputIterator partial_sum(InputIterator sourceBeg, InputIterator sourceEnd,
// OutputIterator destBeg);
//OutputIterator partial_sum(InputIterator sourceBeg, InputIterator sourceEnd, OutputIterator destBeg, BinaryFunc op);\

// OutputIterator adjacent_difference(InputIterator sourceBeg,
//                                   InputIterator sourceEnd,
//                                   OutputIterator destBeg);

// OutputIterator adjacent_difference(InputIterator sourceBeg,
//                                   InputIterator sourceEnd,
//                                   OutputIterator destBeg, BinaryFunc op);

#include "algorithm_test.hpp"

int main() {
  std::vector<int> coll;
  INSERT_ELEMENTS(coll, 1, 6);
  PRINT_ELEMENTS(coll);

  // print all partial sums
  std::partial_sum(coll.cbegin(), coll.cend(),
                   std::ostream_iterator<int>(std::cout, " "));
  std::cout << std::endl;

  // print all partial products
  std::partial_sum(coll.cbegin(), coll.cend(),
                   std::ostream_iterator<int>(std::cout, " "),
                   std::multiplies<int>());
  std::cout << std::endl;

  // print differences between elements
  std::adjacent_difference(coll.cbegin(), coll.cend(),
                           std::ostream_iterator<int>(std::cout, " "));
  std::cout << std::endl;

  // print all sums with the predecessors
  std::adjacent_difference(coll.cbegin(), coll.cend(),
                           std::ostream_iterator<int>(std::cout, " "),
                           std::plus<int>());
  std::cout << std::endl;

  // print all sums with the predecessors
  std::adjacent_difference(coll.cbegin(), coll.cend(),
                           std::ostream_iterator<int>(std::cout, " "),
                           std::multiplies<int>());
  std::cout << std::endl;
}
