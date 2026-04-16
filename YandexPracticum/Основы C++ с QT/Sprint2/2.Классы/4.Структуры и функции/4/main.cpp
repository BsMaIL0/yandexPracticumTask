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

void PrintVector(Vector2D v) { std::cout << "(" << v.x << ", " << v.y << ")"; }

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

Point GetCenter(const Triangle& t) {
  double x = (t.p1.x + t.p2.x + t.p3.x) / 3;
  double y = (t.p1.y + t.p2.y + t.p3.y) / 3;
  return Point{x, y};
}

void MovePoint(Point& p, Vector2D v) {
  p.x += v.x;
  p.y += v.y;
}

void MoveTriangle(Triangle& t, Vector2D v) {
  MovePoint(t.p1, v);
  MovePoint(t.p2, v);
  MovePoint(t.p3, v);
}

void PrintTriangle(const Triangle& t) {
  std::cout << "{";
  PrintPoint(t.p1);
  std::cout << ", ";
  PrintPoint(t.p2);
  std::cout << ", ";
  PrintPoint(t.p3);
  std::cout << "}";
}

int main() {
  Triangle t = ReadTriangle();

  // Исходный центр треугольника.
  Point origin = GetCenter(t);

  // Читаем желаемый центр треугольника.
  Point center = ReadPoint();

  // Находим смещение центра треугольника.
  Vector2D offset = PointDifference(center, origin);

  std::cout << "Исходный центр: ";
  PrintPoint(origin);
  std::cout << std::endl;

  std::cout << "Смещение: ";
  PrintVector(offset);
  std::cout << std::endl;

  MoveTriangle(t, offset);
  PrintTriangle(t);
  std::cout << std::endl;
}