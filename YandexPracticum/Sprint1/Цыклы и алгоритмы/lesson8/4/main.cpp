#include <iostream>
#include <string>
#include <cmath>

int main() {
    double result = 0;
    double current = 0;
    double next = 0;
    char op = '+';
    std::string input;

    if (!(std::cin >> current)) {
        std::cerr << "Wrong arg input!" << std::endl;
        return 0;
    }

    while (true) {
        std::cin >> input;

        if (input == "+" || input == "-") {
            if (op == '+') {
                result += current;
            }
            else if (op == '-') {
                result -= current;
            }

            op = input[0];

            std::cin >> current;
        }
        else if (input == "*") {
            std::cin >> next;
            current *= next;
        }
        else if (input == "/") {
            std::cin >> next;
            current /= next;
        }
        else if (input == "=") {
            if (op == '+') {
                result += current;
            }
            else if (op == '-') {
                result -= current;
            }

            std::cout << result << std::endl;
            return 0;
        }
        else {
            std::cerr << "Wrong operation" << std::endl;
            return 0;
        }
    }

    return 0;
}