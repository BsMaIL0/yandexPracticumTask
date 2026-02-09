#include <iostream>
#include <string>
#include <vector>

int main() {
    using namespace std::literals;

    const std::vector<std::string> num_names = {
        "zero"s,    "one"s,     "two"s,       "three"s,    "four"s,
        "five"s,    "six"s,     "seven"s,     "eight"s,    "nine"s,
        "ten"s,     "eleven"s,  "twelve"s,    "thirteen"s, "fourteen"s,
        "fifteen"s, "sixteen"s, "seventeen"s, "eighteen"s, "nineteen"s
    };

    const std::vector<std::string> tens_names = {
        "twenty"s, "thirty"s, "forty"s, "fifty"s,
        "sixty"s, "seventy"s, "eighty"s, "ninety"s
    };

    int number;
    std::cin >> number;

    // Вычислим единицы и десятки как остаток от деления на 10 и частное:
    int units = number % 10; // Единицы.
    int tens = number / 10; // Десятки.

    if (number < 20) {
        std::cout << num_names[number] << std::endl;
    }
    else if (units == 0) {
        std::cout << tens_names[tens - 2] << std::endl;
    }
    else {
        std::cout << tens_names[tens - 2] << "-" << num_names[units] << std::endl;
    }

    return 0;
}