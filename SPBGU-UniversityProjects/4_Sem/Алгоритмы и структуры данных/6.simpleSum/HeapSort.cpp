#include "HeapSort.hpp"

void heapRecovery(double* arr, int n, int i) {
  int smallest = i;
  int left = (2 * i) + 1;
  int right = (2 * i) + 2;

  if (left < n && std::fabs(arr[left]) < std::fabs(arr[smallest])) {
    smallest = left;
  }

  if (right < n && std::fabs(arr[right]) < std::fabs(arr[smallest])) {
    smallest = right;
  }

  if (smallest != i) {
    double tmp = arr[i];
    arr[i] = arr[smallest];
    arr[smallest] = tmp;
    heapRecovery(arr, n, smallest);
  }
}

void buildHeap(double* arr, int n) {
  for (int i = (n / 2) - 1; i >= 0; --i) {
    heapRecovery(arr, n, i);
  }
}

void heapSort(double* arr, int n) {
  buildHeap(arr, n);

  for (int i = n - 1; i > 0; --i) {
    double tmp = arr[0];
    arr[0] = arr[i];
    arr[i] = tmp;
    heapRecovery(arr, i, 0);
  }
}