#pragma once

class Rational {
public:
    Rational();
    Rational(int numerator);
    Rational(int numerator, int denominator);
    int GetNumerator() const;
    int GetDenominator() const;
    double AsDouble() const;

   private:
    int numerator_ = 0;   // Числитель дроби.
    int denominator_ = 1; // Знаменатель дроби.
};

// Функция сложения дробей.
// Возвращает обыкновенную дробь, равную сумме дробей r1 и r2.
Rational Add(Rational r1, Rational r2);

// Функция вычитания дробей.
// Возвращает обыкновенную дробь, равную разности дробей r1 и r2.
Rational Sub(Rational r1, Rational r2);