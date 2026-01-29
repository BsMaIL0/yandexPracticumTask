#include <string>
#include <iostream>

int main() {
    std::string line;
    std::getline(std::cin, line);

    int pos;
    std::cin >> pos;

    std::cout << line[pos - 1] << line[pos] << line[pos + 1] << std::endl;

    return 0;
}