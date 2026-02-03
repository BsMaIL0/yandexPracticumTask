#include <iostream>
#include <string>
#include <cmath>

int main() {
    // Число калькулятора.
    double number;
    std::string ch;
    double number2;

    if (!(std::cin >> number)) {
        std::cerr << "Error: Numeric operand expected" << std::endl;
        return 0;
    }
    else {
        while (true) {
            std::cin >> ch;
            if (ch == "q") {
                return 0;
            }
            else if (ch == "+") {
                if (!(std::cin >> number2)) {
                    std::cerr << "Error: Numeric operand expected" << std::endl;
                    return 0;
                }
                number = number + number2;
                std::cout << number << std::endl;
            }
            else {
                std::cerr << "Error: Unknown token " << ch << std::endl;
                return 0;
            }
        }
    }
    return 0;
}