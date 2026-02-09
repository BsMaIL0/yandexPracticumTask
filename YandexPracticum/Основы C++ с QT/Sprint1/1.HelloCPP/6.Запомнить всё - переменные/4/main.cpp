#include <iostream>
#include <cmath>

int main() {
    double farg;
    double cels;

    std::cout << "Введите температуру в градусах Фаренгейта:" << std::endl;
    std::cin >> farg;

    cels = (farg - 32) * 5 / 9;
    cels = cels * 10;
    cels = std::round(cels) / 10;

    std::cout << "Температура в градусах Цельсия: " << cels << std::endl;

    return 0;
}