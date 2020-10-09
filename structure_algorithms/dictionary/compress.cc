#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include "hash_table.h"

// constants
const int DIVISOR = 4099, MAX_CODES = 4096, BYTE_SIZE = 8, EXCESS = 4,
          ALPHA = 256, MASK1 = 255, MASK2 = 15;
typedef std::pair<const long, int> pairType;

// global variables
int leftOver;               // bit is on output
bool bitsLeftOver = false;  // false: no left bit to output
std::string inputFileName, outputFileName;
std::ifstream in;
std::ofstream out;

void setFiles(int argc, char** argv) {
  if (argc >= 2) {
    inputFileName = std::string(argv[1]);
    std::cout<<"filename is: " << inputFileName<<std::endl;
    outputFileName = inputFileName + ".zzz";
  } else {
    std::cout << "Please enter name of file to compress." << std::endl;
    std::getline(std::cin, inputFileName);
    std::cout << "inputFileName: " << inputFileName << std::endl;
  }

  // open inputFile as binary
  in.open(inputFileName, std::ios::binary);
  if (in.fail()) {
    std::cerr << "Cannot open " << inputFileName << std::endl;
    exit(1);
  }
  out.open(outputFileName, std::ios::binary);
}

void output(long pcode) {
  int c, d;
  // output 8 bits, save rest 4bits in leftOver
  if (bitsLeftOver) {
    // half byte remain from before
    d = int(pcode & MASK1);
    c = int((leftOver << EXCESS) | (pcode >> BYTE_SIZE));
    out.put(c);
    out.put(d);
    bitsLeftOver = false;
  } else {
    // no bits remain from before
    leftOver = pcode & MASK2;  // right EXCESS bits
    c = int(pcode >> EXCESS);
    out.put(c);
    bitsLeftOver = true;
  }
}

void compress() {
  HashTable<long, int> h(DIVISOR);
  for (int i = 0; i < ALPHA; ++i) {
    pairType a(i, i);
    h.insert(a);
  }
  int codesUsed = ALPHA;
  // input and compress
  int c = in.get();
  if (c != EOF) {
    long pcode = c;  // prefix code
    while ((c = in.get()) != EOF) {
      // deal with character 'c'
      long theKey = (pcode << BYTE_SIZE) + c;
      pairType* thePair = h.find(theKey);
      if (thePair == nullptr) {
        // the key is not in dict
        output(pcode);
        if (codesUsed < MAX_CODES) {
          pairType temp(theKey, codesUsed++);
          h.insert(temp);
          pcode = c;
        } else {
          pcode = thePair->second;
        }
        // output last codes
        output(pcode);
        if (bitsLeftOver) {
          out.put(leftOver << EXCESS);
        }
      }
    }
  }
  out.close();
  in.close();
}

int main(int argc, char** argv) {
  setFiles(argc, argv);
  compress();
  return 0;
}
