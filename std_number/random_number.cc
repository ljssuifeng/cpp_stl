#include <algorithm>
#include <iostream>
#include <iterator>
#include <random>
#include <sstream>
#include <vector>

void printNumber(std::default_random_engine& dre) {
  for (int i = 0; i < 6; ++i) {
    std::cout << dre() << " ";
  }
  std::cout << std::endl;
}

int main() {
  // create default engine as source of randomness
  std::default_random_engine dre1;

  // use engine to generate integral numbers between 10 and 20 (both included)
  std::uniform_int_distribution<int> di(10, 20);
  for (int i = 0; i < 20; ++i) {
    std::cout << di(dre1) << " ";
  }
  std::cout << std::endl;

  // use engine to generate floating-point numbers between 10.0 to 20.0
  // -(10.0 included 20.0 not included)
  std::uniform_real_distribution<double> dr(10, 20);
  for (int i = 0; i < 8; ++i) {
    std::cout << dr(dre1) << " ";
  }
  std::cout << std::endl;

  // use engine to shuffle elements
  std::vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  std::shuffle(v.begin(), v.end(), dre1);
  std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, " "));
  std::cout << std::endl;

  // create engine and generate numbers
  std::default_random_engine dre;
  printNumber(dre);

  // create equal engine and generate numbers
  std::default_random_engine dre2;
  printNumber(dre2);

  // create engine with initial value specified by a seed
  std::default_random_engine dre3(42);
  printNumber(dre3);

  // save state of engine dre
  std::stringstream engineState;
  engineState << dre;

  // generate numbers according to current state of dre
  printNumber(dre);

  // restore saved state of engine dre and create numbers again
  engineState >> dre;
  printNumber(dre);

  // restore saved state of engine dre, skip 2 numbers and create numbers again
  engineState.clear();
  engineState.seekg(0);
  engineState >> dre;
  dre.discard(2);
  printNumber(dre);
}
