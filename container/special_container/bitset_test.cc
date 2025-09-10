#include <bitset>

// namespace std {
// template <size_t Bits>
// class bitset;
//}

#include <iostream>
#include <limits>
#include <string>

int main() {
  // enumeration type for the bits
  // -each bit represent a color
  enum Color { red, yellow, green, blue, white, black, numColors };
  // create bitset for all bits/colors
  std::bitset<numColors> usedColors;

  // set bits for two colors
  usedColors.set(red);
  usedColors.set(blue);

  // print some bitset data
  std::cout << "bitfield of used colors:    " << usedColors << std::endl;
  std::cout << "number   of used colors:    " << usedColors.count()
            << std::endl;
  std::cout << "bitfield of unused colors:  " << ~usedColors << std::endl;

  // if any color is used
  if (usedColors.any()) {
    // loop over all colors
    for (int c = 0; c < numColors; ++c) {
      if (usedColors[(Color)c]) {
      }
    }
  }

  // print some number in binary representation
  std::cout << "267 as binary short:    "
            << std::bitset<std::numeric_limits<unsigned short>::digits>(267)
            << std::endl;
  std::cout << "267 as binary long:    "
            << std::bitset<std::numeric_limits<unsigned long>::digits>(267)
            << std::endl;
  std::cout << "10,000,000 with 24 bits: " << std::bitset<24>(1e7) << std::endl;
  // write binary prepresentation into string
  std::string s = std::bitset<42>(12345678).to_string();
  std::cout << "12,345,678 with 42 bits: " << s << std::endl;
  // transform binary representation into integral number
  std::cout << "\"1000101011\" as number:  "
            << std::bitset<100>("1000101011").to_ullong() << std::endl;
}
