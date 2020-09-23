#include "algorithm_test.hpp"

// function object that adds the value with which it is initialized
template <typename T>
class AddValue {
 private:
  T theValue;

 public:
  // constructor initializes the value to add
  AddValue(const T& v) : theValue(v) {}
  // the function call for th element adds the value
  void operator()(T& elem) const { elem += theValue; }
};

// function object to process the mean value
class MeanValue {
 private:
  long num;
  long sum;

 public:
  // constructor
  MeanValue() : num(0), sum(0) {}
  // function call
  //-process one more element of the sequence
  void operator()(int elem) {
    num++;
    sum += elem;
  }
  // return mean value (implicit type conversion)
  operator double() {
    return static_cast<double>(sum) / static_cast<double>(num);
  }
};

int main() {
  std::vector<int> coll;
  INSERT_ELEMENTS(coll, 1, 9);

  // call print() for each element
  for_each(coll.cbegin(), coll.cend(),
           [](int elem) { std::cout << elem << ' '; });
  std::cout << std::endl;

  // rangebased for circle more convinent
  for (auto elem : coll) {
    std::cout << elem << ' ';
  }
  std::cout << std::endl;

  // add 10 to each element
  for_each(coll.begin(), coll.end(), [](int& elem) { elem += 10; });
  PRINT_ELEMENTS(coll);
  // add value of first element to each element
  for_each(coll.begin(), coll.end(), [=](int& elem) { elem += *coll.begin(); });
  PRINT_ELEMENTS(coll);

  for_each(coll.begin(), coll.end(), AddValue<int>(10));
  PRINT_ELEMENTS(coll);

  for_each(coll.begin(), coll.end(), AddValue<int>(*coll.begin()));
  PRINT_ELEMENTS(coll);

  // add 10 to each element
  std::transform(coll.begin(), coll.end(), coll.begin(),
                 [](int elem) { return elem + 10; });
  PRINT_ELEMENTS(coll);
  // add value of first value to each element
  std::transform(coll.begin(), coll.end(), coll.begin(),
                 [=](int elem) { return elem + *coll.begin(); });
  PRINT_ELEMENTS(coll);

  // process and print mean value
  double mv = for_each(coll.begin(), coll.end(), MeanValue());
  std::cout << mv << std::endl;
}
