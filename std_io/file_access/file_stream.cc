#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>

// forward declarations
void writeCharsetToFile(const std::string& filename);
void outputFile(const std::string& filename);

int main() {
  writeCharsetToFile("charset.out");
  outputFile("charset.out");
}

void writeCharsetToFile(const std::string& filename) {
  // open output file
  std::ofstream file(filename);
  // file opened?
  if (!file) {
    // NO, abort program
    std::cerr << "can not open output file\"" << filename << "\"" << std::endl;
    exit(EXIT_FAILURE);
  }
  // write character set
  for (int i = 32; i < 256; ++i) {
    file << "value: " << std::setw(3) << i << " "
         << "char: " << static_cast<char>(i) << std::endl;
  }
}  // closes file automatically

void outputFile(const std::string& filename) {
  // open input file
  std::ifstream file(filename);
  // file opened?
  if (!file) {
    // NO, abort program
    std::cerr << "can not open output file\"" << filename << "\"" << std::endl;
    exit(EXIT_FAILURE);
  }
  // copy file contentsto cout
  char c;
  while (file.get(c)) {
    std::cout.put(c);
  }
}  // closes file automatically
