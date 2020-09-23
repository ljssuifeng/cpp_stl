#include <functional>
#include <iostream>
#include <string>
#include <tuple>

// namespace std {
// template <typename ... Types>
// class tuple;
//}

////functions
// tuple<T1, T2, ..., Tn> t;
// tuple<T1, T2, ..., Tn> t(v1, v2, ..., vn);
// tuple<T1, T2> t(t2);

// get<0>(t);
// get<1>(t);

// t1.swap(t2);
// swap(t1, t2);

// make_tuple(t1, t2);

template <typename... T>
void sum(T... args) {
  std::cout << "sizeof of args:" << sizeof...(args) << std::endl;
  std::cout << "sizeof of T:" << sizeof...(T) << std::endl;
}

typename std::tuple<int, float, std::string> tupleType;
int main() {
  std::string s;
  auto x = std::make_tuple(s);
  std::get<0>(x) = "my value";

  auto y = std::make_tuple(std::ref(s));
  std::get<0>(y) = "my value";

  std::cout << std::get<0>(x) << std::endl;
  std::cout << std::get<0>(y) << std::endl;

  std::tuple<int, float, std::string> t(77, 1.1, "more light");
  int i;
  float f;
  // assign values of t to i,f,and s
  //  std::make_tuple(std::ref(i), std::ref(f), std::ref(s)) = t;
  std::tie(i, f, s) = t;
  // std::ignore allow us to ignore some elements
  std::tie(i, std::ignore, s) = t;

  std::cout << i << f << s << std::endl;

  // tuple_size<tupletype>::value;   can get elements count of this tuple
  std::cout << std::tuple_size<std::tuple<int, float, std::string>>::value
            << std::endl;
  // tuple_element<idx, tupletype>::type can get the idx element's type
  //  tuple_cat, can concatenate two tuple elements to
  int n;
  std::tuple_cat(std::make_tuple(42, 7.7, "hello"), std::tie(n));

  sum<int>(1, 2, 3, 4);
}
