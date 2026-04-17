#include "calculator.h"

#include <cmath>
#include <string>

Number Calculator::GetNumber() const { return number_; }
void Calculator::Set(Number n) { number_ = n; }
void Calculator::Add(Number n) { number_ += n; }
void Calculator::Sub(Number n) { number_ -= n; }
void Calculator::Div(Number n) { number_ /= n; }
void Calculator::Mul(Number n) { number_ *= n; }
void Calculator::Pow(Number n) { number_ = std::pow(number_, n); }
void Calculator::Save() {
  is_saved_ = true;
  saved_number_ = number_;
}
void Calculator::Load() {
  if (is_saved_) {
    number_ = saved_number_;
  }
}
bool Calculator::HasMem() const {
  if (is_saved_) {
    return true;
  }
  return false;
}
std::string Calculator::GetNumberRepr() const {
  return std::to_string(number_);
}