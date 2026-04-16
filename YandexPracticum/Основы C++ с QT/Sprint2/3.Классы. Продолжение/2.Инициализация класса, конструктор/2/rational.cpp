#include "rational.h"

#include <cstdlib>
#include <numeric>

static void Normalize(int& numerator, int& denominator) {
  if (denominator == 0) {
    std::abort();
  }

  if (denominator < 0) {
    numerator = -numerator;
    denominator = -denominator;
  }

  int divider = std::gcd(std::abs(numerator), denominator);
  numerator /= divider;
  denominator /= divider;
}

Rational::Rational() = default;

Rational::Rational(int numerator) {
  numerator_ = numerator;
  denominator_ = 1;
  Normalize(numerator_, denominator_);
}

Rational::Rational(int numerator, int denominator) {
  if (denominator == 0) {
    std::abort();
  }
  numerator_ = numerator;
  denominator_ = denominator;
  Normalize(numerator_, denominator_);
}

int Rational::GetNumerator() const { return numerator_; }

int Rational::GetDenominator() const { return denominator_; }

double Rational::AsDouble() const {
  return static_cast<double>(numerator_) / static_cast<double>(denominator_);
}

Rational Add(Rational r1, Rational r2) {
  int tmp_numerator = r1.GetNumerator() * r2.GetDenominator() +
                      r1.GetDenominator() * r2.GetNumerator();
  int tmp_denominator = r1.GetDenominator() * r2.GetDenominator();

  if (tmp_denominator < 0) {
    tmp_numerator = -tmp_numerator;
    tmp_denominator = -tmp_denominator;
  }

  int divider = std::gcd(std::abs(tmp_numerator), tmp_denominator);
  tmp_numerator /= divider;
  tmp_denominator /= divider;

  return Rational(tmp_numerator, tmp_denominator);
}

Rational Sub(Rational r1, Rational r2) {
  int tmp_numerator = r1.GetNumerator() * r2.GetDenominator() -
                      r1.GetDenominator() * r2.GetNumerator();
  int tmp_denominator = r1.GetDenominator() * r2.GetDenominator();

  if (tmp_denominator < 0) {
    tmp_numerator = -tmp_numerator;
    tmp_denominator = -tmp_denominator;
  }

  int divider = std::gcd(std::abs(tmp_numerator), tmp_denominator);
  tmp_numerator /= divider;
  tmp_denominator /= divider;

  return Rational(tmp_numerator, tmp_denominator);
}