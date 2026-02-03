#include <iostream>
#include <string>

void CountAndPrint(std::string str, char character) {
    int count = 0;
    std::size_t pos = str.find(character);
    while (pos != std::string::npos) {
        count++;
        pos = str.find(character, pos + 1);
    }
    std::cout << "В строке \"" << str
        << "\" символ '" << character
        << "' встречается " << count << " раз(а)." << std::endl;
}

void SplitAndAnalyze(std::string str, char del, char character) {
    size_t start = 0;
    size_t end = str.find(del);

    while (true) {
        std::string tmp = str.substr(start, end - start);
        CountAndPrint(tmp, character);

        if (end == std::string::npos) {
            break;
        }

        start = end + 1;
        end = str.find(del, start);
    }
}

int main() {
    std::string str;
    std::getline(std::cin, str);

    char del;
    std::cin >> del;

    char ch;
    std::cin >> ch;

    SplitAndAnalyze(str, del, ch);
}