#include <chrono>
#include <condition_variable>
#include <future>
#include <iostream>
#include <mutex>
#include <queue>
#include <thread>

std::queue<int> queue;
std::mutex queueMutex;
std::condition_variable queueCondVar;

void provider(int val) {
  // push different values(va til val+5 with timeout of val milliseconds into
  // the queue
  for (int i = 0; i < 6; ++i) {
    std::lock_guard<std::mutex> lg(queueMutex);
    queue.push(val + i);
  }  // release lock
  queueCondVar.notify_all();
  std::this_thread::sleep_for(std::chrono::milliseconds(val));
}

void consumer(int num) {
  // pop values if available (num identifies the consumer)
  while (true) {
    int val;
    {
      std::unique_lock<std::mutex> ul(queueMutex);
      queueCondVar.wait(ul, []() { return !queue.empty(); });
      val = queue.front();
      queue.pop();
      std::cout << "consumer " << num << ": " << val << std::endl;
    }  // release lock
       //    std::cout << "consumer " << num << ": " << val << std::endl;
  }
}

int main() {
  // start three providers for values 100+, 300+, and 500+
  auto p1 = std::async(std::launch::async, provider, 100);
  auto p2 = std::async(std::launch::async, provider, 300);
  auto p3 = std::async(std::launch::async, provider, 500);

  // start two consumer printing the values
  auto c1 = std::async(std::launch::async, consumer, 1);
  auto c2 = std::async(std::launch::async, consumer, 2);
}