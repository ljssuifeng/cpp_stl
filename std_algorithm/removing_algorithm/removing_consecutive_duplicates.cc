// ForwardIterator unique(ForwardIterator beg, ForwardIterator end);
// ForwardIterator unique(ForwardIterator beg, ForwardIterator end,
// BinaryPredicate op);

#include "algorithm_test.hpp"

bool differenceOne(int elem1, int elem2) {
  return elem1 + 1 == elem2 || elem1 - 1 == elem2;
}

bool bothSpaces(char elem1, char elem2) { return elem1 == ' ' && elem2 == ' '; }

int main() {
  int source[]{1, 4, 4, 6, 1, 2, 2, 3, 1, 6, 6, 6, 5, 7, 5, 4, 4};
  std::list<int> coll;
  // initilize coll with elements from source
  std::copy(std::begin(source), std::end(source), std::back_inserter(coll));
  PRINT_ELEMENTS(coll);

  // remove consecutive duplicates
  auto pos = std::unique(coll.begin(), coll.end());
  // print elements with consecutive duplicates removed
  std::unique_copy(coll.cbegin(), coll.cend(),
                   std::ostream_iterator<int>(std::cout, " "));
  std::cout << std::endl;

  // print elements without consecutive entries that differ by one
  std::unique_copy(coll.cbegin(), coll.cend(),
                   std::ostream_iterator<int>(std::cout, " "), differenceOne);
  std::cout << std::endl;

  // don't skip leading whitespaces by default
  std::cin.unsetf(std::ios::skipws);

  // copy standard input to standard output
  //-while compressing spaces
  std::unique_copy(std::istream_iterator<char>(std::cin),
                   std::istream_iterator<char>(),
                   std::ostream_iterator<char>(std::cout), bothSpaces);
  std::cout << std::endl;
}
