#include <iostream>

int main() {
    int n;
    int number;
    double summ = 0;

    std::cin >> n;

    for (int i = 0; i < n; i++) {
        std::cin >> number;
        summ += number;
    }

    summ = summ / n;

    std::cout << summ;

    return 0;
}