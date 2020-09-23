// bool next_permutation(BidirectionalIterator beg, BidirectionalIterator end);
// bool next_permutation(BidirectionalIterator beg, BidirectionalIterator end,
// BinaryPredicate op);
// bool prev_permutation(BidirectionalIterator beg, BidirectionalIterator end);
// bool prev_permutation(BidirectionalIterator beg, BidirectionalIterator end,
// BinaryPredicate op);

#include "algorithm_test.hpp"

int main() {
std:
  std::vector<int> coll;
  INSERT_ELEMENTS(coll, 1, 3);
  PRINT_ELEMENTS(coll, "on entry: ");

  // permute elements until they are sorted
  //-runs through all permutations because the elements are sorted now
  while (std::next_permutation(coll.begin(), coll.end())) {
    PRINT_ELEMENTS(coll, " ");
  }
  PRINT_ELEMENTS(coll, "afterward: ");

  // permute until descending sorted
  //-this is the next permutation after ascending sorting
  //-so the loop ends immediately
  while (std::prev_permutation(coll.begin(), coll.end())) {
    PRINT_ELEMENTS(coll, " ");
  }
  PRINT_ELEMENTS(coll, "now: ");

  // permute elements until they are sorted in descending order
  //-runs through all permutations because the elements are sorted in descending
  //order now
  while (std::prev_permutation(coll.begin(), coll.end())) {
    PRINT_ELEMENTS(coll, " ");
  }
  PRINT_ELEMENTS(coll, "afterward: ");
}
