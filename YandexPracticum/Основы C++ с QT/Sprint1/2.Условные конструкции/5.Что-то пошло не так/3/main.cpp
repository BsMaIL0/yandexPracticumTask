#include <iostream>

int main() {
    int first_x, first_y;
    int second_x, second_y;
    std::cin >> first_x >> first_y;
    std::cin >> second_x >> second_y;

    if ((first_x == second_x && first_y != second_y) || (first_y == second_y && first_x != second_x)) {
        std::cout << "Да" << std::endl;
    }
    else {
        std::cout << "Нет" << std::endl;
    }

    return 0;
}