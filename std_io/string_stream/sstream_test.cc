#include <bitset>
#include <iostream>
#include <sstream>
#include <tuple>
#include <utility>
#include <string>

std::tuple<std::string, std::string, std::string> parseName(std::string name) {
    std::string s1, s2, s3;
    std::istringstream(name) >> s1 >> s2 >> s3;
    if(s3.empty()) {
        return std::tuple<std::string, std::string, std::string>(std::move(s1), "", std::move(s2));
    } else {
        return std::tuple<std::string, std::string, std::string>(std::move(s1), std::move(s2), std::move(s3));
    }
}


int main() {
  std::ostringstream os;
  // decimal and hexadecimal value
  os << "dec: " << 15 << std::hex << " hex: " << 15 << std::endl;
  std::cout << os.str() << std::endl;

  // append floating value and bitset
  std::bitset<15> b(5789);
  os << "float: " << 4.67 << "bitset: " << b << std::endl;
  // overwrite with octal value
  os.seekp(0);
  os << "oct: " << std::oct << 15;
  std::cout << os.str() << std::endl;

  int x;
  float f;
  std::string s = "3.7";
  std::istringstream is(s);
  is >> x >> f;
  std::cout << "x: " << x << " f:" << f << std::endl;
  is.seekg(0);
  is >> f;
  std::cout << "f: " << f << std::endl;

  std::string ss("value: ");
  std::ostringstream oss(ss, std::ios::out | std::ios::ate);
  oss << 77 << " " << std::hex << 77 << std::endl;
  std::cout << oss.str();
  std::cout << ss << std::endl;


  auto t1 = parseName("Nicolai M. Josuttis");
  std::cout<<"firstname: " << std::get<0>(t1) <<std::endl;
  std::cout<<"middle: " << std::get<1>(t1) <<std::endl;
  std::cout<<"lastname: " << std::get<2>(t1) <<std::endl;
  auto t2 = parseName("Nico Josuttis");
  std::cout<<"firstname: " << std::get<0>(t2) <<std::endl;
  std::cout<<"middle: " << std::get<1>(t2) <<std::endl;
  std::cout<<"lastname: " << std::get<2>(t2) <<std::endl;
}
