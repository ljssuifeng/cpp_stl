#include "algorithm_test.hpp"

// ForwardIterator
// search_n(ForwardIterator beg, ForwardIterator end, Size count, const T&
// value);

// ForwardIterator
// search_n(ForwardIterator beg, ForwardIterator end, Size count, const T&
// value, BinaryPredicate op);

int main() {
  std::deque<int> coll;
  coll = {1, 2, 7, 7, 6, 3, 9, 5, 7, 7, 7, 3, 6};
  PRINT_ELEMENTS(coll);

  // find three consecutive elements with value
  std::deque<int>::iterator pos;
  pos = std::search_n(coll.begin(), coll.end(), 3, 7);
  // print result
  if (pos != coll.end()) {
    std::cout << "three consectuive elements with value 7 "
              << "start with " << std::distance(coll.begin(), pos) + 1
              << ". element" << std::endl;
  } else {
    std::cout << "no three consecutive elements with value7 found."
              << std::endl;
  }
  // find four consecutive odd elements
  pos = std::search_n(coll.begin(), coll.end(), 4, 0,
                      [](int elem, int value) { return elem % 2 == 1; });
  // print result
  if (pos != coll.end()) {
    std::cout << "first four consecutive odd elements are: ";
    for (int i = 0; i < 4; ++i, ++pos) {
      std::cout << *pos << ' ';
    }
  } else {
    std::cout << "no four consecutive elements with odd value found.";
  }
  std::cout << std::endl;
}
