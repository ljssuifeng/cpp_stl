#include <atomic>
#include <chrono>
#include <future>
#include <iostream>
#include <thread>

// std::atomic<bool> readyFlag(false);

// void thread1() {
//    //do something thread2 needs as preparation
//    ...
//    readyFlag.store(true);
//}

// void thread2() {
//    //wait until readyFlag is true (thread1 is done)
//    while(!readyFlag.load()) {
//        std::this_thread::sleep_for(std::chrono::milliseconds(100));
//    }

//    //do whatever shall happend after thread1 has prepared things
//    ...
//}

long data;
std::atomic<bool> readyFlag(false);

void provider() {
  // after reading a character
  std::cout << "<return>" << std::endl;
  std::cin.get();
  // provide som data
  data = 42;
  // and signal readiness
  readyFlag.store(true);
}

void consumer() {
  // wait for readiness and do something else
  while (!readyFlag.load()) {
    std::cout.put('.').flush();
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
  }
  // and process provided data
  std::cout << "\nvalue: " << data << std::endl;
}

int main() {
  // start provider and consumer
  auto p = std::async(std::launch::async, provider);
  auto c = std::async(std::launch::async, consumer);
}
