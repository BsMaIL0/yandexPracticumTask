#include <string>
#include <iostream>

int main() {
    std::string haystack, needle, replacement;
    std::getline(std::cin, haystack);
    std::getline(std::cin, needle);
    std::getline(std::cin, replacement);

    size_t pos = haystack.find(needle);
    if (pos != std::string::npos) {
        haystack = haystack.substr(0, pos) + replacement + haystack.substr(pos + needle.size());
    }

    std::cout << haystack << std::endl;

    return 0;
}