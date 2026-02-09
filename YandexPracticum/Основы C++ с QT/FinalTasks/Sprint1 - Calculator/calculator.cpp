#include "calculator.h"
#include <string>
#include <iostream>
#include <cmath>

bool ReadNumber(Number& result){
    Number tmp;
    if(!(std::cin>>tmp)){
        std::cerr<<"Error: Numeric operand expected"<<std::endl;
        return 0;
    }
    result = tmp;
    return 1;
}

bool ReadOperation(std::string& op){
    std::string tmp;
    if(!(std::cin>>tmp)){
        std::cerr<<"Error: Wrong input op "<<tmp<<std::endl;
        return 0;
    }
    op = tmp;
    return 1;
}

bool RunCalculatorCycle(){
    Number calc;
    Number tmp;
    Number save;
    std::string op;
    bool is_save = false;
    if(!ReadNumber(calc)){
        return 0;
    }
    while(true){
        if(!ReadOperation(op)){
            return 0;
        }
        if(op=="s"){
            save = calc;
            is_save = true;
        }
        else if(op=="l"){
            if(!(is_save)){
                std::cerr<<"Error: Memory is empty"<<std::endl;
                return 0;
            }
            calc = save;
        }
        else if(op=="+"){
            if(!ReadNumber(tmp)){
                return 0;
            }
            calc += tmp;
        }
        else if(op=="-"){
            if(!ReadNumber(tmp)){
                return 0;
            }
            calc -= tmp;
        }
        else if(op=="*"){
            if(!ReadNumber(tmp)){
                return 0;
            }
            calc *= tmp;
        }
        else if(op == "/"){
            if(!ReadNumber(tmp)){
                return 0;
            }
            calc /= tmp;
        }
        else if(op == "**"){
            if(!ReadNumber(tmp)){
                return 0;
            }
            calc = std::pow(calc,tmp);
        }
        else if(op == "="){
            std::cout<<calc<<std::endl;
        }
        else if(op == ":"){
            if(!ReadNumber(tmp)){
                return 0;
            }
            calc = tmp;
        }
        else if(op == "c"){
            calc = 0;
        }
        else if(op == "q"){
            return 1;
        }
        else{
            std::cerr<<"Error: Unknown token "<<op<<std::endl;
            return 0;
        }
    }
}
