#pragma once

#include <iostream>
#include <string>

class Rational {
public:
    Rational() = default;
    Rational(int numerator, int denominator)
     : numerator_{numerator}, denominator_{denominator} {}
    
    friend std::istream& operator>>(std::istream& iss, Rational& number);
    friend std::ostream& operator<<(std::ostream& oss, const Rational& number);
    
private:
    int numerator_ = 0;
    int denominator_ = 1;
};

inline std::istream& operator>>(std::istream& iss, Rational& number) {
    std::string line;
    if (!std::getline(iss, line)) {
        iss.setstate(std::ios::failbit);
        return iss;
    }
    
    size_t slashPos = line.find('/');
    
    if (slashPos == std::string::npos) {
        try {
            number.numerator_ = std::stoi(line);
            number.denominator_ = 1;
        } catch (const std::exception&) {
            iss.setstate(std::ios::failbit);
        }
    } else {
        try {
            std::string numeratorStr = line.substr(0, slashPos);
            std::string denominatorStr = line.substr(slashPos + 1);
            
            number.numerator_ = std::stoi(numeratorStr);
            number.denominator_ = std::stoi(denominatorStr);
            
            if (number.denominator_ == 0) {
                iss.setstate(std::ios::failbit);
            }
        } catch (const std::exception&) {
            iss.setstate(std::ios::failbit);
        }
    }
    
    return iss;
}

inline std::ostream& operator<<(std::ostream& oss, const Rational& number) {
    if (number.denominator_ == 1) {
        oss << number.numerator_;  
    } else {
        oss << number.numerator_ << " / " << number.denominator_; 
    }
    return oss;
}