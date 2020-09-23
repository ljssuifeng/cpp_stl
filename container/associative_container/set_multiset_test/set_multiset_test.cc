#include <algorithm>
#include <iostream>
#include <iterator>
#include <set>
#include <string>

int main() {
  std::multiset<std::string> cities{"Braunschweig", "Hanover",  "Frankfurt",
                                    "New York",     "chicago",  "Toronto",
                                    "Paris",        "Frankfurt"};
  for (const auto& elem : cities) {
    std::cout << elem << " ";
  }
  std::cout << std::endl;

  cities.insert({"London", "Munich", "Hanover", "Braunschweig"});
  for (const auto& elem : cities) {
    std::cout << elem << " ";
  }
  std::cout << std::endl;
  std::cout << "*******************************\n";
  std::set<std::string> set_cities{"Braunschweig", "Hanover",  "Frankfurt",
                                   "New York",     "chicago",  "Toronto",
                                   "Paris",        "Frankfurt"};
  for (const auto& elem : set_cities) {
    std::cout << elem << " ";
  }
  std::cout << std::endl;

  set_cities.insert({"London", "Munich", "Hanover", "Braunschweig"});
  for (const auto& elem : set_cities) {
    std::cout << elem << " ";
  }
  std::cout << std::endl;

  std::set<int> c;
  c.insert({1, 2, 3, 4, 5, 6});

  std::cout << "lower_bound(3)" << *c.lower_bound(3) << std::endl;
  std::cout << "upper_bound(3)" << *c.upper_bound(3) << std::endl;
  std::cout << "equal_range(3)" << *c.equal_range(3).first << " "
            << *c.equal_range(3).second << std::endl;
  std::cout << std::endl;

  std::cout << "lower_bound(5): " << *c.lower_bound(5) << std::endl;
  std::cout << "upper_bound(5): " << *c.upper_bound(5) << std::endl;
  std::cout << "equal_range(5): " << *c.equal_range(5).first << " "
            << *c.equal_range(5).second << std::endl;

  // descending order
  std::set<int, std::greater<int>> coll1;
  // insert elements in random order using different member functions.
  coll1.insert({4, 3, 5, 1, 6, 2});
  coll1.insert(5);
  std::copy(coll1.cbegin(), coll1.cend(),
            std::ostream_iterator<int>(std::cout, " "));
  std::cout << std::endl;

  //insert 4 again and processs return value
  auto status = coll1.insert(4);
  if(status.second) {
      std::cout<<"4 inserted as element" << std::distance(coll1.begin(), status.first) + 1 <<std::endl;
  } else {
    std::cout<<"4 already exists."<<std::endl;
  }

  std::set<int> coll2(coll1.cbegin(), coll1.cend());
  std::copy(coll2.cbegin(), coll2.cend(),
            std::ostream_iterator<int>(std::cout, " "));
  std::cout << std::endl;

  // remove all elements up to element with value 3
  coll2.erase(coll2.begin(), coll2.find(3));

  //remove all elements with value 5
  int num;
  num = coll2.erase(5);
  std::cout<<num<<" elements removed."<<std::endl;

  std::copy(coll2.cbegin(), coll2.cend(),
            std::ostream_iterator<int>(std::cout, " "));
  std::cout << std::endl;

}
