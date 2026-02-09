#include <iostream>

int main() {
    int N;
    std::cin >> N;

    int remains = N % 2;
    remains == 0 ? std::cout << "Число " << N << " чётное" << std::endl : std::cout << "Число " << N << " нечётное" << std::endl;

    return 0;
}