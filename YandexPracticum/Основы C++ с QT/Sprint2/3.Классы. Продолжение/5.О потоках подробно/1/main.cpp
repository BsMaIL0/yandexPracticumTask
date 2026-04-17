#include <cassert>
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>

#include "book.h"

// Записывает книгу в переданный поток.
void WriteBook(std::ostream& out, const Book& book) {
    out<<book.title<<"\n"<<book.author<<"\n"<<book.publication_year<<"\n";
}

// Считывает книгу из переданного потока.
Book ReadBook(std::istream& in) {
    Book book;
    std::getline(in, book.title);
    std::getline(in, book.author);
    in >> book.publication_year >> std::ws;
    return book;
}

bool BooksAreEqual(const Book& book1, const Book& book2) {
    return (book1.title == book2.title) && (book1.author == book2.author)
        && (book1.publication_year == book2.publication_year);
}

int main() {
    using namespace std::literals;

    const Book book1{.title = "White Fang"s, .author = "Jack London"s, .publication_year = 1906};
    const Book book2{.title = "Moby-Dick"s, .author = "Herman Melville"s, .publication_year = 1851};

    // Тестируем WriteBook.
    {
        std::ostringstream out_stream;
        WriteBook(out_stream, book1);
        
        assert(out_stream.str() == "White Fang\nJack London\n1906\n");
    }

    {
        std::ostringstream out_stream;
        WriteBook(out_stream, book2);
        
        assert(out_stream.str() == "Moby-Dick\nHerman Melville\n1851\n");
    }

    // Тестируем ReadBook.
    {
        std::istringstream input_stream("White Fang\nJack London\n1906\n");
        const Book read_bool = ReadBook(input_stream);
        
        assert(BooksAreEqual(read_bool, book1));

        // Следующая проверка убедится, что вы не забыли прочитать из потока
        //  все оставшиеся пробельные символы манипулятором std::ws.
        assert(input_stream.get() == EOF);
    }

    {
        std::istringstream input_stream("Moby-Dick\nHerman Melville\n1851\n");
        const Book read_bool = ReadBook(input_stream);
        
        assert(BooksAreEqual(read_bool, book2));
        assert(input_stream.get() == EOF);
    }

    // Тестируем обе функции.
    {
        std::stringstream strm;
        WriteBook(strm, book1);
        WriteBook(strm, book2);

        auto book1_copy = ReadBook(strm);
        auto book2_copy = ReadBook(strm);

        assert(BooksAreEqual(book1_copy, book1));
        assert(BooksAreEqual(book2_copy, book2));
    }
}