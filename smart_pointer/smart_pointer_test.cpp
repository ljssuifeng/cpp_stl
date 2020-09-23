#include <iostream>
#include <memory>
#include <cassert>
#include <stdio.h>
#include <cstring>

using namespace std;

struct Student {
    std::string name;
    int age;
    ~Student() {std::cout<<"student object destructed!\n";}
};
#pragma pack(1)
struct bitfield_t {
    unsigned char head : 4,
        body:4;
        unsigned int start: 4;
        unsigned int :4;
        unsigned int middle:15;
        unsigned int tail:1;
        unsigned char end:1;
};//__attribute__((packed));


int main(int argc, char *argv[])
{
    std::cout<<sizeof(bitfield_t)<<std::endl;
//    cout << "Hello World!" << endl;
//    Student ss{"ljs", 32};
    std::unique_ptr<Student> unique_student(new  Student{"ljs", 32});
//    assert(unique_student->age == 33 && "age is not 32!\n");
    std::cout<<unique_student->name<<":"<<unique_student->age<<std::endl;

    const char* name = "ljs";
//    name[2] = 'l';
    char *pname = new char[4];
    memcpy(pname, "ljs", 4);
    pname[2] = 'l';
    std::cout<<name<<std::endl;
    printf("%c\n", pname[2]);
    delete[] pname;

    const int MAX_AGE = 90;
    int* a = new int;
    *a =2;
    int *b = a;
     delete b;
    a = (int*)&MAX_AGE;
    std::cout<<*a<<std::endl;
    *a = 30;
    std::cout<<*a<<std::endl;
    std::cout<<MAX_AGE<<std::endl;


    const int* p = (int*)&(MAX_AGE);
    std::cout<<"before_change:" <<*p<<std::endl;
//    *p = 30;
    std::cout<<"*p = "<< *p<<std::endl;
    std::cout<< MAX_AGE<<std::endl;

    int x = 9;
    auto f = [=]() mutable {
        x ++;
        std::cout<<"x is: "<<x<<std::endl;
    };
    f();
    std::cout<<"outer x is: "<< x <<std::endl;

    return 0;
}
