#include <iostream>
#include <string>

std::string ToLower(std::string str) {
    std::string result = "";
    for (char ch : str) {
        result += std::tolower(ch);
    }
    return result;
}

std::string ToUpper(std::string str) {
    std::string result = "";
    for (char ch : str) {
        result += std::toupper(ch);
    }
    return result;
}

int main() {
    std::string str;
    std::getline(std::cin, str);

    std::cout << "Upper: " << ToUpper(str) << std::endl;
    std::cout << "Lower: " << ToLower(str) << std::endl;
}