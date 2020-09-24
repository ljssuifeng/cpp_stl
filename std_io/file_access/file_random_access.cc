#include <fstream>
#include <iostream>

////seek to the beginning ot the file
// file.seekg(0, std::ios::beg);
////seek 20 characters forward
// file.seekg(20, std::ios::beg);
////seek 10 characters before the end.
// file.seekg(-10, std::ios::end);

void printFileTwice(const char* filename) {
  // open file
  std::ifstream file(filename);
  // print contents the first time
  std::cout << file.rdbuf();
  // seek to the beginning
  file.seekg(0);
  // print contents the second time
  std::cout << file.rdbuf();
}

int main(int argc, char* argv[]) {
  // print all files passed as a command-line argument twice
  for (int i = 1; i < argc; ++i) {
    printFileTwice(argv[i]);
  }
}
