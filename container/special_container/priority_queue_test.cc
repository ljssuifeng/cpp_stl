// namespace std {
// template <typename T, typename Container = vector<T>,
//          typename Compare = less<typename Container::value_type>>
// class priority_queue;
//}

// core function: push(), top(), pop()

#include <iostream>
#include <queue>

int main() {
  std::priority_queue<float> q;
  // insert three elements into the priority queue
  q.push(66.6);
  q.push(22.2);
  q.push(44.4);

  // read and print two elements
  std::cout << q.top() << ' ';
  q.pop();
  std::cout << q.top() << ' ';
  q.pop();

  // insert three more elements
  q.push(11.1);
  q.push(55.5);
  q.push(33.3);

  // skip one element
  q.pop();

  // pop and print remaining elements
  while (!q.empty()) {
    std::cout << q.top() << ' ';
    q.pop();
  }
  std::cout << std::endl;
}
