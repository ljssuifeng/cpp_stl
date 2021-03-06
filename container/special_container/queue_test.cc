#include <queue>

// namespace std {
// template <typename T, typename Container = std::deque<T>>
// class queue;
//}

// core functions: push(), pop(), front(), back()

#include <iostream>
#include <string>

int main() {
  std::queue<std::string> q;
  // insert three elements into the queue
  q.push("These ");
  q.push("are ");
  q.push("more than ");

  // read and print two elements from the queue
  std::cout << q.front();
  q.pop();
  std::cout << q.front();
  q.pop();

  // insert two new elements
  q.push("four ");
  q.push("words! ");

  // skip one element
  q.pop();

  // read and print two elements
  std::cout << q.front();
  q.pop();
  std::cout << q.front();
  q.pop();

  // print number of elements in the queue
  std::cout << "number of elements in the queue: " << q.size() << std::endl;
}
