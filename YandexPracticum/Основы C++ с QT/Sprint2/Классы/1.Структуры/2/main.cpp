#include <iostream>

struct Person {
    std::string name;
    std::string surname;
};

using namespace std::literals;

int main() {
    Person person1;
    Person person2;
    // Не меняйте код выше этой строки!

    person1.name = "Harry";
    person1.surname = "Potter";
    person2.name = "Hermione";
    person2.surname = "Granger";

    std::cout << person1.name << " " << person1.surname << std::endl;
    std::cout << person2.name << " " << person2.surname << std::endl;

    return 0;
    // 1) Пусть person1 зовут Harry Potter.

    // 2) Объявите переменную person2 типа Person, пусть второго человека зовут Hermione Granger.

    // 3) Выведите через пробел имя и фамилию первого человека.
    //    Во второй строке выведите через пробел имя и фамилию второго человека.
}