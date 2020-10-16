#include <iostream>
#include <string>
#include "bubble_sort.h"
#include "insertion_sort.h"
#include "selection_sort.h"
#include "selection_sort.h"
#include "sort_test_helper.h"
#include "student.h"

int main() {
  int a[10] = {0, 9, 8, 7, 6, 5, 4, 3, 2, 1};
  selection_sort(a, 10);
  for (auto elem : a) {
    std::cout << elem << std::endl;
  }
  float b[4] = {4.4, 3.3, 2.2, 1.1};
  selection_sort(b, 4);
  for (auto elem : b) {
    std::cout << elem << std::endl;
  }
  std::string c[4] = {"D", "C", "B", "A"};
  selection_sort(c, 4);
  for (auto elem : c) {
    std::cout << elem << std::endl;
  }

  Student d[4] = {{"D", 90}, {"C", 100}, {"B", 95}, {"A", 95}};
  selection_sort(d, 4);
  for (auto elem : d) {
    std::cout << elem;
  }

  int n = 10000;
  //  int *arr = SortTestHelper::generateRandomArray(n, 0, n);
  int *arr = SortTestHelper::generateNearlyOrderedArray(n, 20);
  int *arr2 = SortTestHelper::copyIntArray(arr, n);

  //  selection_sort(arr, n);
  //  SortTestHelper::testSort("selection_sort", selection_sort, arr, n);
  SortTestHelper::testSort("insertion_sort2", insertion_sort2, arr2, n);
  SortTestHelper::testSort("bubble_sort", bubbleSort, arr, n);
  //  SortTestHelper::printArray(arr, n);
  delete[] arr;
  delete[] arr2;
}
