#include <iostream>
#include <string>

struct Book {
    std::string title;
    std::string author;
    int publication_year;
    // Добавьте поля:
    // author типа std::string,
    // publication_year типа int.
};

int main() {
    Book book;
    // Считываем название книги.
    std::getline(std::cin, book.title);
    std::getline(std::cin, book.author);
    std::cin >> book.publication_year;

    // Прочитайте из cin имя автора и год публикации.

    // Выведите в cout текст:
    // "Название_книги by Имя_автора was published in Год_публикации.".
    std::cout << book.title << " by " << book.author << " was published in " << book.publication_year << "." << std::endl;

    return 0;
}