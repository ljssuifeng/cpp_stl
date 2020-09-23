// void generate(ForwardIterator beg, ForwardIterator end, Func op);
// void generate_n(OutputIterator beg, Size num, Func op);

#include "algorithm_test.hpp"

int main() {
  std::list<int> coll;
  // insert five random numbers
  std::generate_n(std::back_inserter(coll), 5, std::rand);
  PRINT_ELEMENTS(coll, "coll: ");

  // overwrite with five new random numbers
  std::generate(coll.begin(), coll.end(), std::rand);
  PRINT_ELEMENTS(coll, "coll: ");
}
