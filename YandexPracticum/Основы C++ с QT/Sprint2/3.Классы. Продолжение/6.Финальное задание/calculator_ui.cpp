#include "calculator_ui.h"

using namespace std::literals;

bool CalculatorUI::Parse(std::istream& input) const {
  Number operand;
  if (!ReadNumber(input, operand)) {
    return false;
  }
  calc_.Set(operand);

  std::string op;
  double tmp;

  for (std::string op; input >> op;) {
    if (op == "s") {
      calc_.Save();
    } else if (op == "l") {
      if (!(calc_.HasMem())) {
        err_ << "Error: Memory is empty" << std::endl;
        return false;
      }
      calc_.Load();
    } else if (op == "+") {
      if (!ReadNumber(input, tmp)) {
        return false;
      }
      calc_.Add(tmp);
    } else if (op == "-") {
      if (!ReadNumber(input, tmp)) {
        return false;
      }
      calc_.Sub(tmp);
    } else if (op == "*") {
      if (!ReadNumber(input, tmp)) {
        return false;
      }
      calc_.Mul(tmp);
    } else if (op == "/") {
      if (!ReadNumber(input, tmp)) {
        return false;
      }
      calc_.Div(tmp);
    } else if (op == "**") {
      if (!ReadNumber(input, tmp)) {
        return false;
      }
      calc_.Pow(tmp);
    } else if (op == "=") {
      out_ << calc_.GetNumberRepr() << std::endl;
    } else if (op == ":") {
      if (!ReadNumber(input, tmp)) {
        return false;
      }
      calc_.Set(tmp);
    } else if (op == "c") {
      calc_.Set(0);
    } else if (op == "q") {
      return true;
    } else if (op == "n") {
      calc_.Set(calc_.GetNumber() * (-1));
    } else {
      err_ << "Error: Unknown token " << op << std::endl;
      return false;
    }
  }

  return !input.fail();
}

bool CalculatorUI::ReadNumber(std::istream& input, Number& result) const {
  if (!(input >> result)) {
    err_ << "Error: Numeric operand expected" << std::endl;
    return false;
  }
  return true;
}

CalculatorUI::CalculatorUI(Calculator& calc, std::ostream& out,
                           std::ostream& err)
    : calc_(calc), out_(out), err_(err) {}