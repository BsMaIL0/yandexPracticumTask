#include <iostream>

int main() {
    int seconds;
    std::cin >> seconds;

    int days = seconds / (60 * 60 * 24);
    seconds %= 60 * 60 * 24;

    int hours = seconds / (60 * 60);
    seconds %= 60 * 60;

    int minutes = seconds / 60;
    seconds %= 60;

    std::cout << days << " суток " << hours << " часов " << minutes << " минут " << seconds << " секунд" << std::endl;

    return 0;
}