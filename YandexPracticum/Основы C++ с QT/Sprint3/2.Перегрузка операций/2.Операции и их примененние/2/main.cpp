#include <iostream>
#include <string>
#include <utility>

// Определяем пару.
using IntPair = std::pair<int, int>;

// Складывает покомпонентно две пары.
IntPair Add(const IntPair& pair1, const IntPair& pair2) {
    return std::make_pair(pair1.first + pair2.first, pair1.second + pair2.second);
}

// Вычитает покомпонентно две пары.
IntPair Sub(const IntPair& pair1, const IntPair& pair2){
    return std::make_pair(pair1.first - pair2.first, pair1.second - pair2.second);
}

// Умножает компоненты пары на число.
IntPair Mul(const IntPair& pair, int value){
    return std::make_pair(pair.first * value, pair.second * value);
}

// Печать и чтение интовой пары.
void Print(std::ostream& out, const IntPair& pair){
    out<<"{"<<pair.first<<","<<pair.second<<"}";
}

IntPair Read(std::istream& inp) {
    char ch;
    int first, second;

    inp >> ch;  
  
    inp >> first;
    
    inp >> ch;  

    inp >> second;
    
    inp >> ch;  

    return IntPair(first, second);
}

int main() {
    std::string str;
    char op_sym;
    IntPair pair1;
    IntPair pair2;
    IntPair res_pair;
    int val;

    pair1 = Read(std::cin);
    std::cin >> op_sym;
    // Выведем элементы пары.
    switch (op_sym) {
        case '+':
            pair2 = Read(std::cin);
            res_pair = Add(pair1, pair2);
            break;
        case '-':
            pair2 = Read(std::cin);
            res_pair = Sub(pair1, pair2);
            break;
        case '*':
            std::cin >> val;
            res_pair = Mul(pair1, val);
            break;
        default:
            std::cout << "Undefined symbol!" << std::endl;
            return 1;
    }
    Print(std::cout, res_pair);
}