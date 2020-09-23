#include "algorithm_test.hpp"
#include <algorithm>
#include <deque>
#include <iostream>
#include <vector>

int main() {
  //    std::min_element
  std::vector<int> coll = {2, 5, 4, 1, 6, 3};
  auto min_pos = std::min_element(coll.begin(), coll.end());
  std::cout << "min: " << *min_pos << std::endl;

  //    std::max_element
  auto max_pos = std::max_element(coll.begin(), coll.end());
  std::cout << "max: " << *max_pos << std::endl;

  //  std::sort
  std::sort(coll.begin(), coll.end());
  for (auto& elem : coll) {
    std::cout << elem << ' ';
  }
  std::cout << std::endl;

  //  std::find
  auto pos3 = std::find(coll.begin(), coll.end(), 3);
  std::reverse(pos3, coll.end());
  for (auto& elem : coll) {
    std::cout << elem << ' ';
  }
  std::cout << std::endl;

  std::vector<int> coll2;
  //  coll2.reserve(coll.size());
  coll2.resize(coll.size());
  std::copy(coll.cbegin(), coll.cend(), coll2.begin());
  for (auto& elem : coll2) {
    std::cout << elem << ' ';
  }
  std::cout << std::endl;

  std::deque<int> coll3(coll.size());
  std::copy(coll.begin(), coll.end(), coll3.begin());
  for (auto& elem : coll2) {
    std::cout << elem << ' ';
  }
  std::cout << std::endl;
}
