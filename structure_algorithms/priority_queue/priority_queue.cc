#include "priority_queue.h"

int main() {
  using std::cout;
  using std::endl;
  // test constructor and push
  MaxHeap<int> h(4);
  h.push(10);
  h.push(20);
  h.push(5);

  cout << "Heap size is " << h.size() << endl;
  cout << "Elements in array order are" << endl;
  cout << h << endl;

  h.push(15);
  cout << h << endl;
  h.push(30);

  cout << "Heap size is " << h.size() << endl;
  cout << "Elements in array order are" << endl;
  cout << h << endl;

  // test top and pop
  cout << "The max element is " << h.top() << endl;
  h.pop();
  cout << "The max element is " << h.top() << endl;
  h.pop();
  cout << "The max element is " << h.top() << endl;
  h.pop();
  cout << "Heap size is " << h.size() << endl;
  cout << "Elements in array order are" << endl;
  cout << h << endl;

  // test initialize
  int* z = new int[10];
  for (int i = 1; i < 10; i++) z[i] = i;
  h.initialize(z, 9);
  cout << "Elements in array order are" << endl;
  cout << h << endl;
  return 0;

  //  int* a = new int[10];
  //  delete[] a;
  //  int* b = new int[5];
  //  a = b;
  //  delete[] a;
}
