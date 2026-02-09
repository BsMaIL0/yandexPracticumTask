#include <iostream>

int main() {
    int a, b;
    std::cin >> a >> b;

    if (a != 0) {
        double x = static_cast<double>(-b) / a;
        std::cout << x << std::endl;
    }
    else if (a == 0 && b == 0) {
        std::cout << "бесконечное число корней" << std::endl;
    }
    else {
        std::cout << "нет корней" << std::endl;
    }

    return 0;
}