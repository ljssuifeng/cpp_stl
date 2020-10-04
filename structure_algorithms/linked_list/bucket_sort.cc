#include <iostream>
#include <string>
#include "chain.cc"
#include "chain.h"

struct StudentRecord {
  StudentRecord(int s, std::string na) : score(s), name(na) {}
  int score;
  std::string name;
  bool operator!=(const StudentRecord& rhs) const { return score != rhs.score; }
  operator int() const { return score; }
};

std::ostream& operator<<(std::ostream& out, const StudentRecord& x) {
  out << x.score << ' ' << x.name << std::endl;
  return out;
}

void bucketSort(Chain<StudentRecord>& theChain, int range) {
  Chain<StudentRecord>* bucket;
  bucket = new Chain<StudentRecord>[range + 1];
  int numberofElements = theChain.size();
  for (int i = 0; i < numberofElements; ++i) {
    StudentRecord x = theChain.get(0);
    theChain.erase(0);
    bucket[x.score].insert(0, x);
  }

  for (int j = range; j >= 0; j--) {
    while (!bucket[j].empty()) {
      StudentRecord x = bucket[j].get(0);
      bucket[j].erase(0);
      theChain.insert(0, x);
    }
  }
  delete[] bucket;
}

int main() {
  using std::cout;
  Chain<StudentRecord> chain_ss(10);
  chain_ss.insert(0, StudentRecord(1, "li"));
  chain_ss.insert(0, StudentRecord(4, "wang"));
  chain_ss.insert(0, StudentRecord(3, "zhang"));
  chain_ss.insert(0, StudentRecord(6, "zhao"));
  chain_ss.insert(0, StudentRecord(2, "zhou"));
  chain_ss.insert(0, StudentRecord(4, "liu"));
  bucketSort(chain_ss, 6);
  cout << chain_ss;
}
