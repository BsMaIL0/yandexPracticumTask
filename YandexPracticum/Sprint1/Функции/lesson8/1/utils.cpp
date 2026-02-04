#include "utils.h"
#include <string>
#include <iostream>

char ToUpper(unsigned char ch) {
    return static_cast<char>(std::toupper(ch));
}

std::string ToUpper(std::string s) {
    for (char& ch : s) {
        ch = ToUpper(ch);
    }
    return s;
}

std::string ReadString() {
    std::string line;
    std::getline(std::cin, line);
    return line;
}

int ReadInteger() {
    std::string s = ReadString();
    return std::stoi(s);
}