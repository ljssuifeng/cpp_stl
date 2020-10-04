#include "ring_buffer.h"
#include <cassert>
#include <iostream>

#define NDEBUG
#define log(data) debugBuf.addEntry(data)
RingBuffer debugBuf;

int main(int argc, char* argv[]) {
  // Log the command line argument
  for (int i = 0; i < argc; ++i) {
    log(argv[i]);
  }
  std::cout << debugBuf << std::endl;

  assert(false);

  return 0;
}
