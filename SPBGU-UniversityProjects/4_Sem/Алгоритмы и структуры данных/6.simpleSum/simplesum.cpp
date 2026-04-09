#include <fstream>
#include <iomanip>
#include <iostream>

#include "HeapSort.hpp"

int main(int argc, char* argv[]) {
  if (argc != 2) {
    std::cerr << "Wrong input!" << std::endl;
    return 1;
  }
  std::ifstream in;
  in.open(argv[1]);
  if (!in) {
    std::cerr << "Cannot open input file!" << std::endl;
    return 1;
  }

  int N;
  in >> N;

  double* array = new double[N];

  for (int i = 0; i < N; ++i) {
    in >> array[i];
  }

  heapSort(array, N);

  double sum = 0;
  double c = 0;
  for (int i = 0; i < N; ++i) {
    double y = array[i] - c;
    double t = sum + y;
    c = (t - sum) - y;
    sum = t;
  }

  std::cout << std::scientific
            << std::setprecision(std::numeric_limits<double>::max_digits10)
            << sum << "\n";

  delete[] array;
}