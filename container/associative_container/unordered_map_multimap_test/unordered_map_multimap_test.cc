#include <iostream>
#include <numeric>
#include <string>
#include <unordered_map>

int main() {
  std::unordered_map<std::string, double> coll{{"tim", 9.9},
                                               {"struppi", 11.77}};
  for (std::pair<const std::string, double>& elem : coll) {
    elem.second *= elem.second;
  }
  coll["VAT1"] = 0.16;
  coll["VAT2"] = 0.07;
  coll["Pi"] = 3.1415;
  for (const auto& elem : coll) {
    std::cout << elem.first << ": " << elem.second << std::endl;
  }
}
