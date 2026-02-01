#include <iostream>
#include <string>

int main() {
    double x, y;
    std::string op;
    std::cin >> x >> op >> y;

    if (!std::cin) {
        std::cerr << "Incorrect input" << std::endl;
        return 0;
    }
    if (op == "+") {
        std::cout << x + y << std::endl;
    }
    else if (op == "-") {
        std::cout << x - y << std::endl;
    }
    else if (op == "*") {
        std::cout << x * y << std::endl;
    }
    else if (op == "/") {
        std::cout << x / y << std::endl;
    }
    else {
        std::cerr << "Incorrect operation" << std::endl;
        return 0;
    }

    return 0;
}