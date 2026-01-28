#include <iostream>
#include <cmath>

int main() {
    double pumpkin = 0.15;
    double onion = 0.05;
    double carrot = 0.05;
    double coconut_milk = 0.1;

    double pumpkin_cost;
    double onion_cost;
    double carrot_cost;
    double coconut_milk_cost;

    int portions;

    std::cout << "Тыква" << std::endl;
    std::cin >> pumpkin_cost;
    std::cout << "Лук" << std::endl;
    std::cin >> onion_cost;
    std::cout << "Морковь" << std::endl;
    std::cin >> carrot_cost;
    std::cout << "Кокосовое молоко" << std::endl;
    std::cin >> coconut_milk_cost;
    std::cout << "Количество порций" << std::endl;
    std::cin >> portions;

    pumpkin_cost *= pumpkin;
    onion_cost *= onion;
    carrot_cost *= carrot;
    coconut_milk_cost *= coconut_milk;

    double portion_cost = pumpkin_cost + onion_cost + carrot_cost + coconut_milk_cost;

    std::cout << "Стоимость: " << (portion_cost * portions) << std::endl;
    return 0;
}