#include <array>
#include <iostream>
#include <string>

int main() {
  std::array<std::string, 5> coll = {"hello", "world"};

  std::cout << "coll size: " << coll.size() << std::endl;
  std::cout << "coll max_size: " << coll.max_size() << std::endl;
  std::cout << "coll front elem: " << coll.front() << std::endl;
  std::cout << "coll back elem: " << coll.back() << std::endl;  // return ""
  //    coll.fill("hello");
  //    for(auto elem:coll) {
  for (int i = 0; i < coll.size(); ++i) {
    std::cout << i << ":" << coll[i] << std::endl;
    //        std::cout<<elem<<' ';
  }
}
