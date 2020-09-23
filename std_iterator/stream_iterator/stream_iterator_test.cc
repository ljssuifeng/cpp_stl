#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

int main() {
  //    std::vector<std::string> coll;
  //    std::copy(std::istream_iterator<std::string>(std::cin),  // start of
  //    source
  //              std::istream_iterator<std::string>(),          // end of
  //              source
  //              std::back_inserter(coll));                     // destination

  //    std::sort(coll.begin(), coll.end());

  //    std::unique_copy(coll.begin(), coll.end(),
  //                     std::ostream_iterator<std::string>(std::cout, "\n"));
  //    std::cout<<std::endl;

  std::istream_iterator<int> intReader(std::cin);
  std::istream_iterator<int> intReaderEOF;

  while (intReader != intReaderEOF) {
    std::cout << "once:     " << *intReader << std::endl;
    std::cout << "once again:   " << *intReader << std::endl;
    ++intReader;
  }
}
