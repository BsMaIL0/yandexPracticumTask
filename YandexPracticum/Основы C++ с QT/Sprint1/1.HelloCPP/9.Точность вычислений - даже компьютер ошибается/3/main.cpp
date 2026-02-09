#include <iostream>

int main() {
    int days_passed;
    int weekend_day;
    int weelend_passed;
    int day_now;
    std::cin >> weekend_day >> days_passed;

    weelend_passed = days_passed / 7;
    day_now = (days_passed - 1 + weekend_day) % 7 + 1;

    std::cout << weelend_passed << std::endl;
    std::cout << day_now << std::endl;

    return 0;
}