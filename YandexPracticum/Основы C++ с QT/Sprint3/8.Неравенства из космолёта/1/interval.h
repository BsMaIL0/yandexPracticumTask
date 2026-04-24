#pragma once

#include <cmath>

class Interval {
public:
    Interval(int start, int end): start_(start), end_(end) {};
    int GetStart() const { 
        return start_; 
    }
    int GetEnd() const { 
        return end_; 
    }
private:
    int start_, end_;
};

inline bool operator<(const Interval& i1, const Interval& i2) {
    return abs(i1.GetEnd() - i1.GetStart()) < abs(i2.GetEnd() - i2.GetStart());
}

inline bool operator==(const Interval& i1, const Interval& i2) {
    return !(i1 < i2) && !(i2 < i1);
}

inline bool operator!=(const Interval& i1, const Interval& i2) {
    return !(i1 == i2);
}

inline bool operator>(const Interval& i1, const Interval& i2) {
    return i2 < i1;
}

inline bool operator<=(const Interval& i1, const Interval& i2) {
    return !(i2 < i1);
}

inline bool operator>=(const Interval& i1, const Interval& i2) {
    return !(i1 < i2);
}