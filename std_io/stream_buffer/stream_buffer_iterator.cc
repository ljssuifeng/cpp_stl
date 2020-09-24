#include <iostream>
#include <iterator>

int main() {
  // input stream buffer iterator for cin
  std::istreambuf_iterator<char> inpos(std::cin);

  // end-of-stream iterator
  std::istreambuf_iterator<char> endpos;

  // output stream buffer iterator for cout
  std::ostreambuf_iterator<char> outpos(std::cout);

  // while input iterator is valid
  while (inpos != endpos) {
    *outpos = *inpos;
    ++inpos;
    ++outpos;
  }
}
