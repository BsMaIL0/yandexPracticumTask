#include "calculator.h"
#include<iostream>


int main(){
  Calculator calc;
  double n,tmp;
  std::cin >> n;
  std::string op;
  calc.Set(n);
  while (true) {
    std::cin >> op;
    if (op == "s") {
      calc.Save();
    } else if (op == "l") {
      if (!(calc.HasMem())) {
        std::cerr << "Error: Memory is empty" << std::endl;
        return 0;
      }
      calc.Load();
    } else if (op == "+") {
      std::cin >> tmp;
      calc.Add(tmp);
    } else if (op == "-") {
      std::cin >> tmp;
      calc.Sub(tmp);
    } else if (op == "*") {
      std::cin >> tmp;
      calc.Mul(tmp);
    } else if (op == "/") {
      std::cin >> tmp;
      calc.Div(tmp);
    } else if (op == "**") {
      std::cin >> tmp;
      calc.Pow(tmp);
    } else if (op == "=") {
      std::cout << calc.GetNumberRepr() << std::endl;
    } else if (op == ":") {
      std::cin >> tmp;
      calc.Set(tmp);
    } else if (op == "c") {
      calc.Set(0);
    } else if (op == "q") {
      return 1;
    } else {
      std::cerr << "Error: Unknown token " << op << std::endl;
      return 0;
    }
  }
}