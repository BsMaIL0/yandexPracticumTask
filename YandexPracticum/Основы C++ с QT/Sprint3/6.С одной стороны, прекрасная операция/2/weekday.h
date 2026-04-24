#pragma once

enum class Weekday {Sun, Mon, Tue, Wed, Thu, Fri, Sat};

inline Weekday& operator++(Weekday& wd) {
    if (wd == Weekday::Sat) {
        wd = Weekday::Sun;
    } else {
        wd = static_cast<Weekday>(static_cast<int>(wd) + 1);
    }
    return wd;
}

inline Weekday operator++(Weekday& wd, int) {
    Weekday old = wd;
    ++wd;
    return old;
}

inline Weekday& operator--(Weekday& wd) {
    if (wd == Weekday::Sun) {
        wd = Weekday::Sat;
    } else {
        wd = static_cast<Weekday>(static_cast<int>(wd) - 1);
    }
    return wd;
}

inline Weekday operator--(Weekday& wd, int) {
    Weekday old = wd;
    --wd;
    return old;
}