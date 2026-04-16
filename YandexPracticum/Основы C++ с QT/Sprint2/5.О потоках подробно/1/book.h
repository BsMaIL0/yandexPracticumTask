#include <string>
#include <iostream>

struct Book {
    std::string title;
    std::string author;
    int publication_year = 0;
};

// Реализуйте эти функции в cpp-файле.
void WriteBook(std::ostream& out, const Book& book);
Book ReadBook(std::istream& in);