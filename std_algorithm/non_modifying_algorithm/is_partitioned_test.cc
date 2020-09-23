// bool is_partitioned(InputIterator beg, InputIterator end, UnaryPredicate op);
// ForwardIterator partition_point(ForwardIterator beg, ForwardIterator end,
// BinaryPredicate op);

#include "algorithm_test.hpp"

int main() {
  std::vector<int> coll = {5, 3, 9, 1, 3, 4, 8, 2, 6};
  PRINT_ELEMENTS(coll, "coll: ");
  //define predicate: check whether element is odd:
  auto isOdd = [](int elem) {return elem%2==1;};

  //check whether coll is partitioned in odd and even elements
  if(std::is_partitioned(coll.cbegin(), coll.cend(), isOdd)) {
      std::cout<<"coll is partitioned."<<std::endl;
      //find first even element
      auto pos = std::partition_point(coll.cbegin(), coll.cend(), isOdd);
      std::cout<<"first even element: "<<*pos<<std::endl;
  } else {
      std::cout<<"coll is not partitioned"<<std::endl;
  }
}
