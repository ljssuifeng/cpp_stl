#include "my_stack_class.hpp"
#include <exception>
#include <iostream>

int main() {
  try {
    MyStack<int> st;
    // push three elements into the stack
    st.push(1);
    st.push(2);
    st.push(3);

    // pop and print elements from the stack
    std::cout << st.pop() << ' ';
    std::cout << st.pop() << ' ';

    // modify top element
    st.top() = 77;
    // push two new elements
    st.push(4);
    st.push(5);

    // pop one element without processing it
    st.pop();

    // pop and print three elements
    //-ERROR: one element too many
    std::cout << st.pop() << ' ';
    std::cout << st.pop() << std::endl;
    std::cout << st.pop() << std::endl;
  } catch (const std::exception& e) {
    std::cerr << "Exception: " << e.what() << std::endl;
  }
}
