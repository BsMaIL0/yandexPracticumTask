#pragma once

#include <cstdlib>

class Rational {
public:
    Rational(int numerator, int denominator)
    : numerator_(numerator)
    , denominator_(denominator) {
      if (denominator_ == 0) {
          std::abort();
      }
  }

  explicit operator double(){
    return static_cast<double>(numerator_) / static_cast<double>(denominator_);
  }

private:
    int numerator_ = 0;
    int denominator_ = 1;
};