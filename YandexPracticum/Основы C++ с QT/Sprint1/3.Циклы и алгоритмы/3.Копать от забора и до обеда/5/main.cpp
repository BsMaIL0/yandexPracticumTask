#include <iostream>

int main() {
    int a, b;
    std::cin >> a >> b;

    if (a < b) {
        for (int i = a; i <= b; ++i) {
            if (i % 2 != 0) {
                std::cout << i << std::endl;
            }
        }
    }
    else {
        for (int i = a; i >= b; --i) {
            if (i % 2 != 0) {
                std::cout << i << std::endl;
            }
        }
    }

    return 0;
}