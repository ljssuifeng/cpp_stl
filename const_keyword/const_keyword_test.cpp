#include <iostream>

#define ADD(x, y) (x+y)

class A {
 private:
  const int a;
  int b;

 public:
  A() : a(0) {}
  A(int x) : a(x) {}

  int getValue();
  bool setValue(int value) const;
  int getValue() const;
};
int A::getValue() { return a; }
int A::getValue() const { return a; }
bool A::setValue(int value) const {
//  b = value;
  return true;
}

using namespace std;

int main(int argc, char *argv[]) {
  A b;
  const A a;
  const A *p = &a;
  const A &q = a;
  a.setValue(5);
  cout << "A.a is: " << b.getValue() << endl;
  cout << "a.a is: " << a.getValue() << endl;
  cout << "Hello World!" << endl;

  cout<<ADD(3.2, 5.7)<<endl;
  return 0;
}
