#include <algorithm>
#include <cctype>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <map>
#include <string>

// function object to compare strings
//-allows you to set the comparison criterion at runtime
//-allows you to compare case insensitive
class RuntimeStringCmp {
 public:
  // constants for comparison criterion
  enum cmp_mode { normal, nocase };

 private:
  // actual comparison mode
  const cmp_mode mode;
  // auxiliary function to compare case insensitive
  static bool nocase_compare(char c1, char c2) {
    return toupper(c1) < toupper(c2);
  }

 public:
  // constructor: initialize the comparison criterion
  RuntimeStringCmp(cmp_mode m = normal) : mode(m) {}
  // the comparison
  bool operator()(const std::string& s1, const std::string& s2) const {
    if (mode == normal) {
      return s1 < s2;
    } else {
      return std::lexicographical_compare(s1.begin(), s1.end(), s2.begin(),
                                          s2.end(), nocase_compare);
    }
  }
};

typedef std::map<std::string, std::string, RuntimeStringCmp> StringStringMap;
// function that fills and prints such containers
void fillAndPrint(StringStringMap& coll);

int main() {
  std::multimap<int, std::string> coll;

  coll = {{5, "tagged"},  {2, "a"},  {1, "this"},    {4, "of"},
          {6, "strings"}, {1, "is"}, {3, "multimap"}};
  for (auto elem : coll) {
    std::cout << elem.second << ' ';
  }
  std::cout << '\n';

  coll.insert({7, "insert_test"});
  for (auto elem : coll) {
    std::cout << elem.second << ' ';
  }
  std::cout << '\n';

  std::map<std::string, double> coll_{{"tim", 9.9}, {"struppi", 11.77}};
  std::for_each(coll_.begin(), coll_.end(),
                [](std::pair<const std::string, double>& elem) {
                  elem.second *= elem.second;
                });
  std::for_each(coll_.begin(), coll_.end(),
                [](const std::map<std::string, double>::value_type& elem) {
                  std::cout << elem.first << ": " << elem.second << std::endl;
                });

  typedef std::map<std::string, float> StringFloatMap;
  StringFloatMap stocks;
  // insert some elements
  stocks["BASF"] = 369.50;
  stocks["VW"] = 413.50;
  stocks["Daimler"] = 819.00;
  stocks["BMW"] = 834.00;
  stocks["Siemens"] = 842.20;

  StringFloatMap::iterator pos;
  std::cout << std::left;
  for (pos = stocks.begin(); pos != stocks.end(); ++pos) {
    std::cout << "stock: " << std::setw(12) << pos->first
              << "price: " << pos->second << std::endl;
  }
  std::cout << std::endl;
  // boom (all prices double)
  for (pos = stocks.begin(); pos != stocks.end(); ++pos) {
    pos->second *= 2;
  }
  // print all elements
  for (pos = stocks.begin(); pos != stocks.end(); ++pos) {
    std::cout << "stock: " << std::setw(12) << pos->first
              << "price: " << pos->second << std::endl;
  }
  std::cout << std::endl;

  // rename key from " VW " TO "Volkswagen"
  //- provided only by exchanging element
  stocks["Volkswagen"] = stocks["VW"];
  stocks.erase("VW");
  // print all elements
  for (pos = stocks.begin(); pos != stocks.end(); ++pos) {
    std::cout << "stock: " << std::setw(12) << pos->first
              << "price: " << pos->second << std::endl;
  }
  std::cout << std::endl;

  std::multimap<std::string, std::string> dict;
  // insert some elements in random order
  dict.insert({{"day", "Tag"},
               {"strange", "fremd"},
               {"car", "Auto"},
               {"smart", "elegant"},
               {"trait", "Merkmal"},
               {"strange", "seltsam"},
               {"smart", "raffiniert"},
               {"smart", "king"},
               {"clever", "raffiniert"}});

  std::cout.setf(std::ios::left, std::ios::adjustfield);
  std::cout << ' ' << std::setw(10) << "english"
            << "german " << std::endl;
  std::cout << std::setfill('-') << std::setw(20) << "" << std::setfill(' ')
            << std::endl;
  for (const auto& elem : dict) {
    std::cout << ' ' << std::setw(10) << elem.first << elem.second << std::endl;
  }
  std::cout << std::endl;

  // print all values for key "smart"
  std::string word("smart");
  std::cout << word << ": " << std::endl;
  for (auto pos = dict.lower_bound(word); pos != dict.upper_bound(word);
       ++pos) {
    std::cout << "    " << pos->second << std::endl;
  }

  // print all keys for value "raffiniert"
  word = ("raffiniert");
  std::cout << word << ": " << std::endl;
  for (const auto& elem : dict) {
    if (elem.second == word) {
      std::cout << "    " << elem.first << std::endl;
    }
  }

  std::map<float, float> coll_map = {{1, 7}, {2, 4}, {3, 2}, {4, 3},
                                     {5, 6}, {6, 1}, {7, 3}};
  // search an element with key 3.0 (logarithmic complexity)
  auto posKey = coll_map.find(3.0);
  if (posKey != coll_map.end()) {
    std::cout << "key 3.0 found (" << posKey->first << ":" << posKey->second
              << ")" << std::endl;
  }
  // search an element with value 3.0 (linear complexity)
  auto posVal = find_if(
      coll_map.begin(), coll_map.end(),
      [](const std::pair<float, float>& elem) { return elem.second == 3.0; });
  if (posVal != coll_map.end()) {
    std::cout << "value 3.0 found (" << posVal->first << ":" << posVal->second
              << ")" << std::endl;
  }
  StringStringMap coll1;
  fillAndPrint(coll1);

  // create an object for case-insensitive comparisons
  RuntimeStringCmp ignorecase(RuntimeStringCmp::nocase);
  StringStringMap coll2(ignorecase);
  fillAndPrint(coll2);
}

void fillAndPrint(StringStringMap& coll) {
  // insert elements in random order
  coll["Deutschland"] = "Germany";
  coll["deutsch"] = "German";
  coll["Haken"] = "snag";
  coll["arbeiten"] = "work";
  coll["Hund"] = "dog";
  coll["gehen"] = "go";
  coll["Unternehmen"] = "enterprise";
  coll["unternehmen"] = "undertake";
  coll["gehen"] = "walk";
  coll["Bestatter"] = "undertaker";
  // print elements
  std::cout.setf(std::ios::left, std::ios::adjustfield);
  for (const auto& elem : coll) {
    std::cout << std::setw(15) << elem.first << " " << elem.second << std::endl;
  }
  std::cout << std::endl;
}
