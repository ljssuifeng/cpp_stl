#include "hash_table.h"

int main() {
  HashTable<std::string, int> ha_table(2);
  std::pair<const std::string, int> a("one", 1);
  std::pair<const std::string, int> b("two", 2);
  //  std::pair<const std::string, int> c("three", 3);
  std::pair<const std::string, int> d("two", 3);
  ha_table.insert(a);
  ha_table.insert(b);
  std::cout << ha_table << std::endl;
  ha_table.insert(d);
  std::cout << "overwirte theKey: two" << std::endl;
  std::cout << ha_table << std::endl;
  ha_table.erase("one");
  std::cout << "erase: one" << std::endl;
  std::cout << ha_table << std::endl;

  return 0;
}
