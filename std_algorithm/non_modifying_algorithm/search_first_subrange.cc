#include "algorithm_test.hpp"

// ForwardIterator1
// search(ForwardIterator1 beg, ForwardIterator2 end, ForwardIterator2
// searchBeg, ForwardIterator2 searchEnd);

// ForwardIterator1
// search(ForwardIterator1 beg, ForwardIterator2 end, ForwardIterator2
// searchBeg, ForwardIterator2 searchEnd, BinaryPredicate op);

// check whether an element is even or odd
bool checkEven(int elem, bool even) {
  if (even) {
    return even % 2 == 0;
  } else {
    return even % 2 == 1;
  }
}

int main() {
  std::deque<int> coll;
  std::list<int> subcoll;

  INSERT_ELEMENTS(coll, 1, 7);
  INSERT_ELEMENTS(coll, 1, 7);
  INSERT_ELEMENTS(subcoll, 3, 6);

  PRINT_ELEMENTS(coll, "coll: ");
  PRINT_ELEMENTS(subcoll, "subcoll: ");

  // search first occurrence of subcoll in coll
  auto pos =
      std::search(coll.begin(), coll.end(), subcoll.begin(), subcoll.end());
  // loop while subcoll found as subrange of coll
  while (pos != coll.end()) {
    // print position of first element
    std::cout << "subcoll found starting with element "
              << std::distance(coll.begin(), pos) + 1 << std::endl;
    // search next occurance of subcoll
    ++pos;
    pos = std::search(pos, coll.end(), subcoll.begin(), subcoll.end());
  }

  std::vector<int> v_coll;
  INSERT_ELEMENTS(v_coll, 1, 9);
  PRINT_ELEMENTS(v_coll, "v_coll: ");

  // arguments for checkEven()
  // -checkfor: "even odd even"
  bool checkEvenArgs[3] = {true, false, true};

  // check first subrange in v_coll
  std::vector<int>::iterator v_pos;
  v_pos = std::search(v_coll.begin(), v_coll.end(), checkEvenArgs,
                      checkEvenArgs + 3, checkEven);
  // loop while subrange found
  while (v_pos != v_coll.end()) {
    std::cout << "subrange found starting with element "
              << std::distance(v_coll.begin(), v_pos) + 1 << std::endl;
  }
  // search next subrange in v_coll
  v_pos = std::search(++v_pos, v_coll.end(), checkEvenArgs, checkEvenArgs + 3,
                      checkEven);
}
