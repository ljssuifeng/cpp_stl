#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

int main() {
  std::vector<int> coll;
  for (int i = 1; i <= 9; ++i) {
    coll.push_back(i);
  }
  std::copy(coll.crbegin(), coll.crend(),
            std::ostream_iterator<int>(std::cout, " "));
  std::cout << std::endl;
}
