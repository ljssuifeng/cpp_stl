#include "dictionary.h"
#include <iostream>
#include <string>

int main() {
  SortedChain<std::string, int> dict(10);
  std::pair<const std::string, int> a("first", 1);
  std::pair<const std::string, int> b("second", 2);
  std::pair<const std::string, int> c("third", 3);
  std::pair<const std::string, int> d("first", 11);

  dict.insert(a);
  dict.insert(b);
  dict.insert(c);
  dict.insert(d);
  dict.erase("second");
  std::pair<const std::string, int>* result = dict.find(std::string("third"));
  if (result) {
    std::cout << result->first << ": " << result->second << std::endl;
  }
  result = dict.find(std::string("first"));
  if (result) {
    std::cout << result->first << ": " << result->second << std::endl;
  }

  // test SortedArray
  SortedArray<std::string, int> sa_dict(2);
  sa_dict.insert(a);
  sa_dict.insert(b);
  sa_dict.insert(c);
  sa_dict.insert(d);

  std::pair<const std::string, int> e("girl", 8);
  sa_dict.insert(e);
  std::pair<const std::string, int> f("boy", 9);
  sa_dict.insert(f);

  std::cout << "*******************" << std::endl;
  std::cout << sa_dict << std::endl;
  std::cout << "*******************" << std::endl;

  std::cout << "sa size is: " << sa_dict.size() << std::endl;
  std::cout << sa_dict.find("second")->first << ": "
            << sa_dict.find("second")->second << std::endl;
  sa_dict.erase("second");
  result = sa_dict.find(std::string("third"));
  if (result) {
    std::cout << "sa_dcit: " << result->first << ": " << result->second
              << std::endl;
  }
}
