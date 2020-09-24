#include <chrono>
#include <exception>
#include <iostream>
#include <random>
#include <thread>

void doSomething(int num, char c) {
  try {
    // random-number generator (use c as seed toget different sequences)
    std::default_random_engine dre(42 * c);
    std::uniform_int_distribution<int> id(10, 100);

    for (int i = 0; i < 10; ++i) {
      std::this_thread::sleep_for(std::chrono::milliseconds(id(dre)));
      std::cout.put(c).flush();
    }
  }
  // make sure no exception leaves the thread and terminates the program
  catch (const std::exception& e) {
    std::cerr << "THREAD-EXCEPTION (Thread " << std::this_thread::get_id()
              << ")" << e.what() << std::endl;
  } catch (...) {
    std::cerr << "THREAD-EXCEPTION (Thread " << std::this_thread::get_id()
              << ")" << std::endl;
  }
}

int main() {
  try {
    std::thread t1(doSomething, 5, '.');
    std::cout << "- started fg thread " << t1.get_id() << std::endl;

    // print other characters in other background threads
    for (int i = 0; i < 5; ++i) {
      std::thread t(doSomething, 10, 'a' + i);
      std::cout << "- detach started bg thread " << t.get_id() << std::endl;
      t.detach();
    }
    std::cin.get();
    std::cout << "- join fg thread " << t1.get_id() << std::endl;
    t1.join();
  } catch (const std::exception& e) {
    std::cerr << "EXCEPTION: " << e.what() << std::endl;
  }
}
