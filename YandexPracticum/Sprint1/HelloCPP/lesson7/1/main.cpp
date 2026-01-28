#include <iostream>
#include <cmath>

int main() {
    int first;
    int delta;
    int k;
    int last;
    int sum;

    std::cin >> first >> delta >> k;

    last = first + delta * (k - 1);
    sum = (first + last) * k / 2;

    std::cout << last << std::endl;
    std::cout << sum << std::endl;
}