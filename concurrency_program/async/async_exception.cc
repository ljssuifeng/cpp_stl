#include <chrono>
#include <exception>
#include <future>
#include <iostream>
#include <list>

void task1() {
  // endless insertion and momory allocation
  //-will sonner or later raise an exception
  //-BEWARE: this is bad parctice
  std::list<int> v;
  while (true) {
    for (int i = 0; i < 1000000; ++i) {
      v.push_back(i);
    }
    std::cout.put('.').flush();
  }
}

int main() {
  std::cout << "starting 2 tasks" << std::endl;
  std::cout << "- task1: process endless loop of memory consumption"
            << std::endl;
  std::cout << "- task2: wait for <return> and then for task1" << std::endl;

  auto f1 = std::async(
      task1);      // start task1() asynchronously
  std::cin.get();  // read a character (like getchar())
  std::cout << "\nwait for the end of task1: " << std::endl;
  try {
    f1.get();  // wait for task1() to finish (raise exception if any)
  } catch (const std::exception& e) {
    std::cerr << "EXCEPTION: " << e.what() << std::endl;
  }
}
