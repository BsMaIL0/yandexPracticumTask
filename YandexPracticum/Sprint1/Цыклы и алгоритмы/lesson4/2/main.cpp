#include <iostream>

int main() {
    int n;
    std::cin >> n;
    if (n < 1 || n>63) {
        std::cout << "Wrong input" << std::endl;
        return 0;
    }
    unsigned long long result = 1;
    for (int i = 0; i < n; ++i) {
        if (i != 0) {
            std::cout << ", ";
        }
        result = result * 2;
        std::cout << result;
    }

    return 0;
}