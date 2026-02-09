#include <iostream>

struct Cat {
    std::string name;
    int age;
};

using namespace std::literals;

int main() {
    Cat cat;
    cat.name = "Leopold"s;
    cat.age = 3;

    // Ќе мен€йте код выше этой строки!

    // ¬ыведите строку ЂX is now N years oldї, где X Ч им€ кота, а N Ч его возраст.
    std::cout << cat.name << " is now " << cat.age << " years old" << std::endl;
    return 0;
}