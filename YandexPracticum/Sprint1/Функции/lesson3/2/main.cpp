#include <iostream>

unsigned long long GetFactorial(int n) {
    unsigned long long result = 1;
    if (n == 0 || n == 1) {
        return 1ULL;
    }
    for (size_t i = 2; i <= n; ++i) {
        result = i * result;
    }
    return result;
}

int main() {
    int n;
    std::cin >> n;
    std::cout << GetFactorial(n) << std::endl;
}