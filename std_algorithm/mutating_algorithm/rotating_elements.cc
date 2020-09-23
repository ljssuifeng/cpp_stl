// ForwardIterator rotate(ForwardIterator beg, ForwardIterator newBeg,
// ForwardIterator end);
// OutputIterator rotate_copy(ForwardIterator beg, ForwardIterator newBeg,
// ForwardIterator sourceEnd,
// OutputIterator destBeg);

#include "algorithm_test.hpp"

int main() {
  std::vector<int> coll;
  INSERT_ELEMENTS(coll, 1, 9);
  PRINT_ELEMENTS(coll, "coll: ");

  // rotate one element to the left
  std::rotate(coll.begin(), coll.begin() + 1, coll.end());
  PRINT_ELEMENTS(coll, "coll: ");

  // rotate two elements to the right
  std::rotate(coll.begin(), coll.end() - 2, coll.end());
  PRINT_ELEMENTS(coll, "two right: ");

  // rotate so that element with value 4 is the beginning
  std::rotate(coll.begin(), std::find(coll.begin(), coll.end(), 4), coll.end());
  PRINT_ELEMENTS(coll, "4 first: ");

  std::set<int> coll_s;
  INSERT_ELEMENTS(coll_s, 1, 9);
  PRINT_ELEMENTS(coll_s);
  // print elements rotated one element to the left
  std::set<int>::const_iterator pos = std::next(coll_s.cbegin());
  std::rotate_copy(coll_s.cbegin(), pos, coll_s.cend(),
                   std::ostream_iterator<int>(std::cout, " "));
  std::cout << std::endl;
  // print elements rotated so that element with value 4 is the beginning
  std::rotate_copy(coll_s.cbegin(), coll_s.find(4), coll_s.cend(),
                   std::ostream_iterator<int>(std::cout, " "));
  std::cout << std::endl;
}
