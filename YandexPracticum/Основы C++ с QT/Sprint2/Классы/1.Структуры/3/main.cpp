#include <iostream>

struct Person {
    std::string name;
    std::string surname;
};

using namespace std::literals;

int main() {
    Person groom;  // Жених.
    std::cin >> groom.name >> groom.surname;

    Person bride;  // Невеста.
    std::cin >> bride.name >> bride.surname;

    // Не меняйте код выше этой строки!

    // 1) Прочитайте из стандартного ввода имя и фамилию невесты.

    // 2) Выведите текст в следующем формате:
    //    Ronald Weasley and Hermione Granger! I pronounce you husband and wife.

    std::cout << groom.name << " " << groom.surname << " and " << bride.name << " " << bride.surname
        << "! I pronounce you husband and wife." << std::endl;

    return 0;
}