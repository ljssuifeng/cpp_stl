//// transforming element
// OutputIterator transform(InputIterator sourceBeg, InputIterator sourceEnd,
//                         OutputIterator destBeg, UnaryFunc op);

#include "algorithm_test.hpp"

int main() {
  std::vector<int> coll1;
  std::list<int> coll2;

  INSERT_ELEMENTS(coll1, 1, 9);
  PRINT_ELEMENTS(coll1, "coll1: ");

  // negate all elements in coll1
  std::transform(coll1.cbegin(), coll1.cend(), coll1.begin(),
                 std::negate<int>());
  PRINT_ELEMENTS(coll1, "coll1 negated: ");

  // transform elements of coll1 into coll2 with ten times their value
  std::transform(coll1.cbegin(), coll1.cend(), std::back_inserter(coll2),
                 [](int elem) { return 10 * elem; });
  PRINT_ELEMENTS(coll2, "coll2: ");

  // print coll2 neagtively and in reverse order
  std::transform(coll2.crbegin(), coll2.crend(),
                 std::ostream_iterator<int>(std::cout, " "),
                 [](int elem) { return -elem; });
  std::cout << std::endl;

  //  //combining elements of two sequences
  //  OutputIterator transform(InputIterator1 source1Beg, InputIterator1
  //  source1End,
  //                           InputIterator2 source2Beg,
  //                           OutputIterator destBeg,
  //                           BinaryFunc op);

  coll1.clear();
  coll2.clear();
  INSERT_ELEMENTS(coll1, 1, 9);
  PRINT_ELEMENTS(coll1, "coll1: ");
  // square each element
  std::transform(coll1.cbegin(), coll1.cend(), coll1.cbegin(), coll1.begin(),
                 std::multiplies<int>());
  PRINT_ELEMENTS(coll1, "coll1 squared: ");

  // add each element traversed forward with each element traversed backward
  // and insert result into coll2
  std::transform(coll1.cbegin(), coll1.cend(), coll1.crbegin(),
                 std::back_inserter(coll2), std::plus<int>());
  PRINT_ELEMENTS(coll2, "coll2: ");

  // print differences of two corresponding elements
  std::cout << "diff ";
  std::transform(coll1.cbegin(), coll1.cend(), coll2.cbegin(),
                 std::ostream_iterator<int>(std::cout, " "), std::minus<int>());
  std::cout << std::endl;
}
