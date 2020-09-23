#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

int main() {
  std::vector<int> coll;

  for (int i = 1; i <= 6; ++i) {
    coll.push_back(i);
  }
  std::cout << "vector size: " << coll.size() << std::endl;
  std::cout << "vector max_size: " << coll.max_size() << std::endl;
  std::cout << "vector capacity: " << coll.capacity() << std::endl;
  coll.shrink_to_fit();
  std::cout << "vector capacity: " << coll.capacity() << std::endl;

  //    for(auto elem:coll) {
  for (int i = 0; i < coll.size(); ++i) {
    std::cout << coll[i] << ' ';
    //        std::cout<<elem<<' ';
  }
  std::cout << std::endl;

  //  delete first value: val in coll
  auto pos = std::find(coll.begin(), coll.end(), 5);
  if (pos != coll.end()) {
    coll.erase(pos);
  }

  for (int i = 0; i < coll.size(); ++i) {
    std::cout << coll[i] << ' ';
    std::cout << coll.at(i) << ' ';  // vector.at(idx), if idx is out of range,
                                     // it will throw an exception.
    //        std::cout<<elem<<' ';
  }
  std::cout << std::endl;

  // delete all val==3 in coll
  coll.erase(std::remove(coll.begin(), coll.end(), 3), coll.end());
  for (int i = 0; i < coll.size(); ++i) {
    std::cout << coll[i] << ' ';
    //        std::cout<<elem<<' ';
  }
  std::cout << std::endl;

  //  operate vector as c-array: vector.data()
  std::vector<char> v(41);
  strcpy(v.data(), "hello, world.");
  printf("%s\n", v.data());

  std::vector<std::string> sentence;
  sentence.reserve(5);
  sentence.push_back("hello");
  sentence.insert(sentence.end(), {"how", "are", "you", "?"});
  std::copy(sentence.cbegin(), sentence.cend(),
            std::ostream_iterator<std::string>(std::cout, " "));
  std::cout << std::endl;
  std::cout << "max size(): " << sentence.max_size() << std::endl;
  std::cout << "size(): " << sentence.size() << std::endl;
  std::cout << "capacity(): " << sentence.capacity() << std::endl;

  std::swap(sentence[1], sentence[3]);

  sentence.insert(std::find(sentence.begin(), sentence.end(), "?"), "always");
  sentence.back() = "!";

  std::copy(sentence.cbegin(), sentence.cend(),
            std::ostream_iterator<std::string>(std::cout, " "));
  std::cout << std::endl;
  std::cout << "size(): " << sentence.size() << std::endl;
  std::cout << "capacity(): " << sentence.capacity() << std::endl;

  sentence.pop_back();
  sentence.pop_back();

  sentence.shrink_to_fit();
  std::cout << "size(): " << sentence.size() << std::endl;
  std::cout << "capacity(): " << sentence.capacity() << std::endl;

  std::vector<bool> vbool;
  vbool.reserve(5);
  vbool = {1, 0, 0, 1, 1};
  std::copy(vbool.cbegin(), vbool.cend(),
            std::ostream_iterator<bool>(std::cout, " "));
  std::cout << std::endl;
  vbool.flip();
  std::copy(vbool.cbegin(), vbool.cend(),
            std::ostream_iterator<bool>(std::cout, " "));
  std::cout << std::endl;
  vbool.at(2).flip();
  std::copy(vbool.cbegin(), vbool.cend(),
            std::ostream_iterator<bool>(std::cout, " "));
  std::cout << std::endl;
}
