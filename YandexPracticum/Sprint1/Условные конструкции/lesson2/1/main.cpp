#include <iostream>
#include <string>

int main() {
    std::string line;
    std::cin >> line;
    if (line == "COOLPETYA111") {
        std::cout << "Пароль верный" << std::endl;
    }
    else {
        std::cout << "Пароль неверный" << std::endl;
    }
    return 0;
}