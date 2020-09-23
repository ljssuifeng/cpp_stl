#include <algorithm>
#include <cctype>
#include <iostream>
#include <locale>
#include <regex>
#include <string>

int main() {
  // create a string
  std::string s("The zip code of Braunschweig in Germany is 38100");
  std::cout << "original: " << s << std::endl;

  // lowercase all characters
  std::transform(s.cbegin(), s.cend(), s.begin(),
                 [](char elem) { return std::tolower(elem); });
  std::cout << "lowered: " << s << std::endl;

  // uppercase all characters
  std::transform(s.cbegin(), s.cend(), s.begin(),
                 [](char elem) { return std::toupper(elem); });
  std::cout << "uppered: " << s << std::endl;

  // search case-insensitive for Germany
  std::string g("Germany");
  std::string::const_iterator pos;
  pos = std::search(
      s.cbegin(), s.cend(), g.cbegin(), g.cend(),
      [](char c1, char c2) { return std::toupper(c1) == std::toupper(c2); });
  if (pos != s.cend()) {
    std::cout << "substring \"" << g << "\" found at index "
              << std::distance(s.cbegin(), pos) << std::endl;
  }

  // create constant string
  const std::string hello("Hello, how are you?");
  // initilize string s with all characters of string hello
  std::string ss(hello.cbegin(), hello.cend());
  // rangebase for loop that iterates through all the characters
  for (char c : ss) {
    std::cout << c;
  }
  std::cout << std::endl;

  // reverse the order of all characters inside the string
  std::reverse(ss.begin(), ss.end());
  std::cout << "reversed:   " << ss << std::endl;

  // sort all characters inside the string
  std::sort(ss.begin(), ss.end());
  std::cout << "sorted:  " << ss << std::endl;

  // remove adjacent duplicates
  //-unique() reorders and returns new end
  //-erease() shrinks accordingly
  ss.erase(std::unique(ss.begin(), ss.end()), ss.end());
  std::cout << "no duplicates: " << ss << std::endl;

  std::string input;
  // don't skip leading whitespace
  std::cin.unsetf(std::ios::skipws);
  // read all characters while compressing whitespaces
  const std::locale& loc(std::cin.getloc());
  std::unique_copy(std::istream_iterator<char>(std::cin), std::istream_iterator<char>(),
              std::back_inserter(input), [=](char c1, char c2) {
                return std::isspace(c1, loc) && std::isspace(c2, loc);
              });
  // process input
  //-here: write it to the standard output
  std::cout << input;
}
