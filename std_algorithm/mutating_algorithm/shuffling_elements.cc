// void shuffle(RandomAccessIterator beg, RandomAccessIterator end,
// UniformRandomNumberGenerator&& eng);
// void random_shuffle(RandomAccessIterator beg, RandomAccessIterator end);
// void random_shuffle(RandomAccessIterator beg, RandomAccessIterator end,
// RandomFunc&& op);

#include "algorithm_test.hpp"

int main() {
  std::vector<int> coll;
  INSERT_ELEMENTS(coll, 1, 9);
  PRINT_ELEMENTS(coll, "coll:  ");

  // shuffle all elements randomly
  random_shuffle(coll.begin(), coll.end());
  PRINT_ELEMENTS(coll, "shuffled: ");

  // sort them again
  std::sort(coll.begin(), coll.end());
  PRINT_ELEMENTS(coll, "sorted: ");

  // shuffle elements with default engine
  std::default_random_engine dre;
  std::shuffle(coll.begin(), coll.end(), dre);
  PRINT_ELEMENTS(coll, "shuffled: ");
}
