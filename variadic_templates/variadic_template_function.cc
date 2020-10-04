#include <iostream>

template <typename... T>
void f(T... args) {
  std::cout << sizeof...(args) << std::endl;
}

void print() { std::cout << "empty" << std::endl; }

template <typename T, typename... args>
void print(T head, args... rest) {
  std::cout << "parameter " << head << std::endl;
  print(rest...);
}

template <typename T>
T sum(T t) {
  return t;
}

template <typename T, typename... Types>
T sum(T first, Types... rest) {
  return first + sum<T>(rest...);
}

template <typename T>
void printarg(T t) {
  std::cout << t << std::endl;
}
template <typename... Args>
void expand(Args... args) {
  int arr[] = {(printarg(args), 0)...};
}

int main() {
  f();
  f(1);
  f(1, 2);
  f(3, 5, "hello");

  print(1, 2, 3, 4);
  std::cout << "sum: " << sum(1, 2, 3, 4) << std::endl;

  expand(1, 2, 3, 4);
}
