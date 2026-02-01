#include <iostream>
#include <string>

int main() {
    std::string line;
    std::getline(std::cin, line);

    // Слово const перед типом показывает, что мы
    // не будем менять значение переменной.
    const std::string correct_symbols =
        "abcdefghijklmnopqrstuvwxyz"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "0123456789._-+@";
    size_t sobaka_pos = line.find("@");
    if (sobaka_pos == std::string::npos) {
        std::cout << "Некорректный email" << std::endl;
        return 0;
    }
    if (line.find("@", sobaka_pos + 1) != std::string::npos) {
        std::cout << "Некорректный email" << std::endl;
        return 0;
    }
    if (line.find(".", sobaka_pos + 1) == std::string::npos || line[sobaka_pos + 1] == '.') {
        std::cout << "Некорректный email" << std::endl;
        return 0;
    }
    if (line.rfind(".") == line.size() - 1) {
        std::cout << "Некорректный email" << std::endl;
        return 0;
    }
    if (line.find_first_not_of(correct_symbols) != std::string::npos) {
        std::cout << "Некорректный email" << std::endl;
        return 0;
    }

    std::cout << "Корректный email" << std::endl;
    return 0;
}