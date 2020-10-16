#ifndef SELECTION_SORT_H
#define SELECTION_SORT_H
#include <algorithm>

template<typename T>
void selection_sort(T arr[], int n) {
  for (int i = 0; i < n; ++i) {
    // find the min element in [0, n)
    int minIndex = i;
    for (int j = i + 1; j < n; j++) {
      if (arr[j] < arr[minIndex]) {
        minIndex = j;
      }
    }
    std::swap(arr[i], arr[minIndex]);
  }
}

#endif
