#include "algorithm_test.hpp"

// InputIterator
// find(InputIterator beg, InputIterator end, const T& value);

// InputIterator
// find_if(InputIterator beg, InputIterator end, UnaryPredicate op);

// InputIterator
// find_if_not(InputIterator beg, InputIterator end, UnaryPredicate op);

// note : if container is sorted,
//       we should use
//       lower_bound(),
//       upper_bound(),
//       equal_range() or binary_search(),
//       these functions would be much faster

// note2: associative and unordered container provide a member-function find(),
// which runs fast.

int main() {
  std::list<int> coll;
  INSERT_ELEMENTS(coll, 1, 9);
  INSERT_ELEMENTS(coll, 1, 9);
  PRINT_ELEMENTS(coll);

  // find first element with value 4
  std::list<int>::iterator pos1;
  pos1 = std::find(coll.begin(), coll.end(), 4);

  // find second element with value 4
  // -note: continue the search behind the first 4(if any)
  std::list<int>::iterator pos2;
  pos2 = std::find(coll.begin(), coll.end(), 4);
  if (pos1 != coll.end()) {
    pos2 = std::find(++pos1, coll.end(), 4);
  }

  // print all elements from first to second 4 (both include)
  // -note: now we need the position of the first 4 again (if any)
  if (pos1 != coll.end() && pos2 != coll.end()) {
    std::copy(--pos1, ++pos2, std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;
  }

  // find first element greater than 3
  pos1 = std::find_if(coll.begin(), coll.end(),
                      [](int element) { return element > 3; });
  // print its position
  std::cout << "the " << std::distance(coll.begin(), pos1) + 1
            << ". element is the first greater than 3" << std::endl;

  // find first element divisible by 3
  pos2 = std::find_if(coll.begin(), coll.end(),
                      [](int elem) { return elem % 3 == 0; });
  // print its position
  std::cout << "the " << std::distance(coll.begin(), pos2) + 1
            << ". element is the first divisible by 3" << std::endl;

  // find first element not <5
  pos2 = std::find_if_not(coll.begin(), coll.end(),
                          [](int elem) { return elem < 5; });
  std::cout << "first value >=5: " << *pos2 << std::endl;
}
