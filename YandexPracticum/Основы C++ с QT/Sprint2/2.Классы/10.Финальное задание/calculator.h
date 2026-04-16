#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <string>

using Number = double;

class Calculator {
 public:
  Number GetNumber() const;
  void Set(Number n);
  void Add(Number n);
  void Sub(Number n);
  void Div(Number n);
  void Mul(Number n);
  void Pow(Number n);
  void Save();
  void Load();
  bool HasMem() const;
  std::string GetNumberRepr() const;

 private:
  Number number_ = 0;
  bool is_saved_ = false;
  Number saved_number_ = 0;
};

#endif