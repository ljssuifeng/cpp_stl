#include <algorithm>
#include <iostream>
#include <iterator>
#include "function.h"

int arr[]{6, 4, 3, 0, 2, 5, 1, 7};
int arrLen = sizeof(arr) / sizeof(arr[0]);

int main() {
  std::cout << "elem 3 index is: " << senquenceSearch(arr, arrLen, 3)
            << std::endl;
  std::cout << "elem 9 index is: " << senquenceSearch(arr, arrLen, 9)
            << std::endl;
  std::cout << "elem 6 index is: " << rSequentialSearch(arr, arrLen, 6)
            << std::endl;

  int* p_rank = new int[arrLen];
  rank(arr, arrLen, p_rank);
  rearrange2(arr, arrLen, p_rank);
  for (auto elem : arr) {
    std::cout << "arr:" << elem << " ";
  }
  std::cout << std::endl;

  std::random_shuffle(std::begin(arr), std::end(arr));
  std::cout << "random shffled: ";
  std::copy(std::begin(arr), std::end(arr),
            std::ostream_iterator<int>(std::cout, " "));
  std::cout << std::endl;

  //  bubbleSort2(arr, arrLen);
  insertionSort2(arr, arrLen);

  std::cout << " sorted: ";
  std::copy(std::begin(arr), std::end(arr),
            std::ostream_iterator<int>(std::cout, " "));
  std::cout << std::endl;

  std::cout << "index of 3 in arr is: " << binarySearch(arr, arrLen, 3)
            << std::endl;
}
