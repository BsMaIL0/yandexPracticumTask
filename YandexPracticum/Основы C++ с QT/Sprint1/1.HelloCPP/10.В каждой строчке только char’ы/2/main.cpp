#include <string>
#include <iostream>

int main() {
    std::string line;
    int number;
    char ch;

    std::getline(std::cin, line);
    std::cin >> number >> ch;

    line[number] = ch;

    std::cout << line << std::endl;

    return 0;
}