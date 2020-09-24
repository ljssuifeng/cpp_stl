#include <iostream>

int main() {
  char c;
  // while it is possible to read a character
  while (std::cin.get(c)) {
    // print it
    std::cout.put(c);
//    std::cout.flush();
  }
}
