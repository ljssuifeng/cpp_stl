#ifndef _BUBBLE_SORT_H
#define _BUBBLE_SORT_H

#include <algorithm>

template <typename T>
void bubbleSort(T arr[], int n) {
  for (int i = n - 1; i >= 0; --i) {
    bool swapFlag = false;
    for (int j = 0; j < i; ++j) {
      if (arr[j + 1] < arr[j]) {
        std::swap(arr[j], arr[j + 1]);
        swapFlag = true;
      }
    }
    if (!swapFlag) {
      std::cout << "sort finished advance!" << std::endl;
      break;
    }
  }
}

#endif
