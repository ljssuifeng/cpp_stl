// bool binary_search(ForwardIterator beg, ForwardIterator end, const T& value);
// bool binary_search(ForwardIterator beg, ForwardIterator end, const T& value,
//                   const T& value, BinaryPredicate op);

// bool includes(InputIterator1 beg, InputIterator1 end, InputIterator2
// searchBeg,
//              InputIterator2 searchEnd);
// bool includes(InputIterator1 beg, InputIterator1 end, InputIterator2
// searchBeg,
//              InputIterator2 searchEnd, BinaryPredicate op);

// ForwardIterator lower_bound(ForwardIterator beg, ForwardIterator end,
//                            const T& value);
// ForwardIterator lower_bound(ForwardIterator beg, ForwardIterator end,
//                            const T& value, BinaryPredicate op);
// ForwardIterator upper_bound(ForwardIterator beg, ForwardIterator end,
//                            const T& value);
// ForwardIterator upper_bound(ForwardIterator beg, ForwardIterator end,
//                            const T& value, BinaryPredicate op);

// pair<ForwardIterator, ForwardIterator>
// equal_range(ForwardIterator beg, ForwardIterator end, const T& value);

// pair<ForwardIterator, ForwardIterator>
// equal_range(ForwardIterator beg, ForwardIterator end, const T& value,
// BinaryPredicate op);

#include "algorithm_test.hpp"

int main() {
  std::list<int> coll;

  INSERT_ELEMENTS(coll, 1, 9);
  PRINT_ELEMENTS(coll);

  // check existence of element with value 5
  if (std::binary_search(coll.cbegin(), coll.cend(), 5)) {
    std::cout << "5 is present." << std::endl;
  } else {
    std::cout << "5 is not present." << std::endl;
  }

  // check existence of element with value 42
  if (std::binary_search(coll.cbegin(), coll.cend(), 42)) {
    std::cout << "42 is presend." << std::endl;
  } else {
    std::cout << "42 is not present." << std::endl;
  }

  std::vector<int> search;
  search.push_back(3);
  search.push_back(4);
  search.push_back(7);
  PRINT_ELEMENTS(search, "search: ");

  // check whether all elements in search are also in coll
  if (std::includes(coll.cbegin(), coll.cend(), search.cbegin(),
                    search.cend())) {
    std::cout << "all elements of search are also in coll" << std::endl;
  } else {
    std::cout << "not all elements of search are also in coll." << std::endl;
  }

  coll.clear();
  INSERT_ELEMENTS(coll, 1, 9);
  INSERT_ELEMENTS(coll, 1, 9);
  coll.sort();
  PRINT_ELEMENTS(coll);

  // print first and last position 5 could get inserted
  auto pos1 = std::lower_bound(coll.cbegin(), coll.cend(), 5);
  auto pos2 = std::upper_bound(coll.cbegin(), coll.cend(), 5);
  std::cout << "5 could get position " << std::distance(coll.cbegin(), pos1) + 1
            << " up to " << std::distance(coll.cbegin(), pos2) + 1
            << " without breaking the sorting" << std::endl;
  // insert 3 at the first possible position without breaking the sorting
  coll.insert(std::lower_bound(coll.begin(), coll.end(), 3), 3);
  // insert 7 at the last possible position without breaking the sorting
  coll.insert(std::upper_bound(coll.begin(), coll.end(), 7), 7);
  PRINT_ELEMENTS(coll);

  // print first and last position 5 could get inserted
  std::pair<std::list<int>::const_iterator, std::list<int>::const_iterator>
      range;
  range = std::equal_range(coll.cbegin(), coll.cend(), 5);
  std::cout << "5 could get position "
            << std::distance(coll.cbegin(), range.first) + 1 << " up to "
            << std::distance(coll.cbegin(), range.second) + 1
            << " without breaking the sorting.\n";
}
