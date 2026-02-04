#include <cctype>
#include <iostream>
#include <string>
#include "utils.h"

int main() {
    using namespace std::literals;
    const std::string title = ReadString();
    const int publication_year = ReadInteger();
    const std::string author = ReadString();
    const int number_of_pages = ReadInteger();

    std::cout << "Book title: "s << ToUpper(title) << std::endl;
    std::cout << "Author: "s << ToUpper(author) << std::endl;
    std::cout << "Pages: "s << number_of_pages << std::endl;
    std::cout << "Published in: "s << publication_year << std::endl;
}