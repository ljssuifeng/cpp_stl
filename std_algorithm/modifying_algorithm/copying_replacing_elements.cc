// OutputIterator replace_copy(InputIterator sourceBeg, InputIterator sourceEnd,
//                            OutputIterator destBeg, const T& oldValue,
//                            const T& newValue);
// OutputIterator replace_copy_if(InputIterator sourceBeg, InputIterator
// sourceEnd,
//                            OutputIterator destBeg, UnaryPredicate op,
//                            const T& newValue);

#include "algorithm_test.hpp"

int main() {
  std::list<int> coll;
  INSERT_ELEMENTS(coll, 2, 6);
  INSERT_ELEMENTS(coll, 4, 9);
  PRINT_ELEMENTS(coll, "coll: ");

  // print all elements with value replaced with 55
  std::replace_copy(coll.cbegin(), coll.cend(),
                    std::ostream_iterator<int>(std::cout, " "), 5, 55);
  std::cout << std::endl;

  // print all elements with a value less than 5 replaced with 42
  std::replace_copy_if(coll.cbegin(), coll.cend(),
                       std::ostream_iterator<int>(std::cout, " "),
                       [](int elem) { return elem < 5; }, 42);
  std::cout << std::endl;

  // print each element while each odd element is replaced with 0
  std::replace_copy_if(coll.cbegin(), coll.cend(),
                       std::ostream_iterator<int>(std::cout, " "),
                       [](int elem) { return elem % 2 == 1; }, 0);
  std::cout << std::endl;
}
