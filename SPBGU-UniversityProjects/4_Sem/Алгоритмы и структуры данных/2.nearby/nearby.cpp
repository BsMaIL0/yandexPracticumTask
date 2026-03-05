#include <cmath>
#include <fstream>
#include <iostream>

int find_closest(int* sorted_array, int n, int x);

int main(int argc, char* argv[]) {
  if (argc != 3) {
    std::cerr << "Needs two file's names\n";
    return 1;
  }

  std::ifstream in(argv[1]);
  std::ofstream out(argv[2]);

  if (!in) {
    std::cerr << "Cannot open input file!\n";
    return 1;
  }
  if (!out) {
    std::cerr << "Cannot open output file!\n";
    return 1;
  }

  char bom[3] = {0};
  in.read(bom, 3);
  if (bom[0] != '\xEF' || bom[1] != '\xBB' || bom[2] != '\xBF') {
    in.seekg(0);
  }

  int n;
  int k;
  in >> n >> k;

  int* sorted_array = new int[n];

  for (int i = 0; i < n; ++i) {
    in >> sorted_array[i];
  }

  for (int i = 0; i < k; ++i) {
    int query;
    in >> query;
    out << find_closest(sorted_array, n, query) << '\n';
  }

  delete[] sorted_array;

  return 0;
}

int find_closest(int* sorted_array, int n, int x) {
  if (x <= sorted_array[0]) {
    return sorted_array[0];
  }
  if (x >= sorted_array[n - 1]) {
    return sorted_array[n - 1];
  }

  int left = 0;
  int right = n - 1;

  while (left <= right) {
    int mid = left + ((right - left) / 2);

    if (sorted_array[mid] == x) {
      return x;
    }

    if (sorted_array[mid] < x) {
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }

  if (right < 0) {
    return sorted_array[left];
  }

  if (left >= n) {
    return sorted_array[right];
  }

  long long left_diff =
      static_cast<long long>(x) - static_cast<long long>(sorted_array[right]);
  long long right_diff =
      static_cast<long long>(sorted_array[left]) - static_cast<long long>(x);

  if (left_diff < right_diff) {
    return sorted_array[right];
  }

  if (right_diff < left_diff) {
    return sorted_array[left];
  }

  if (sorted_array[right] < sorted_array[left]) {
    return sorted_array[right];
  }

  return sorted_array[left];
}
