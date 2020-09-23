// void sort(RandomAccessIterator beg, RandomAccessIterator end);
// void sort(RandomAccessIterator beg, RandomAccessIterator end,
//          BinaryPredicate op);
// void stable_sort(RandomAccessITerator beg, RandomAccessIterator end);
// void stable_sort(RandomAccessITerator beg, RandomAccessIterator end,
//                 BinaryPredicate op);

#include "algorithm_test.hpp"

bool lessLength(const std::string& s1, const std::string& s2) {
  return s1.length() < s2.length();
}

int main() {
  std::deque<int> coll;
  INSERT_ELEMENTS(coll, 1, 9);
  INSERT_ELEMENTS(coll, 1, 9);

  PRINT_ELEMENTS(coll, "on entry: ");
  // sort elements
  std::sort(coll.begin(), coll.end());
  PRINT_ELEMENTS(coll, "sorted: ");
  // sorted reverse
  std::sort(coll.begin(), coll.end(), std::greater<int>());
  PRINT_ELEMENTS(coll, "sorted>:");

  // fill two collection with the same elements
  std::vector<std::string> coll1 = {
      "1xxx",  "2x", "3x", "4x", "5xx",  "6xxxx", "7xx", "8xxx", "9xx",
      "10xxx", "11", "12", "13", "14xx", "15",    "16",  "17"};
  std::vector<std::string> coll2(coll1);
  PRINT_ELEMENTS(coll1, "on entry: \n");
  // sort (according to the length of the strings)
  std::sort(coll1.begin(), coll1.end(), lessLength);
  std::stable_sort(coll2.begin(), coll2.end(), lessLength);
  PRINT_ELEMENTS(coll1, "\nwith sort(): \n");
  PRINT_ELEMENTS(coll2, "\n with stable_sort():\n");
}
