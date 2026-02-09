#include <iostream>
#include <string>

int main() {
    std::string lit;
    std::getline(std::cin, lit);
    for (int i = 1; i < lit.size() - 1; ++i) {
        if (lit[i] == '\\' && lit[i + 1] == 'n') {
            i = i + 1;
            std::cout << "\n";
        }
        else if (lit[i] == '\\' && lit[i + 1] == '\\') {
            i = i + 1;
            std::cout << "\\";
        }
        else if (lit[i] == '\\' && lit[i + 1] == '\"') {
            ++i;
            std::cout << "\"";
        }
        else if (lit[i] == '\\' && lit[i + 1] == '0') {
            return 0;
        }
        else {
            std::cout << lit[i];
        }
    }
    return 0;
}