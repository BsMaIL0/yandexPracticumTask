#include <iostream>

int main() {
    int n;
    std::cin >> n;

    for (int i = 0; i <= n; i += 2) {
        std::cout << i << std::endl;
    }

    return 0;
}