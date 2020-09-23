#include "algorithm_test.hpp"

// ForwardIterator
// adjacent_find(ForIterator beg, ForwardIterator end);

// ForwardIterator
// adjacent_find(ForIterator beg, ForwardIterator end, BinaryPredicate op);

// return whether the second object has double the value of the first
bool doubled(int elem1, int elem2) { return elem1 * 2 == elem2; }

int main() {
  std::vector<int> coll = {1, 3, 2, 4, 5, 5, 0};
  PRINT_ELEMENTS(coll, "coll: ");

  // search first two elements with equal value
  auto pos = std::adjacent_find(coll.begin(), coll.end());
  if (pos != coll.end()) {
    std::cout << "first two elements with equal value have position "
              << std::distance(coll.begin(), pos) + 1 << std::endl;
  }
  // search first two elements for which the second has double the value of the
  // first
  pos = std::adjacent_find(coll.begin(), coll.end(), doubled);
  if (pos != coll.end()) {
    std::cout << "first two elements with second value twice the "
              << "first hav pos." << std::distance(coll.begin(), pos) + 1
              << std::endl;
  }
}
