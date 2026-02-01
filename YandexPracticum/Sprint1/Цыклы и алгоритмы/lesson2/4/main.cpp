#include <iostream>

int main() {
    int i = 0;
    int symbols = 0;
    std::string line;
    while (true) {
        std::getline(std::cin, line);

        if (line.size() == 0) {
            std::cout << i << " " << symbols << std::endl;
            return 0;
        }

        i++;
        symbols += line.size();
    }
}