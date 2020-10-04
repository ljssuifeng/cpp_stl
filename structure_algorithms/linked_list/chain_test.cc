#include "chain.h"
#include <algorithm>
#include <iomanip>
#include <iterator>
#include "chain.cc"

int main() {
  using std::cout;
  using std::endl;
  Chain<double> chain_double(1);
  chain_double.insert(0, 10);
  chain_double.insert(1, 2.3);
  chain_double.insert(2, 3.3);
  chain_double.insert(3, 21.3);
  chain_double.insert(4, 222.3);
  chain_double.output(std::cout);
  cout << chain_double;
  cout << "is empty? " << std::boolalpha << chain_double.empty() << endl;
  cout << chain_double.size() << endl;
  chain_double.erase(1);
  cout << chain_double;
  for (auto elem : chain_double) {
    cout << elem << " ";
  }
  cout << endl;
  Chain<double>::iterator iter = chain_double.begin();
  for (; iter != chain_double.end(); iter++) {
    cout << *iter << " ";
  }
  cout << endl;

  std::copy(chain_double.begin(), chain_double.end(),
            std::ostream_iterator<double>(std::cout, " "));
  cout << endl;
}
