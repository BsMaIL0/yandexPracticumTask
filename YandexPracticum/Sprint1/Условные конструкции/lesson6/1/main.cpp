#include <iostream>

int main() {
    int N;
    std::cin >> N;

    if ((N % 4 == 0 && N % 100 != 0) || N % 400 == 0) {
        std::cout << "Да" << std::endl;
    }
    else {
        std::cout << "Нет" << std::endl;
    }

    return 0;
}