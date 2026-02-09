#include <iostream>

int main() {
    int max = -9999;
    int min = 9999;
    int n;
    std::cin >> n;
    int number;
    for (int i = 0; i < n; i++) {
        std::cin >> number;
        if (number > max) {
            max = number;
        }
        if (number < min) {
            min = number;
        }
    }
    std::cout << min << " " << max << std::endl;

    return 0;
}