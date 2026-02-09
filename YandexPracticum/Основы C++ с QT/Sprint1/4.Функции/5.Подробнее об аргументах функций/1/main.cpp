#include <cassert>
#include <iostream>
#include <cmath>

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
    assert(base >= MIN_BASE && base <= MAX_BASE);

    std::string str;
    do {
        int digit = number % base;  // Вычленяем последнюю цифру числа.
        str = DigitToChar(digit) + str;
        number = number / base;  // Отбрасываем последнюю цифру.
    } while (number != 0);       // Повторяем, пока не дошли до нуля.

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

// Преобразовывает число src_number, записанное в системе счисления src_base,
// в строковое представление этого же числа в системе счисления dst_base.
std::string ConvertNotation(std::string src_number, int src_base, int dst_base) {
    return NumberToString(StringToNumber(src_number, src_base), dst_base);
}

int main() {
    std::string src_string;
    int src_base, dst_base;

    std::cin >> src_string >> src_base >> dst_base;

    std::cout << ConvertNotation(src_string, src_base, dst_base) << std::endl;
}