#include <iostream>

int main() {
    double farg;
    double cels;

    std::cout << "Введите температуру в градусах Фаренгейта:" << std::endl;
    std::cin >> farg;

    cels = (farg - 32) * 5 / 9;

    std::cout << "Температура в градусах Цельсия: " << cels << std::endl;

    return 0;
}