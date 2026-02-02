#include <iostream>
#include <string>
#include <cctype>

int main() {
    std::string line;
    std::getline(std::cin, line);

    bool digit = false;
    int counter = 0;

    for (int i = 0; i < line.size(); i++) {
        if (std::isdigit(line[i])) {
            if (!digit) {
                digit = true;
                counter++;
            }
        }
        else {
            digit = false;
        }
    }

    std::cout << counter << std::endl;

    return 0;
}