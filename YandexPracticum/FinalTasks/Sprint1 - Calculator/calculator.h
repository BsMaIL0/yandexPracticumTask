#pragma once
#include <string>

using Number = double;

bool RunCalculatorCycle(); 

bool ReadNumber(Number& result);

bool ReadOperation(std::string& op);