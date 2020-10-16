#ifndef _INSERTION_SORT_H
#define _INSERTION_SORT_H

#include <algorithm>

template <typename T>
void insertion_sort(T arr[], int n) {
  for (int i = 1; i < n; ++i) {
    for (int j = i; j > 0 && arr[j] < arr[j - 1]; --j) {
      std::swap(arr[j], arr[j - 1]);
    }
  }
}

template <typename T>
void insertion_sort2(T arr[], int n) {
  for (int i = 1; i < n; ++i) {
    T temp = arr[i];
    int j = i;
    for (; j > 0 && arr[j - 1] > temp; --j) {
      arr[j] = arr[j - 1];
    }
    arr[j] = temp;
  }
}

template <typename T>
void insertion_sort3(T arr[], int n) {
  for (int i = 1; i < n; ++i) {
    T temp = arr[i];
    int j = i - 1;
    for (; j >= 0 && arr[j] > temp; --j) {
      arr[j + 1] = arr[j];
    }
    arr[j + 1] = temp;
  }
}
#endif
