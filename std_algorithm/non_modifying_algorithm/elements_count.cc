#include "algorithm_test.hpp"

/**
 * @brief count return count of elements whose value equal to the third
 * parameter:value
 * @param beg
 * @param end
 * @param value
 */
// count(InputIterator beg, InputIterator end, const T& value);

// count_if(InputIterator beg, InputIterator end, UnaryPredicate op);

int main() {
  std::vector<int> coll;
  int num;
  INSERT_ELEMENTS(coll, 1, 9);
  PRINT_ELEMENTS(coll, "coll: ");
  // count elements with value 4
  num = std::count(coll.cbegin(), coll.cend(), 4);
  std::cout << "number of elements equal to 4:   " << num << std::endl;

  // count elements with even value
  num = std::count_if(coll.cbegin(), coll.cend(),
                      [](int elem) { return elem % 2 == 0; });
  std::cout << "number of elements with even value: " << num << std::endl;

  // count elements that are greater than value 4
  num = std::count_if(coll.cbegin(), coll.cend(),
                      [](int elem) { return elem > 4; });
  std::cout << "number of elements greater than 4 : " << num << std::endl;
}
