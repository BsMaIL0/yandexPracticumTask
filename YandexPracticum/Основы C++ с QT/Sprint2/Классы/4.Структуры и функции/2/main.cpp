#include <cmath>
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

struct Vector2D {
  double x = 0.0;
  double y = 0.0;
};

Vector2D PointDifference(Point p1, Point p2) {
  double tmp_x = p2.x - p1.x;
  double tmp_y = p2.y - p1.y;
  return Vector2D{tmp_x, tmp_y};
}

void PrintVector(Vector2D v) { std::cout << "(" << v.x << ", " << v.y << "}"; }

double FindLength(Vector2D v) { return std::hypot(v.x, v.y); }

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