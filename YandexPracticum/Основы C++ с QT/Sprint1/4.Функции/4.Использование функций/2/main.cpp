#include <cassert>
#include <iostream>
#include <cmath>

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

int StringToNumber(std::string s, int base) {
    int result = 0;
    int n = 0;
    for (int i = s.size() - 1; i >= 0; --i) {
        int tmp = CharToDigit(s[i]);
        result += tmp * std::pow(base, n);
        n++;
    }
    return result;
}

int main() {
    std::string src_string;
    int src_base;

    std::cin >> src_string >> src_base;

    // Переводим число из строкового представления в системе 
    // счисления src_base в int.
    int number = StringToNumber(src_string, src_base);

    // Выводим число в десятичной системе счисления.
    std::cout << number << std::endl;
}