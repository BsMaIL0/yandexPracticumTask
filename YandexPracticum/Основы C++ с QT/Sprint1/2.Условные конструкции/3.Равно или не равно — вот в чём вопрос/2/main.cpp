#include <iostream>

int main() {
    int n, m, k;
    std::cin >> n >> m >> k;

    if (n >= m && n <= k) {
        std::cout << n << std::endl;
    }
    else if (n >= k && n <= m) {
        std::cout << n << std::endl;
    }
    else if (m >= k && m <= n) {
        std::cout << m << std::endl;
    }
    else if (m >= n && m <= k) {
        std::cout << m << std::endl;
    }
    else if (k >= n && k <= m) {
        std::cout << k << std::endl;
    }
    else {
        std::cout << k << std::endl;
    }

    return 0;
}