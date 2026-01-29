#include <string>
#include <iostream>

int main() {
    int x;
    int y;

    std::cin >> x >> y;

    std::string line;
    line = std::to_string(x) + std::to_string(y);

    std::cout << x + y << std::endl;
    std::cout << line << std::endl;
    std::cout << std::stoi(line) - x - y << std::endl;

    return 0;
}