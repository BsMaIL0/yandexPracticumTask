#include <iostream>
#include <vector>

int main() {
    std::vector<char> abc{ 'a', 'b', 'c', 'd' };
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            for (int g = 0; g < 4; ++g) {
                if (abc[i] == abc[j] || abc[i] == abc[g] || abc[j] == abc[g]) {
                    std::cout << abc[i] << abc[j] << abc[g] << std::endl;
                    continue;
                }
            }
        }
    }
    return 0;
}