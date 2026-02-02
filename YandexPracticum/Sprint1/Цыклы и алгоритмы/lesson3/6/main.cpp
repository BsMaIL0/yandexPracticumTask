#include <iostream>
#include <cmath>

int main() {
    int amount;
    double rate;
    int term;

    std::cin >> amount >> rate >> term;

    double debt = amount;

    for (int i = 1; i <= term; i++) {
        double month_rate = rate / 12 / 100;
        double ratio = (std::pow(1 + month_rate, term) * month_rate) / (std::pow(1 + month_rate, term) - 1);
        double month_payment = amount * ratio;
        double percent_part = debt * month_rate;
        double debt_part = month_payment - percent_part;
        debt = debt - debt_part;
        std::cout << "Месяц: " << i << " Платёж: " << month_payment << " Проценты: " << percent_part << " Долг: " << debt_part << std::endl;
    }

    return 0;
}