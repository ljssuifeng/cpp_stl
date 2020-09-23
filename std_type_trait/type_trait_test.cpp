#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <type_traits>

template <typename T>
void foo_impl(T val, std::true_type) {
  std::cout << val << std::endl;
}

template <typename T>
void foo_impl(T val, std::false_type) {
  std::cout << "type false!\n";
}

template <typename T>
void foo(T val) {
  foo_impl(val, std::is_integral<T>());
}

template <typename T1, typename T2>
typename std::common_type<T1, T2>::type min(const T1& x, const T2& y) {
  return x < y ? x : y;
}
int main() {
  foo(4);
  foo("string");
  std::cout << "min(50,12.9) is: " << min(50, 12.9) << std::endl;
  std::cout << std::min(3, 5, [](int x, int y) { return x > y; }) << std::endl;
  // minmax() return type is a pair, first element is min, second is max
  auto minmax = std::minmax<double>({1, 2, 3, 4, 5, 6, 7, 9.5});
  std::cout << "min of initlist is: " << minmax.first << '\n'
            << "max of initlist is: " << minmax.second << std::endl;
}
