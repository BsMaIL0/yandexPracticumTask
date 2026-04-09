#include <fstream>
#include <iostream>

int arrange(const double* array, int* sorted_ptr, int left, int right);
void quickSort(double* array, int* sorted_ptr, int left, int right);

int main(int argc, char* argv[]) {
  if (argc < 2) {
    std::cerr << "Wrong input" << std::endl;
    return 1;
  }

  std::ifstream in;
  in.open(argv[1]);
  if (!in) {
    std::cerr << "Cannot open input file!" << std::endl;
    return 1;
  }

  int n;
  in >> n;
  double* array = new double[n];
  int* sorted_ptr = new int[n];

  for (int i = 0; i < n; i++) {
    in >> array[i];
    sorted_ptr[i] = i;
  }

  int indexMin = 0;
  int indexMax = 0;

  for (int i = 1; i < n; ++i) {
    if (array[i] < array[indexMin]) {
      indexMin = i;
    }
    if (array[i] > array[indexMax]) {
      indexMax = i;
    }
  }

  quickSort(array, sorted_ptr, 0, n - 1);
  int averageIndex = sorted_ptr[n / 2];

  std::cout << (indexMin + 1) << " " << (averageIndex + 1) << " "
            << (indexMax + 1) << std::endl;

  delete[] sorted_ptr;
  delete[] array;

  return 0;
}

int arrange(const double* array, int* sorted_ptr, int left, int right) {
  int tmp;
  double pivot = array[sorted_ptr[right]];
  int i = left - 1;

  for (int j = left; j < right; j++) {
    if (array[sorted_ptr[j]] <= pivot) {
      i++;
      tmp = sorted_ptr[i];
      sorted_ptr[i] = sorted_ptr[j];
      sorted_ptr[j] = tmp;
    }
  }

  tmp = sorted_ptr[i + 1];
  sorted_ptr[i + 1] = sorted_ptr[right];
  sorted_ptr[right] = tmp;

  return i + 1;
}

void quickSort(double* array, int* sorted_ptr, int left, int right) {
  if (left < right) {
    int p = arrange(array, sorted_ptr, left, right);
    quickSort(array, sorted_ptr, left, p - 1);
    quickSort(array, sorted_ptr, p + 1, right);
  }
}