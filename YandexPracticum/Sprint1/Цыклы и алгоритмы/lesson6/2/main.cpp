#include <iostream>
#include <vector>
#include <string>

int main() {
    int n, k;
    std::cin >> n;
    std::vector<std::string> vector;
    std::cin.ignore();
    for (int i = 0; i < n; ++i) {
        std::string line;
        std::getline(std::cin, line);
        vector.push_back(line);
    }
    --n;
    std::cin >> k;
    for (; k != 0; --k) {
        std::cout << n << " " << vector[n] << std::endl;
        --n;
    }

    return 0;
}