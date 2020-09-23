// OutputIterator merge(InputIterator source1Beg, InputIterator source1End,
//                     InputIterator source2Beg, InputIterator source2End,
//                     OutputIterator destBeg);
// OutputIterator merge(InputIterator source1Beg, InputIterator source1End,
//                     InputIterator source2Beg, InputIterator source2End,
//                     OutputIterator destBeg, BinaryPredicate op);

// OutputIterator set_union(InputIterator source1Beg, InputIterator source1End,
//                         InputIterator source2Beg, InputIterator source2End,
//                         OutputIterator destBeg);

// OutputIterator set_union(InputIterator source1Beg, InputIterator source1End,
//                         InputIterator source2Beg, InputIterator source2End,
//                         OutputIterator destBeg, BinaryPredicate op);

// OutputIterator set_intersection(InputIterator source1Beg,
//                                InputIterator source1End,
//                                InputIterator source2Beg,
//                                InputIterator source2End, OputIterator
//                                destBeg);
// OutputIterator set_intersection(InputIterator source1Beg,
//                                InputIterator source1End,
//                                InputIterator source2Beg,
//                                InputIterator source2End, OputIterator
//                                destBeg,
//                                BinaryPredicate op);

// OutputIterator set_difference(InputIterator source1Beg,
//                              InputIterator source1End,
//                              InputIterator source2Beg,
//                              InputIterator source2End, OutputIterator
//                              destBeg);
// OutputIterator set_difference(InputIterator source1Beg,
//                              InputIterator source1End,
//                              InputIterator source2Beg,
//                              InputIterator source2End, OutputIterator
//                              destBeg,
//                              BinaryPredicate op);

// OutputIterator set_symmetric_difference(InputIterator source1Beg,
//                                        InputIterator source1End,
//                                        InputIterator source2Beg,
//                                        InputIterator source2End,
//                                        OutputIterator destBeg);
// OutputIterator set_symmetric_difference(InputIterator source1Beg,
//                                        InputIterator source1End,
//                                        InputIterator source2Beg,
//                                        InputIterator source2End,
//                                        OutputIterator destBeg,
//                                        BinaryPredicate op);

// void inplace_merge(BidirectionalIterator beg1, BidirectionalIterator
// end1beg2,
//                   BidirectionalIterator end2);
// void inplace_merge(BidirectionalIterator beg1, BidirectionalIterator
// end1beg2,
//                   BidirectionalIterator end2, BinaryPredicate op);

#include "algorithm_test.hpp"

int main() {
  std::list<int> coll1;
  std::set<int> coll2;

  // fill both collection with some sorted elements
  INSERT_ELEMENTS(coll1, 1, 6);
  INSERT_ELEMENTS(coll2, 3, 8);
  PRINT_ELEMENTS(coll1, "coll1: ");
  PRINT_ELEMENTS(coll2, "coll2: ");

  // print merged sequence
  std::cout << "merged: ";
  std::merge(coll1.cbegin(), coll1.cend(), coll2.cbegin(), coll2.cend(),
             std::ostream_iterator<int>(std::cout, " "));
  std::cout << std::endl;

  // print set_union sequence
  std::cout << "set_union ";
  std::set_union(coll1.cbegin(), coll1.cend(), coll2.cbegin(), coll2.cend(),
                 std::ostream_iterator<int>(std::cout, " "));
  std::cout << std::endl;

  // print set_intersection sequence
  std::cout << "set_intersection ";
  std::set_intersection(coll1.cbegin(), coll1.cend(), coll2.cbegin(),
                        coll2.cend(),
                        std::ostream_iterator<int>(std::cout, " "));
  std::cout << std::endl;

  // print set_difference sequence
  std::cout << "set_difference ";
  std::set_difference(coll1.cbegin(), coll1.cend(), coll2.cbegin(),
                      coll2.cend(), std::ostream_iterator<int>(std::cout, " "));
  std::cout << std::endl;

  // print set_symmetric_difference sequence
  std::cout << "set_symmetric_difference ";
  std::set_symmetric_difference(coll1.cbegin(), coll1.cend(), coll2.cbegin(),
                                coll2.cend(),
                                std::ostream_iterator<int>(std::cout, " "));
  std::cout << std::endl;

  std::list<int> coll_inplace;
  INSERT_ELEMENTS(coll_inplace, 1, 7);
  INSERT_ELEMENTS(coll_inplace, 1, 8);
  PRINT_ELEMENTS(coll_inplace);

  // find beginning of second part (element after 7)
  std::list<int>::iterator pos;
  pos = std::find(coll_inplace.begin(), coll_inplace.end(), 7);
  if (pos != coll_inplace.end()) {
    ++pos;
    // merge into one sorted range
    std::inplace_merge(coll_inplace.begin(), pos, coll_inplace.end());
    PRINT_ELEMENTS(coll_inplace);
  }
}
