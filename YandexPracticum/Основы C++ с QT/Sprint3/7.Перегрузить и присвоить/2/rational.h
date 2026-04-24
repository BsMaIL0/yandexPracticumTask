#pragma once

#include <numeric>
#include <cstdlib>

class Rational {
public:
    Rational(int numerator, int denominator)
    : numerator_(numerator)
    , denominator_(denominator) {
        if (denominator_ == 0) {
            std::abort();
        }
        Reduction();
    }	
    
    Rational(int number) : numerator_(number), denominator_(1) {}
  
    bool operator==(const Rational& r) const = default;
    
    Rational& operator+=(const Rational& r) {
        numerator_ = numerator_ * r.denominator_ + denominator_ * r.numerator_;
        denominator_ = denominator_ * r.denominator_;
        Reduction();
        return *this;
    }
    
    Rational& operator-=(const Rational& r) {
        numerator_ = numerator_ * r.denominator_ - denominator_ * r.numerator_;
        denominator_ = denominator_ * r.denominator_;
        Reduction();
        return *this;
    }
    
    Rational& operator*=(const Rational& r) {
        numerator_ *= r.numerator_;
        denominator_ *= r.denominator_;
        Reduction();
        return *this;
    }
    
    Rational& operator/=(const Rational& r) {
        numerator_ *= r.denominator_;
        denominator_ *= r.numerator_;
        Reduction();
        return *this;
    }

private:
    void Reduction() {
        if (denominator_ < 0) {
            numerator_ = -numerator_;
            denominator_ = -denominator_;
        }
        const int divisor = std::gcd(numerator_, denominator_);
        numerator_ /= divisor;
        denominator_ /= divisor;
    }

private:
    int numerator_ = 0;
    int denominator_ = 1;
};