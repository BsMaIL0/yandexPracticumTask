#include <iostream>

int main() {
    int x;

    std::cin >> x;

    std::cout << R"(Эники, беники ели вареники,
Эники, беники съели вареники,
Эники, беники, хоп!)" << std::endl;

    std::cout << 10 % x << std::endl;

    return 0;
}