#ifndef _PROGRAM_PERFORMANCE_H
#define _PROGRAM_PERFORMANCE_H
#include <algorithm>

template <typename T>
int senquenceSearch(T a[], int n, const T& x) {
  int i = 0;
  for (i = 0; i < n && a[i] != x; ++i) {
    ;
  }
  if (i == n) {
    return -1;
  } else {
    return i;
  }
}

template <typename T>
int rSequentialSearch(T a[], int n, const T& x) {
  if (n < 1) return -1;
  if (a[n - 1] == x) return n - 1;
  return rSequentialSearch(a, n - 1, x);
}

template <typename T>
void rank(T a[], int n, int r[]) {
  for (int i = 0; i < n; ++i) {
    r[i] = 0;
  }
  for (int i = 1; i < n; ++i) {
    for (int j = 0; j < i; ++j) {
      if (a[i] <= a[j])
        r[j]++;
      else
        r[i]++;
    }
  }
}

template <typename T>
void rearrange(T a[], int n, int r[]) {
  T* u = new T[n];
  for (int i = 0; i < n; ++i) {
    u[r[i]] = a[i];
  }
  // move elem in u to a
  for (int i = 0; i < n; ++i) {
    a[i] = u[i];
  }
  delete[] u;
}

template <typename T>
void rearrange2(T a[], int n, int r[]) {
  for (int i = 0; i < n; ++i) {
    if (r[i] != i) {
      for (int k = 0; k < n; ++k) {
        if (r[k] == i) {
          std::swap(a[i], a[k]);
          std::swap(r[i], r[k]);
          break;
        }
      }
    }
  }
}

template <typename T>
int indexOfMax(T a[], int n) {
  int max_index = 0;
  for (int i = 1; i < n; ++i) {
    if (a[i] > a[max_index]) {
      max_index = i;
    }
  }
  return max_index;
}

template <typename T>
void selectionSort(T a[], int n) {
  for (int size = n; size > 1; size--) {
    int index_max = indexOfMax(a, size);
    std::swap(a[index_max], a[size - 1]);
  }
}
template <typename T>
void bubble(T a[], int n) {
  for (int i = 0; i < n - 1; ++i) {
    if (a[i] > a[i + 1]) {
      std::swap(a[i], a[i + 1]);
    }
  }
}

template <typename T>
bool bubble2(T a[], int n) {
  bool swapped = false;
  for (int i = 0; i < n - 1; ++i) {
    if (a[i] > a[i + 1]) {
      std::swap(a[i], a[i + 1]);
      swapped = true;
    }
  }
  return swapped;
}

template <typename T>
void bubbleSort(T a[], int n) {
  for (int i = n; i > 1; i--) {
    bubble(a, i);
  }
}

template <typename T>
void bubbleSort2(T a[], int n) {
  for (int i = n; i > 1 && bubble2(a, i); i--)
    ;
}

template <typename T>
void insert(T a[], int n, const T& x) {
  int i;
  for (i = n - 1; i >= 0 && x < a[i]; --i) {
    a[i + 1] = a[i];
  }
  a[i + 1] = x;
}

template <typename T>
void insertionSort(T a[], int n) {
  for (int i = 1; i < n; ++i) {
    insert(a, i, a[i]);
  }
}

template <typename T>
void insertionSort2(T a[], int n) {
  for (int i = 1; i < n; ++i) {
    T temp = a[i];
    int k;
    for (k = i - 1; k >= 0 && temp < a[k]; --k) {
      a[k + 1] = a[k];
    }
    a[k + 1] = temp;
  }
}

template <typename T>
void selectionSort2(T a[], int n) {
  bool sorted = false;
  for (int size = n; !sorted && (size > 1); --size) {
    int indexOfMax = 0;
    sorted = true;
    for (int i = 1; i < size; ++i) {
      if (a[indexOfMax] < a[i])
        indexOfMax = i;
      else  // unordered
        sorted = false;
    }
    std::swap(a[indexOfMax], a[size - 1]);
  }
}

template <typename T>
int binarySearch(T a[], int n, const T& x) {
  int left = 0, right = n - 1;
  int middle;
  while (left <= right) {
    middle = (left + right) / 2;
    if (a[middle] == x) return middle;
    if (a[middle] > x)
      right = middle - 1;
    else if (a[middle] < x)
      left = middle + 1;
  }
  return -1;
}

#endif
