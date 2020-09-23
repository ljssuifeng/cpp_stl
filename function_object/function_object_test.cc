#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

class PrintInt {
 public:
  void operator()(int elem) { std::cout << elem << ' '; }
};

int main() {
  std::vector<int> coll;
  for (int i = 1; i <= 9; ++i) {
    coll.push_back(i);
  }
  std::for_each(coll.cbegin(), coll.cend(), PrintInt());
  std::cout << std::endl;

  //  lambda function
  std::for_each(coll.cbegin(), coll.cend(),
                [](int elem) { std::cout << elem << ' '; });
  std::cout << std::endl;
}
