#include <cassert>
#include <cctype>
#include <string>

bool CheckIsUpper(char c) {
    return c != std::tolower(c);
}

bool CheckIsLower(char c) {
    return c != std::toupper(c);
}

std::string SwitchCase(std::string str) {
    for (size_t i = 0; i < str.size(); ++i) {
        if (CheckIsUpper(str[i])) {
            str[i] = std::tolower(str[i]);
        }
        else if (CheckIsLower(str[i])) {
            str[i] = std::toupper(str[i]);
        }
    }
    return str;
}

char SwitchCase(char ch) {
    if (CheckIsUpper(ch)) {
        return std::tolower(ch);
    }
    else {
        return std::toupper(ch);
    }
}

void TestLetter() {
    assert(SwitchCase('a') == 'A');
    assert(SwitchCase('b') == 'B');
    assert(SwitchCase('e') == 'E');
    assert(SwitchCase('x') == 'X');

    assert(SwitchCase('A') == 'a');
    assert(SwitchCase('B') == 'b');
    assert(SwitchCase('E') == 'e');
    assert(SwitchCase('X') == 'x');
}

void TestNoLetter() {
    assert(SwitchCase('!') == '!');
    assert(SwitchCase('-') == '-');
    assert(SwitchCase(' ') == ' ');
    assert(SwitchCase('\0') == '\0');
}

void TestString() {
    assert(SwitchCase("hello") == "HELLO");
    assert(SwitchCase("HELLO") == "hello");
    assert(SwitchCase("Hello") == "hELLO");
    assert(SwitchCase("hELLO") == "Hello");

    assert(SwitchCase("I love C++!") == "i LOVE c++!");
    assert(SwitchCase("i LOVE c++!") == "I love C++!");
}

int main() {

    TestLetter();

    TestNoLetter();

    TestString();
}