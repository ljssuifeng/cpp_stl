#include <algorithm>
#include <deque>
#include <iostream>
#include <iterator>
#include <string>

int main() {
  std::deque<float> coll;

  for (int i = 1; i <= 6; ++i) {
    coll.push_front(i * 1.1);
  }

  //    for(auto elem:coll) {
  for (int i = 0; i < coll.size(); ++i) {
    std::cout << coll[i] << ' ';
    //        std::cout<<elem<<' ';
  }
  std::cout << std::endl;

  std::deque<std::string> string_coll;
  string_coll.assign(3, std::string("string"));
  string_coll.push_back("last string");
  string_coll.push_front("first string");

  std::copy(string_coll.cbegin(), string_coll.cend(),
            std::ostream_iterator<std::string>(std::cout, "\n"));
  std::cout << std::endl;

  string_coll.pop_front();
  string_coll.pop_back();

  for (unsigned i = 1; i < string_coll.size(); ++i) {
    string_coll.at(i) = "another " + string_coll[i];
  }
  string_coll.resize(4, "resizd string");
  std::copy(string_coll.cbegin(), string_coll.cend(),
            std::ostream_iterator<std::string>(std::cout, "\n"));
  std::cout << std::endl;
}
