#pragma once

#include <string>

class Person {
public:
   std::string GetName(){
    return name_;
   }
   explicit Person(std::string name) : name_(name) {}
private:
    std::string name_;
};