#include <cassert>
#include <iostream>
#include <cmath>
#include <string>

const int MIN_BASE = 2;
const int MAX_BASE = 36;

// Переводит цифру из числового представления в символьное.
// Если digit находится в диапазоне 0..9, возвращает символ '0'..'9'.
// Если digit находится в диапазоне 10..35, возвращает символ 'A'..'Z'.
// В остальных случае возвращает символ '?'.
char DigitToChar(int digit) {
    if (digit < 0 || digit >= MAX_BASE) {
        return '?';
    }
    return static_cast<char>(digit <= 9 ? '0' + digit : (digit - 10) + 'A');
}

// Преобразует число number в строковое представление
// в системе счисления по основанию base.
// Гарантируется, что base лежит в диапазоне от 2 до 36.
std::string NumberToString(int number, int base) {
    if (base < 2 || base > 36) {
        return "";
    }

    std::string str;
    if (number == 0) {
        return "0";
    }

    bool is_negative = false;
    if (number < 0) {
        is_negative = true;
        number = -number;
    }

    do {
        int digit = number % base;
        str = DigitToChar(digit) + str;
        number = number / base;
    } while (number != 0);

    if (is_negative) {
        str = "-" + str;
    }

    return str;
}

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
        return -1;
    }
}

int StringToNumber(const std::string& s, int base, bool& was_error) {
    was_error = false;

    if (base < 2 || base > 36) {
        was_error = true;
        return 0;
    }

    if (s.empty()) {
        was_error = true;
        return 0;
    }

    int result = 0;
    int power = 1;
    bool is_negative = false;

    size_t start_index = 0;
    if (s[0] == '-') {
        is_negative = true;
        start_index = 1;
        if (s.length() == 1) {
            was_error = true;
            return 0;
        }
    }

    for (int i = static_cast<int>(s.length()) - 1; i >= static_cast<int>(start_index); --i) {
        int digit = CharToDigit(s[i]);

        if (digit == -1) {
            was_error = true;
            return 0;
        }
        if (digit >= base) {
            was_error = true;
            return 0;
        }

        result += digit * power;
        power *= base;
    }

    if (is_negative) {
        result = -result;
    }

    return result;
}

std::string ConvertNotation(const std::string& src_number, int src_base, int dst_base) {
    bool was_error = false;

    int number = StringToNumber(src_number, src_base, was_error);
    if (was_error) {
        return "";
    }

    std::string result = NumberToString(number, dst_base);
    if (result.empty()) {
        return "";
    }

    return result;
}

int main() {
    using namespace std::literals;
    std::string src_string;
    int src_base, dst_base;

    std::cin >> src_string >> src_base >> dst_base;

    std::string result = ConvertNotation(src_string, src_base, dst_base);

    if (!result.empty()) {
        std::cout << result << std::endl;
    }
    else {
        std::cout << "ERROR"s << std::endl;
    }

    return 0;
}