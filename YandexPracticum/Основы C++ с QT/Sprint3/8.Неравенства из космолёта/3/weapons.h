#pragma once

enum class Weapons { ROCK, PAPER, SCISSORS };

inline bool operator<(Weapons lhs, Weapons rhs) {
    if (lhs == Weapons::ROCK && rhs == Weapons::PAPER){ 
        return true;
        }
    if (lhs == Weapons::PAPER && rhs == Weapons::SCISSORS){ 
        return true;
        }
    if (lhs == Weapons::SCISSORS && rhs == Weapons::ROCK){ 
        return true;
        }
    return false;
}