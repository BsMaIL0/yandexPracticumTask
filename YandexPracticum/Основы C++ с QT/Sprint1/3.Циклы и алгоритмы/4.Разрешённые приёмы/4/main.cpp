#include <iostream>

int main() {
    int n;
    std::cin >> n;
    int cur_max;
    int cur_next;
    int number;

    std::cin >> number;
    cur_max = number;
    std::cin >> number;
    cur_next = number;

    if (cur_next > cur_max) {
        int tmp = cur_max;
        cur_max = cur_next;
        cur_next = tmp;
    }

    for (int i = 0; i < n - 2; ++i) {
        std::cin >> number;
        if (number > cur_max) {
            cur_next = cur_max;
            cur_max = number;
        }
        else if (number > cur_next) {
            cur_next = number;
        }
        else {
            continue;
        }
    }

    std::cout << cur_max << " " << cur_next << std::endl;
    return 0;
}