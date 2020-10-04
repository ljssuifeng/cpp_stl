#include <iomanip>
#include "array_list.cc"
#include "array_list.h"

int main() {
  using std::cout;
  using std::endl;
  try {
    ArrayList<double> d_array(10);
    cout << std::boolalpha << d_array.empty() << endl;
    cout << d_array.size() << endl;
    cout << d_array.capacity() << endl;
    for (int i = 0; i < d_array.capacity(); ++i) {
      d_array.insert(i, i);
    }
    for (auto elem : d_array) {
      std::cout << "elem: " << elem << std::endl;
    }
    ArrayList<double>::iterator iter = d_array.begin();
    for (; iter != d_array.end(); ++iter) {
      std::cout << "elem iter: " << *iter << std::endl;
    }
    d_array.output(std::cout);
    std::cout << d_array << std::endl;
    ArrayList<double> d2_array{d_array};
    std::cout << std::accumulate(d2_array.begin(), d2_array.end(), 0)
              << std::endl;
    d2_array.insert(2, 33);
    cout << "after insert, d2 capacity: " << d2_array.capacity() << std::endl;
    d2_array.output(std::cout);
    std::copy(d2_array.begin(), --d2_array.end(), d_array.begin());
    d_array.output(std::cout);

  } catch (std::exception& e) {
    std::cerr << "exception: " << e.what() << std::endl;
  }
}
