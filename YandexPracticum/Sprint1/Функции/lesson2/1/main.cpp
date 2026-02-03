#include <iostream>
#include <string>
#include <cctype>

void PrintUpper(std::string str) {
    for (char ch : str) {
        std::cout << static_cast<char>(std::toupper(ch));
    }
    std::cout << std::endl;
}

void PrintLower(std::string str) {
    for (char ch : str) {
        std::cout << static_cast<char>(std::tolower(ch));
    }
    std::cout << std::endl;
}

int main() {
    std::string str;
    std::getline(std::cin, str);
    PrintUpper(str);
    PrintLower(str);
}