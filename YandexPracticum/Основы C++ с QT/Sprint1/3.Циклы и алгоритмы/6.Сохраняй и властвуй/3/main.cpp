#include <iostream>
#include <vector>
#include <string>

int main() {
    std::string str_number;
    std::cin >> str_number;
    std::vector<int> number;
    for (int i = str_number.size() - 1; i >= 0; --i) {
        number.push_back(static_cast<int>(str_number[i] - '0'));
    }
    bool mind_one = true;
    for (size_t i = 0; i != number.size(); ++i) {
        if (number[i] == 9) {
            number[i] = 0;
            continue;
        }
        else {
            number[i] += 1;
            mind_one = false;
            break;
        }
    }
    if (mind_one == true) {
        number.push_back(1);
    }
    for (int i = number.size() - 1; i >= 0; --i) {
        std::cout << number[i];
    }
    return 0;
}