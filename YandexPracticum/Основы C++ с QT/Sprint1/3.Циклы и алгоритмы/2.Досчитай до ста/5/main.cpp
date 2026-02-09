#include <iostream>
#include <string>
#include <cctype>

int main() {
    std::string type; // Тип регистра: upper или lower.
    std::string str;
    std::getline(std::cin, type);
    std::getline(std::cin, str);

    size_t i = 0;
    while (i < str.size()) {
        char letter = str[i];
        if (std::isalpha(letter)) {
            if (type == "lower") {
                letter = tolower(letter);
            }
            else {
                letter = toupper(letter);
            }
            str[i] = letter;
        }
        ++i;
    }
    std::cout << str << std::endl;

    return 0;
}