// OutputIterator
// copy(InputIterator sourceBeg, InputIterator sourceEnd, OutputIterator
// destBeg);
// OutputIterator
// copy_if(InputIterator sourceBeg, InputIterator sourceEnd, OutputIterator
// destBeg, UnaryPredicate op);
// OutputIterator
// copy_n(InputIterator sourceBeg, Size num, OutputIterator destBeg);
// BidirectionalIterator2
// copy_backward(BidirectionalIterator1 sourceBeg,
//              BidirectionalIterator1 sourceEnd,
//              BidirectionalIterator2 destEnd);

#include "algorithm_test.hpp"

int main() {
  std::vector<std::string> coll1 = {"Hello", "this", "is", "an", "example"};
  std::list<std::string> coll2;

  // copy elements of coll1 into coll2
  // -use back inserter to insert instead of overwrite
  std::copy(coll1.cbegin(), coll1.cend(), std::back_inserter(coll2));

  // print element of coll2
  // -copy elements to count using an ostream iterator
  std::copy(coll2.cbegin(), coll2.cend(),
            std::ostream_iterator<std::string>(std::cout, " "));
  std::cout << std::endl;

  // copy element of coll1 into coll2 in reverse order
  // -now overwriting
  std::copy(coll1.crbegin(), coll1.crend(), coll2.begin());

  // print elements of coll2 again
  std::copy(coll2.cbegin(), coll2.cend(),
            std::ostream_iterator<std::string>(std::cout, " "));
  std::cout << std::endl;

  // initialization source collection with "...........abcdef..............."
  std::vector<char> source(10, '.');
  for (int c = 'a'; c <= 'f'; ++c) {
    source.push_back(c);
  }
  source.insert(source.end(), 10, '.');
  PRINT_ELEMENTS(source, "source: ");

  // copy all letters three elements in front of the 'a'
  std::vector<char> c1(source.cbegin(), source.cend());
  std::copy(c1.cbegin() + 10, c1.cbegin() + 16, c1.begin() + 7);
  PRINT_ELEMENTS(c1, "c1: ");

  // copy all letters three elements behind the 'f'
  std::vector<char> c2(source.cbegin(), source.cend());
  std::copy_backward(c2.cbegin() + 10, c2.cbegin() + 16, c2.begin() + 19);
  PRINT_ELEMENTS(c2, "c2: ");

  std::copy(std::istream_iterator<std::string>(std::cin),
            std::istream_iterator<std::string>(),
            std::ostream_iterator<std::string>(std::cout, "\n"));
}
