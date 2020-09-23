// T accumulate(InputIterator beg, InputIterator end, T initValue);
// T accumulate(InputIterator beg, InputIterator end, T initValue, BinaryFunc
// op);
// T inner_product(InputIterator1 beg1, InputIterator1 end1, InputIterator2
// beg2,
//                T initValue);
// T inner_product(InputIterator1 beg1, InputIterator1 end1, InputIterator2
// beg2,
//                T initValue, BinaryFunc op1, BinaryFunc op2);

#include "algorithm_test.hpp"

int main() {
  std::vector<int> coll;
  INSERT_ELEMENTS(coll, 1, 9);
  PRINT_ELEMENTS(coll);
  // process sum of elements
  std::cout << "sum: " << std::accumulate(coll.cbegin(), coll.cend(), 0)
            << std::endl;
  // process sum of elements less 100
  std::cout << "sum: " << std::accumulate(coll.cbegin(), coll.cend(), -100)
            << std::endl;
  // process product of elements
  std::cout << "sum: " << std::accumulate(coll.cbegin(), coll.cend(), 1,
                                          std::multiplies<int>())
            << std::endl;
  // process product of elements (use 0 as initial value)
  std::cout << "product: " << std::accumulate(coll.cend(), coll.cend(), 0,
                                              std::multiplies<int>())
            << std::endl;

  std::list<int> l_coll;
  INSERT_ELEMENTS(l_coll, 1, 6);
  PRINT_ELEMENTS(l_coll);
  // process sum of all products
  //(0+ 1*1 + 2*2 + 3*3+4*4 + 5*5 + 6*6)
  std::cout << "inner product: "
            << std::inner_product(l_coll.cbegin(), l_coll.cend(), l_coll.cbegin(), 0)
            << std::endl;

  // process sum of 1*6...6*1
  //(0+ 1*6 + 2*5 + 3*4+4*3 + 5*2 + 6*1)
  std::cout << "inner product: "
            << std::inner_product(l_coll.cbegin(), l_coll.cend(), l_coll.crbegin(), 0)
            << std::endl;

  // process sum of all sums
  //(1*1+1*2+2*3+3*4+4*5+5*6+6)
  std::cout << "product of sums: "
            << std::inner_product(l_coll.cbegin(), l_coll.cend(), l_coll.cbegin(), 1,
                                  std::multiplies<int>(), std::plus<int>())
            << std::endl;
}
