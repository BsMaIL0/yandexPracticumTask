#include <iostream>

int main() {
    int x;
    std::cin >> x;

    if (x % 2 == 0) {
        std::cout << "Число " << x << " чётное" << std::endl;
    }
    else {
        std::cout << "Число " << x << " нечётное" << std::endl;
    }

    return 0;
}