#include <cassert>
#include <sstream>

#include "calculator.h"
#include "calculator_ui.h"

int main() {
  std::istringstream input{"42 / 6 + 3 = q"};
  std::ostringstream output;
  std::ostringstream errors;

  Calculator calc;
  CalculatorUI ui{calc, output, errors};
  ui.Parse(input);

  assert(calc.GetNumberRepr() == "10.000000");
  assert(output.str() == "10.000000\n");
  assert(errors.str().empty());
}