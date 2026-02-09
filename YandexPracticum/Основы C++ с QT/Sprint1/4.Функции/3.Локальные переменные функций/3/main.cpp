#include <iostream>

unsigned long long GetFibonacci(int n) {
    unsigned long long result = 0;
    unsigned long long prev = 1;
    unsigned long long now = 1;
    if (n == 0) {
        return 0;
    }
    if (n == 1 || n == 2) {
        return 1;
    }
    for (size_t i = 3; i <= n; ++i) {
        result = now;
        now = prev + now;
        prev = result;
        result = now;
    }
    return result;
}

int main() {
    int n;
    std::cin >> n;
    std::cout << GetFibonacci(n) << std::endl;
}