#include <iostream>

int main() {
    int i;
    std::cin >> i;

    do {
        std::cout << i % 10;
        i = i / 10;
    } while (i != 0);

    std::cout << std::endl;

    return 0;
}