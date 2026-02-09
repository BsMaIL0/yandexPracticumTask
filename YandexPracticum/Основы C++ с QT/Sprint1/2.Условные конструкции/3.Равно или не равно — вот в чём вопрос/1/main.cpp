#include <iostream>

int main() {
    int n, m, k;
    std::cin >> n >> m >> k;

    if (n > m && n > k) {
        if (m > k) {
            std::cout << k << " " << n << std::endl;
        }
        else {
            std::cout << m << " " << n << std::endl;
        }
    }
    else if (m > n && m > k) {
        if (n > k) {
            std::cout << k << " " << m << std::endl;
        }
        else {
            std::cout << n << " " << m << std::endl;
        }
    }
    else {
        if (n > m) {
            std::cout << m << " " << k << std::endl;
        }
        else {
            std::cout << n << " " << k << std::endl;
        }
    }

    return 0;
}