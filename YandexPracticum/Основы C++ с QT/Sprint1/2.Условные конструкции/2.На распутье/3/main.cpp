#include <iostream>

int main() {
    int x;
    int y;

    std::cin >> x >> y;

    if (x > y) {
        std::cout << "Число " << x << " больше" << std::endl;
    }
    else if (x == y) {
        std::cout << "Числа равны" << std::endl;
    }
    else {
        std::cout << "Число " << y << " больше" << std::endl;
    }

    return 0;
}