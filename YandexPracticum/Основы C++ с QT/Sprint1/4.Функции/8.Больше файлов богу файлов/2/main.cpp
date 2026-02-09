#include <iostream>
#include <string>
#include "string_utils.h"

int main() {
    std::string text, text_to_find;

    std::getline(std::cin, text);
    std::getline(std::cin, text_to_find);

    auto found_positions = FindString(text, text_to_find);
    for (auto pos : found_positions) {
        std::cout << pos << std::endl;
    }
}