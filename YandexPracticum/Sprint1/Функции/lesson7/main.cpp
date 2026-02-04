#include <string>
#include <iostream>

void DoPenelopeTask(int count);

void DoOliverTask(int count) {
    if (count % 2 != 0) {
        std::cout << "Transmit to Penelope" << std::endl;
        DoPenelopeTask(count);
        return;
    }

    for (int i = 0; i < count; ++i) {
        std::cout << "Oliver: Hurrah!" << std::endl;
    }
}

void DoPenelopeTask(int count) {
    if (count % 2 == 0) {
        std::cout << "Transmit to Oliver" << std::endl;
        DoOliverTask(count);
        return;
    }

    for (int i = 0; i < count; ++i) {
        std::cout << "Penelope: Hurrah!" << std::endl;
    }
}

int main() {
    std::string target;
    int count;
    std::cin >> target >> count;

    if (target == "Oliver") {
        DoOliverTask(count);
    }
    else if (target == "Penelope") {
        DoPenelopeTask(count);
    }
    else {
        std::cout << "Unknown addressee: " << target << std::endl;
    }
}