#include <fstream>
#include <iostream>

struct Section {
  int x1;
  int x2;
};

void mergeSortByX1(Section* arr, Section* buf, int left, int right) {
  if (right - left <= 1) {
    return;
  }

  int mid = (left + right) / 2;

  mergeSortByX1(arr, buf, left, mid);
  mergeSortByX1(arr, buf, mid, right);

  int i = left;
  int j = mid;
  int k = left;

  while (i < mid && j < right) {
    if (arr[i].x1 < arr[j].x1) {
      buf[k++] = arr[i++];
    } else if (arr[i].x1 > arr[j].x1) {
      buf[k++] = arr[j++];
    } else {
      if (arr[i].x2 > arr[j].x2) {
        buf[k++] = arr[i++];
      } else {
        buf[k++] = arr[j++];
      }
    }
  }
  while (i < mid) {
    buf[k++] = arr[i++];
  }
  while (j < right) {
    buf[k++] = arr[j++];
  }

  for (int idx = left; idx < right; idx++) {
    arr[idx] = buf[idx];
  }
}

void mergeSortByX2(Section* arr, Section* buf, int left, int right) {
  if (right - left <= 1) {
    return;
  }

  int mid = (left + right) / 2;

  mergeSortByX2(arr, buf, left, mid);
  mergeSortByX2(arr, buf, mid, right);

  int i = left;
  int j = mid;
  int k = left;
  while (i < mid && j < right) {
    if (arr[i].x2 < arr[j].x2) {
      buf[k++] = arr[i++];
    } else if (arr[i].x2 > arr[j].x2) {
      buf[k++] = arr[j++];
    } else {
      if (arr[i].x1 < arr[j].x1) {
        buf[k++] = arr[i++];
      } else {
        buf[k++] = arr[j++];
      }
    }
  }
  while (i < mid) {
    buf[k++] = arr[i++];
  }
  while (j < right) {
    buf[k++] = arr[j++];
  }

  for (int idx = left; idx < right; idx++) {
    arr[idx] = buf[idx];
  }
}

long long countInversions(int* arr, int* buf, int left, int right) {
  if (right - left <= 1) {
    return 0;
  }

  int mid = (left + right) / 2;

  long long invCount = 0;
  invCount += countInversions(arr, buf, left, mid);
  invCount += countInversions(arr, buf, mid, right);

  int i = left;
  int j = mid;
  int k = left;
  while (i < mid && j < right) {
    if (arr[i] <= arr[j]) {
      buf[k++] = arr[i++];
    } else {
      invCount += (mid - i);
      buf[k++] = arr[j++];
    }
  }
  while (i < mid) {
    buf[k++] = arr[i++];
  }
  while (j < right) {
    buf[k++] = arr[j++];
  }

  for (int idx = left; idx < right; idx++) {
    arr[idx] = buf[idx];
  }

  return invCount;
}

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

  int n;
  in >> n;

  Section* line = new Section[n];
  for (int i = 0; i < n; ++i) {
    in >> line[i].x1 >> line[i].x2;
  }
  in.close();

  Section* tmp = new Section[n];

  mergeSortByX1(line, tmp, 0, n);

  int* x2Values = new int[n];
  for (int i = 0; i < n; ++i) {
    x2Values[i] = line[i].x2;
  }

  int* invBuf = new int[n];
  long long result = countInversions(x2Values, invBuf, 0, n);

  Section* byX2 = new Section[n];
  for (int i = 0; i < n; ++i) {
    byX2[i] = line[i];
  }
  Section* tmp2 = new Section[n];
  mergeSortByX2(byX2, tmp2, 0, n);

  int sameX2Count = 1;
  for (int i = 1; i < n; ++i) {
    if (byX2[i].x2 == byX2[i - 1].x2) {
      sameX2Count++;
    } else {
      if (sameX2Count > 1) {
        result += (long long)sameX2Count * (sameX2Count - 1) / 2;
      }
      sameX2Count = 1;
    }
  }
  if (sameX2Count > 1) {
    result += (long long)sameX2Count * (sameX2Count - 1) / 2;
  }

  std::cout << result << std::endl;

  delete[] line;
  delete[] tmp;
  delete[] x2Values;
  delete[] invBuf;
  delete[] byX2;
  delete[] tmp2;

  return 0;
}