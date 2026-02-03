#include <iostream>
#include <string>

void CountAndPrint(std::string str, char ch) {
    size_t pos = 0;
    int n = 0;
    while (true) {
        pos = str.find(ch, pos);
        if (pos == std::string::npos) {
            break;
        }
        else {
            ++pos;
            ++n;
        }
    }
    std::cout << "В строке \"" << str << "\" символ \'" << ch << "\' встречается " << n << " раз(а)." << std::endl;
}

int main() {
    std::string str;
    std::getline(std::cin, str);

    char ch;
    std::cin >> ch;

    CountAndPrint(str, ch);
}