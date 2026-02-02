#include <iostream>

int main() {
    int n, m;
    std::cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if ((i + j) % 2 == 0) {
                std::cout << "o ";
            }
            else {
                std::cout << "x ";
            }
        }
        std::cout << std::endl;
    }
    return 0;
}