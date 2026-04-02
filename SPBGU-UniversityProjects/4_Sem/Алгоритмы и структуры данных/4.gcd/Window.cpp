#include "Window.h"

unsigned int Window::getWindowGcd() {
  if (stack_1_size == 0 && stack_2_size == 0) {
    return 0;
  }
  if (stack_1_size == 0) {
    return stack_2[stack_2_size - 1].gcd;
  }
  if (stack_2_size == 0) {
    return stack_1[stack_1_size - 1].gcd;
  }

  return gcd(stack_2[stack_2_size - 1].gcd, stack_1[stack_1_size - 1].gcd);
}

void Window::addWindow(unsigned int value) {
  pushStack1(value);
  summ += value;
}

Elem Window::popStack2() {
  Elem result = {0, 0};
  if (stack_2_size > 0) {
    stack_2_size--;
    result = stack_2[stack_2_size];
  }
  return result;
}

void Window::swapStacks() {
  for (int i = stack_1_size - 1; i >= 0; --i) {
    unsigned int new_gcd;
    if (stack_2_size == 0) {
      new_gcd = stack_1[i].number;
    } else {
      new_gcd = gcd(stack_1[i].number, stack_2[stack_2_size - 1].gcd);
    }

    stack_2[stack_2_size].number = stack_1[i].number;
    stack_2[stack_2_size].gcd = new_gcd;
    stack_2_size++;
  }
  stack_1_size = 0;
}

void Window::deleteNumberWindow() {
  if (stack_2_size == 0) {
    swapStacks();
  }

  if (stack_2_size > 0) {
    Elem removed = popStack2();
    summ -= removed.number;
  }
}

void Window::progr() {
  for (int i = 0; i < window_size; ++i) {
    addWindow(line_numbers[i]);
  }

  out << summ << " " << getWindowGcd() << std::endl;

  for (int i = window_size; i < line_nubmers_size; ++i) {
    deleteNumberWindow();
    addWindow(line_numbers[i]);
    out << summ << " " << getWindowGcd() << std::endl;
  }
}

unsigned int Window::gcd(unsigned int a, unsigned int b) {
  while (b!=0) {
    unsigned int temp = b;
    b = a % b;
    a = temp;
  }
  return a;
}

void Window::pushStack1(unsigned int value) {
  unsigned int new_gcd;
  if (stack_1_size == 0) {
    new_gcd = value;
  } else {
    new_gcd = gcd(stack_1[stack_1_size - 1].gcd, value);
  }

  stack_1[stack_1_size].number = value;
  stack_1[stack_1_size].gcd = new_gcd;
  stack_1_size++;
}

Window::Window(std::ifstream& in, std::ofstream& output) : out(output) {
  unsigned int tmp;
  in >> line_nubmers_size >> window_size;
  stack_1 = new Elem[window_size + 1];
  stack_2 = new Elem[window_size + 1];
  line_numbers = new unsigned int[line_nubmers_size];
  for (int i = 0; i < line_nubmers_size; ++i) {
    in >> tmp;
    line_numbers[i] = tmp;
  }
}

void Window::print() {
  std::cout << "window_size = " << window_size << std::endl;
  std::cout << "Elements in stack_1 (with their GCDs):" << std::endl;

  for (int i = 0; i < stack_1_size; ++i) {
    std::cout << "stack_1[" << i << "]: number=" << stack_1[i].number
              << ", gcd=" << stack_1[i].gcd << " , summ =" << summ << std::endl;
  }
}

Window::~Window() {
  delete[] stack_1;
  delete[] stack_2;
}
