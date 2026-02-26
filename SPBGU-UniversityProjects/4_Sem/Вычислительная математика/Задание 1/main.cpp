#include <iostream>
#include <cmath>
#include <clocale>// для setlocale

int main() {
  double x_max = 0.3;
  double x_min = 0.2;
  double step = 0.01;

  setlocale(LC_ALL, "Russian"); //Вывод в консоль на русском языке

  std::cout << "Задание №13.\n"<<
	  "z(x) = sqrt(1 +x^2)*(sin(3x + 0.1) + cos(2x + 0.3)),x = 0.2(0.01)0.3\n"<<std::endl;
  std::cout << "1. Решение обратной задачи теории погрешностей\n" << std::endl;

  std::cout << "1.1 Разбиваем функцию на отдельные подфункции:" << R"(
z(x) = f(u, v, w) = w · (u + v)
где:
	u = sin(3x + 0.1)
	v = cos(2x + 0.3)
	w = sqrt(1 + x^2)
)" << std::endl;

  std::cout << "1.2 Ищу диапазоны изменения аргументов:" << std::endl;
  double arg_sin_min = 3 * x_min + 0.1;
  double arg_sin_max = 3 * x_max + 0.1;
  std::cout << "Для (3x + 0.1) = [" << arg_sin_min << ',' << arg_sin_max << "]."
            << std::endl;
  double arg_cos_min = 2 * x_min + 0.3;
  double arg_cos_max = 2 * x_max + 0.3;
  std::cout << "Для (2x + 0.3) = [" << arg_cos_min << ',' << arg_cos_max << "]."
            << std::endl;
  double arg_sqrt_min = 1 + x_min * x_min;
  double arg_sqrt_max = 1 + x_max * x_max;
  std::cout << "Для sqrt(1 + x^2) = [" << arg_sqrt_min << ',' << arg_sqrt_max << "]."
            << std::endl;


};