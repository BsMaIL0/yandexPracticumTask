#include <iostream>

int main() {
    int n;
    std::cin >> n;
    for (size_t i = n; i != 0; --i) {
        std::cout << i << std::endl;
    }
    std::cout << "0" << std::endl;
    std::cout << "GO!" << std::endl;

    return 0;
}