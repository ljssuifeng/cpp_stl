#include <iostream>
using std::pair;
// namespace std {
// template <typename T1, typename T2>
// struct pair {
////    member
//    T1 first;
//    T2 second;
//    //...
//};
//}

////functions
// pair<T1, T2> p;
// pair<T1, T2> p(val1, val2);
// pair<T1, T2> p(p2);
// p.first;
// p.second;

// get<0>(p); //equals to p.first
// get<1>(p); //equal to p.second

// p1.swap(p2);
// swap(p1, p2);

// make_pair(val1, val2);

template <typename T1, typename T2>
std::ostream& operator<<(std::ostream& strm, const std::pair<T1, T2>& p) {
  //  std::cout << "[" << p.first << "," << p.second << "]";
  //  return strm;
  return strm << "[" << p.first << "," << p.second << "]";
}

template <typename T1, typename T2>
bool operator==(const pair<T1, T2>& x, const pair<T1, T2>& y) {
  return x.first == y.first && x.second == y.second;
}

template <typename T1, typename T2>
bool operator<(const pair<T1, T2> x, const pair<T1, T2> y) {
  return x.first < y.first || (!(y.first < x.first) && x.second < y.second);
}

typedef std::pair<int, float> IntFloatPair;
IntFloatPair p(42, 3.24);

int main() { std::cout << p << std::endl; }
