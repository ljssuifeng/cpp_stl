#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <string>
#include <unordered_set>

template <typename T>
void printElements(T& ob) {
  for (auto& elem : ob) {
    std::cout << elem << ' ';
  }
  std::cout << std::endl;
}

int main() {
  std::unordered_multiset<std::string> cities{
      "Braunschweig", "Hanover", "Frankfurt", "New York",
      "Chicago",      "Toronto", "Paris",     "Frankfurt"};
  for (const auto& elem : cities) {
    std::cout << elem << ' ';
  }
  std::cout << '\n';
  cities.insert({"London", "Munich", "Hanover", "Braunschweig"});

  for (const auto& elem : cities) {
    std::cout << elem << ' ';
  }
  std::cout << '\n';

  std::unordered_set<int> coll = {1, 2, 3, 5, 7, 11, 13, 17, 19, 77};
  // print elements
  // elements are in arbitrary order
  printElements(coll);
  // insert some additional elements
  //-might cause rehashing and create different order
  coll.insert({-7, 17, 33, -11, 17, 19, 1, 13});
  printElements(coll);
  // remove element with specific value
  coll.erase(33);
  // insert sum of all existing values
  coll.insert(std::accumulate(coll.begin(), coll.end(), 0));
  printElements(coll);
  // check if value 19 is in the set
  if (coll.find(19) != coll.end()) {
    std::cout << "19 is available. " << std::endl;
  }
  // remove all negative values
  std::unordered_set<int>::iterator pos;
  for (pos = coll.begin(); pos != coll.end();) {
    if (*pos < 0) {
      pos = coll.erase(pos);
    } else {
      ++pos;
    }
  }
  printElements(coll);
}
