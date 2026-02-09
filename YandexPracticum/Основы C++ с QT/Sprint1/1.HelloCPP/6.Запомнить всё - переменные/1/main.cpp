#include <iostream>

int main() {
    double x;
    double y;
    std::cin >> x >> y;
    std::cout << "Сумма: " << x + y << std::endl;
    std::cout << "Разность: " << x - y << std::endl;
    std::cout << "Произведение: " << x * y << std::endl;
    std::cout << "Отношение: " << x / y << std::endl;
    return 0;
}