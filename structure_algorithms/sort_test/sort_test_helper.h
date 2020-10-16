#ifndef _SORT_TEST_HELPER_H
#define _SORT_TEST_HELPER_H
#include <cassert>
#include <ctime>
#include <iostream>

namespace SortTestHelper {
int* generateRandomArray(int n, int rangeL, int rangeR) {
  assert(rangeL < rangeR);
  int* arr = new int[n];
  srand(std::time(nullptr));
  for (int i = 0; i < n; ++i) {
    arr[i] = rand() % (rangeR - rangeL + 1) + rangeL;
  }
  return arr;
}
int* copyIntArray(int* a, int n) {
  int* arr = new int[n];
  std::copy(a, a + n, arr);
  return arr;
}

void printArray(int* arr, int n) {
  for (int i = 0; i < n; ++i) {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;
}
template <typename T>
bool isSorted(T arr[], int n) {
  for (int i = 0; i < n - 1; ++i) {
    if (arr[i] > arr[i + 1]) {
      return false;
    }
  }
  return true;
}
template <typename T>
void testSort(std::string sort_name, void (*sort)(T arr[], int n), T arr[],
              int n) {
  std::clock_t startTime = std::clock();
  sort(arr, n);
  std::clock_t endTime = std::clock();
  assert(isSorted(arr, n));
  std::cout << sort_name << ": " << double(endTime - startTime) / CLOCKS_PER_SEC
            << "s" << std::endl;
  return;
}

int* generateNearlyOrderedArray(int n, int swapTimes) {
  int* arr = new int[n];
  for (int i = 0; i < n; ++i) {
    arr[i] = i;
  }
  srand(std::time(nullptr));
  for (int i = 0; i < swapTimes; ++i) {
    int posx = std::rand() % n;
    int posy = std::rand() % n;
    std::swap(arr[posx], arr[posy]);
  }
  return arr;
}
}

#endif
