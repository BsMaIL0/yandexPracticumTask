#pragma once
#include <cstdint>
#include <compare>

class Rational {
public:
    Rational(int numerator, int denominator)
    : numerator_(numerator)
    , denominator_(denominator) {}
    
    int GetNumerator() const {
        return numerator_;
    }
      
    int GetDenominator() const {
        return denominator_;
    }

    friend bool operator==(const Rational& lhs, const Rational& rhs);
    friend std::strong_ordering operator<=>(const Rational& lhs, const Rational& rhs);

private:
    int numerator_ = 0;
    int denominator_ = 1;
};

inline bool operator==(const Rational& lhs, const Rational& rhs) {
    long long left = static_cast<long long>(lhs.numerator_) * rhs.denominator_;
    long long right = static_cast<long long>(rhs.numerator_) * lhs.denominator_;
    return left == right;
}

inline std::strong_ordering operator<=>(const Rational& lhs, const Rational& rhs) {
    long long left = static_cast<long long>(lhs.numerator_) * rhs.denominator_;
    long long right = static_cast<long long>(rhs.numerator_) * lhs.denominator_;
    
    if (left < right) { 
        return std::strong_ordering::less;
    }
    if (left > right) {
        return std::strong_ordering::greater;
    }
    return std::strong_ordering::equal;
}