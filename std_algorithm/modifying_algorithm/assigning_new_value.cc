// void fill(ForwardIterator beg, ForwardIterator end, const T& newValue);
// void fill_n(OutputIterator beg, Size num, const T& newValue);

#include "algorithm_test.hpp"

int main() {
  // print ten times 7.7
  std::fill_n(std::ostream_iterator<float>(std::cout, " "), 10, 7.7);
  std::cout << std::endl;

  std::list<std::string> coll;

  // insert "hello" nine times
  fill_n(back_inserter(coll), 9, "hello");
  PRINT_ELEMENTS(coll, "coll: ");

  // overwrite all elements with "again"
  std::fill(coll.begin(), coll.end(), "again");
  PRINT_ELEMENTS(coll, "coll: ");

  // replace all but two elements with "hi"
  std::fill_n(coll.begin(), coll.size() - 2, "hi");
  PRINT_ELEMENTS(coll, "coll: ");

  // replace the second and upto the last element but one with "hmmm"
  std::list<std::string>::iterator pos1, pos2;
  pos1 = coll.begin();
  pos2 = coll.end();
  std::fill(++pos1, --pos2, "hmmm");
  PRINT_ELEMENTS(coll, "coll: ");
}
