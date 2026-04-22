#include <vector>
#include <iostream>
#include <utility>
#include <algorithm>

using namespace std::literals;

// Названия дней недели на английском.
static const std::vector<std::string> WEEKDAY_NAMES = {
    "Monday"s,
    "Tuesday"s,
    "Wednesday"s,
    "Thursday"s,
    "Friday"s,
    "Saturday"s,
    "Sunday"s,
    "Unknown"s
};

enum class Weekday {
    MONDAY = 0,
    TUESDAY,
    WEDNESDAY,
    THURSDAY,
    FRIDAY,
    SATURDAY,
    SUNDAY,
    UNKNOWN
};

// Напишите эти функции.
Weekday Add(Weekday day, int value) {
    if (day == Weekday::UNKNOWN) {
        return Weekday::UNKNOWN;
    }
    int result_day = ((int)day + value) % 7;
    if (result_day < 0) {
        result_day += 7;
    }
    return static_cast<Weekday>(result_day);
}
Weekday Sub(Weekday day, int value){
    return Add(day,-value);
}
void Print(std::ostream& out, Weekday day){
    out<<WEEKDAY_NAMES[(int)day];
}
Weekday Read(std::istream& inp) {
    std::string str;
    inp >> str;

    auto it = std::find(WEEKDAY_NAMES.begin(), WEEKDAY_NAMES.end(), str);
    if (it != WEEKDAY_NAMES.end()) {
        size_t index = std::distance(WEEKDAY_NAMES.begin(), it);
        return static_cast<Weekday>(index);
    } else {
        return Weekday::UNKNOWN;
    }
}


int main() {
    int val_add = 0;
    int val_sub = 0;

    Weekday init_weekday = Read(std::cin);

    std::cin >> val_add;
    std::cin >> val_sub;

    std::cout << val_add << " day(s) after it will be ";
    Print(std::cout, Add(init_weekday, val_add));
    std::cout << std::endl;

    std::cout << val_sub << " day(s) before it was ";
    Print(std::cout, Sub(init_weekday, val_sub));
    std::cout << std::endl;
}