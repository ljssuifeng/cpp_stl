#include "queue.h"

int main() {
  ArrayQueue<int> aq(2);
  std::cout << "aq is empty? " << std::boolalpha << aq.empty() << std::endl;
  aq.push(2);
  aq.push(3);
  aq.push(4);
  aq.pop();
  std::cout << "aq front element is: " << aq.front() << std::endl;
  std::cout << "aq back element is: " << aq.back() << std::endl;
  aq.pop();
  aq.pop();
  //  aq.pop();   //throw exception : queueEmpty here

  LinkedQueue<int> lq(2);
  std::cout << "lq is empty? " << std::boolalpha << lq.empty() << std::endl;
  lq.push(2);
  lq.push(3);
  lq.push(4);
  lq.pop();
  std::cout << "lq front element is: " << lq.front() << std::endl;
  std::cout << "lq back element is: " << lq.back() << std::endl;
  lq.pop();
  lq.pop();
  //  aq.pop();   //throw exception : queueEmpty here
}
