#include <iostream>
#include <string>

int main(int argc, char** argv) {
  const std::string delims(" \t,.;");
  std::string line;
  // for every line read successful
  while (std::getline(std::cin, line)) {
    std::string::size_type begIdx, endIdx;
    // search begining of the first word
    begIdx = line.find_first_not_of(delims);
    // while begining of a word found
    while (begIdx != std::string::npos) {
      // search end of the actual word
      endIdx = line.find_first_of(delims, begIdx);
      if (endIdx == std::string::npos) {
        // end of word is end of line
        endIdx = line.length();
      }
      // print characters in reverse order
      for (int i = endIdx - 1; i >= static_cast<int>(begIdx); --i) {
        std::cout << line[i];
      }
      std::cout << ' ';
      // search beginning of the next word
      begIdx = line.find_first_not_of(delims, endIdx);
    }
    std::cout << std::endl;
  }
}
