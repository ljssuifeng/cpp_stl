#include <exception>
#include <iostream>
#include <limits>
#include <string>

int main() {
  try {
    // convert to numeric type
    std::cout << std::stoi("  77") << std::endl;
    std::cout << std::stoi("  77.7") << std::endl;
    std::cout << std::stoi("  -0x77") << std::endl;

    // use index of characters ont processed
    std::size_t idx;
    std::cout << std::stoi("  42 is the truth", &idx) << std::endl;
    std::cout << "idx of first unprocessed char: " << idx << std::endl;

    // use bases 16 and 8
    std::cout << std::stol(" 42 ", nullptr, 16) << std::endl;
    std::cout << std::stol("789 ", &idx, 8) << std::endl;
    std::cout << "idx of first unprocessed char:  " << idx << std::endl;

    // convert numeric value to string
    long long ll = std::numeric_limits<long long>::max();
    std::string s = std::to_string(ll);
    std::cout << s << std::endl;

    // try to convert back
    std::cout << std::stoi(s) << std::endl;
  } catch (const std::exception& e) {
    std::cerr << e.what() << std::endl;
  }
}
