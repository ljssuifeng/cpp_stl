#ifndef _ALGORITHM_TEST_
#define _ALGORITHM_TEST_

#include <algorithm>
#include <array>
#include <deque>
#include <forward_list>
#include <functional>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <numeric>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

// INSERT_ELEMETNS(collection, first, last)
//-fill values from from first to last into the collection
//-NOTE: NO half-open range
template <typename T>
inline void INSERT_ELEMENTS(T& coll, int first, int last) {
  for (int i = first; i <= last; ++i) {
    coll.insert(coll.end(), i);
  }
}

// PRINT_ELEMENTS()
//-prints optional string optcstr followed by
//-all elements of the collection coll
//-seperated by spaces
template <typename T>
inline void PRINT_ELEMENTS(const T& coll, const std::string& optcstr = "") {
  std::cout << optcstr;
  for (auto elem : coll) {
    std::cout << elem << ' ';
  }
  std::cout << std::endl;
}

// PRINT_MAPPED_ELEMETNS
//-prints optional string optcstr followed by
//-all elements of the keyvalue collection coll
//-separated by spaces.
template <typename T>
inline void PRINT_MAPPED_ELEMENTS(const T& coll,
                                  const std::string& optcstr = "") {
  std::cout << optcstr;
  for (auto elem : coll) {
    std::cout << "[" << elem.first << ',' << elem.second << "]";
  }
  std::cout << std::endl;
}

#endif
