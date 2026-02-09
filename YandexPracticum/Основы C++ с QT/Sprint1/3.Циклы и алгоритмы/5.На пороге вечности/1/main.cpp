#include <iostream>
#include <string>
#include <cctype>

int main() {
    std::string line;
    std::getline(std::cin, line);
    bool alpha = false;
    for (char ch : line) {
        if (std::isalpha(ch)) {
            alpha = true;
        }
        else if (std::isdigit(ch)) {
            if (alpha) {
                std::cout << ch;
                return 0;
            }
        }
        else {
            alpha = false;
        }
        std::cout << ch;
    }

    return 0;
}