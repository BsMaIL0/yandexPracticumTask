#include <iostream>

int main() {
    int cost;
    std::cin >> cost;
    int money = 0;
    int i = 0;
    do {
        std::cin >> money;
        i++;
        if (money < cost) {
            cost -= money;
        }
        else {
            std::cout << i << " ";
            std::cout << money - cost << " ";
            std::cout << money << std::endl;
            return 0;
        }
    } while (true);

    return 0;
}