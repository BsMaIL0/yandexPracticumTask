#include <iostream>

struct Point {
  double x = 0.0;
  double y = 0.0;
};

Point ReadPoint() {
  double x, y;
  std::cin >> x >> y;
  Point result{x, y};
  return result;
}

void PrintPoint(Point p) { std::cout << "{" << p.x << ", " << p.y << "}"; }

int main() {
  Point point = ReadPoint();

  std::cout << "Read point: ";
  PrintPoint(point);
  std::cout << std::endl;

  Point point_symm = {-point.x, -point.y};

  std::cout << "Symmetric point: ";
  PrintPoint(point_symm);
  std::cout << std::endl;
}