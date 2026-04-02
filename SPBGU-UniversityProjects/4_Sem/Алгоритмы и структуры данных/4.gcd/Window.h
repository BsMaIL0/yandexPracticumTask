#ifndef WINDOW_H
#define WINDOW_H

#include <fstream>
#include <iostream>

struct Elem {
  unsigned int number;
  unsigned int gcd;
};

class Window {
 public:
  static unsigned int gcd(unsigned int a, unsigned int b);
  void pushStack1(unsigned int value);
  Elem popStack2();
  void swapStacks();
  void deleteNumberWindow();
  void addWindow(unsigned int value);
  unsigned int getWindowGcd();

  Window(std::ifstream& in, std::ofstream& out);
  ~Window();
  void print();
  void progr();

 private:
  unsigned long long summ = 0;
  unsigned int* line_numbers;
  int line_nubmers_size;
  Elem* stack_1;
  Elem* stack_2;
  int window_size = 0;
  int stack_1_size = 0;
  int stack_2_size = 0;
  std::ofstream& out;
};

#endif