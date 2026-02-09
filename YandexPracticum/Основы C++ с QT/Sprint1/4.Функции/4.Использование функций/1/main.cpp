#include <cassert>
#include <iostream>

int CharToDigit(char ch) {
    if (ch >= '0' && ch <= '9') {
        return ch - '0';
    }
    else if (ch >= 'A' && ch <= 'Z') {
        return (ch - 'A' + 10);
    }
    else if (ch >= 'a' && ch <= 'z') {
        return (ch - 'a' + 10);
    }
    else {
        return 0;
    }
}

int main() {
    char ch;
    std::cin >> ch;

    // Переводим цифру из char в int.
    const int digit_value = CharToDigit(ch);

    std::cout << digit_value << std::endl;
}