class Rational {
public:
    Rational(int numerator, int denominator)
    : numerator_(numerator)
    , denominator_(denominator) {}	
  
    // Перегрузка операции сравнения.
    // Вы научитесь этому в следующем уроке.
    bool operator==(const Rational& r) const {
        return (numerator_ == r.numerator_) &&
               (denominator_ == r.denominator_);
    }
  
    Rational(int number): numerator_(number), denominator_(1){}
    // И реализуйте перегрузку присваивания.
    Rational& operator=(int number){
        numerator_ = number;
        denominator_ = 1;
        return *this;
    }
    Rational& operator=(const Rational& number) = default;
  
private:
    int numerator_ = 0;
    int denominator_ = 1;
};