#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;
    int number;
    std::vector<int> x;
    for (int i = 0; i < n; ++i) {
        std::cin >> number;
        x.push_back(number);
    }
    int k = 0;
    for (int i : x) {
        n = 0;
        for (int j : x) {
            if (i == j) {
                n++;
            }
        }
        if (n == 1) {
            k++;
        }
        n = 0;
    }
    std::cout << k << std::endl;

    return 0;
}