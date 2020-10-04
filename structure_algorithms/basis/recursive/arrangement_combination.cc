#include <algorithm>
#include <iostream>
#include <iterator>

template <typename T>
void permutation(T list[], int k, int m) {
  if (k == m) {
    std::copy(list, list + m + 1, std::ostream_iterator<T>(std::cout, " "));
    std::cout << std::endl;
  } else {
    for (int i = k; i <= m; ++i) {
      std::swap(list[k], list[i]);
      permutation(list, k + 1, m);
      std::swap(list[k], list[i]);
    }
  }
}

int main() {
  char arr[] = {'a', 'b', 'c', 'd'};
  //  std::cout<<(sizeof(arr) / sizeof(arr[0])) <<std::endl;
  permutation<char>(arr, static_cast<int>(0), sizeof(arr) / sizeof(arr[0]) - 1);
}
