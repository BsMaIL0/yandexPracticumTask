#include <iostream>
#include <cmath>

int main() {
    double room_length;
    double room_width;
    double room_height;

    double roll_width;
    double roll_length;

    std::cin >> room_length >> room_width >> room_height;
    std::cin >> roll_width >> roll_length;

    double room_area = room_length * room_height * 2 + room_width * room_height * 2;
    double roll_area = roll_width * roll_length;

    double result = room_area / roll_area;
    result = std::ceil(result);

    std::cout << result << std::endl;
}