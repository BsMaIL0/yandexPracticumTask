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

struct Triangle {
  Point p1{0, 0};
  Point p2{0, 0};
  Point p3{0, 0};
};

Triangle ReadTriangle() {
  double x1, y1, x2, y2, x3, y3;
  std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
  return Triangle{Point{x1, y1}, Point{x2, y2}, Point{x3, y3}};
}

double FindPerimeter(const Triangle& t) {
  Vector2D a = PointDifference(t.p1, t.p2);
  Vector2D b = PointDifference(t.p1, t.p3);
  Vector2D c = PointDifference(t.p2, t.p3);
  return FindLength(a) + FindLength(b) + FindLength(c);
}

int main() {
  Triangle t = ReadTriangle();
  std::cout << FindPerimeter(t) << std::endl;
}