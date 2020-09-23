#include <iostream>

using namespace std;

class A;
class B {
public:
    void printA(A& a);
};

class A {
private: int m_a;
public:
    A(int a_value = 5):m_a{a_value} {}
//    friend void B::printA(A& a);
    friend void B::printA(A& a);
};

void B::printA(A &a) {
    std::cout<<a.m_a<<std::endl;
}

int main(int argc, char *argv[])
{
    A a;
    B b;
    b.printA(a);
//    printA(a);
    return 0;
}
