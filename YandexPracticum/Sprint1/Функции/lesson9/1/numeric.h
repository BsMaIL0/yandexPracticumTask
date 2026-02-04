#pragma once

#include <cmath> 

inline bool IsPrime(int number) {
    if (number == 1) {
        return false;
    }

    for (int i = 2; i <= std::sqrt(number); ++i) {
        if (number % i == 0) {
            return false; 
        }
    }

    return true; 
}
