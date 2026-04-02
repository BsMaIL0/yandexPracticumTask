#include <fstream>
#include <iostream>

#include "Window.h"

int main(int argc, char* argv[]) {
  if (argc < 3) {
    std::cerr << "Wrong command argument!" << std::endl;
    return 0;
  }

  std::ifstream in;
  std::ofstream out;

  in.open(argv[1]);
  out.open(argv[2]);

  if (!in) {
    std::cerr << "Can't open input file!" << std::endl;
    return 0;
  }
  if (!out) {
    std::cerr << "Can't open output file!" << std::endl;
    return 0;
  }

  Window a(in, out);
  a.progr();

  in.close();
  out.close();

  return 0;
}