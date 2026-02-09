#include <cassert>

int main() {
    struct Point {
        double x = 0;
        double y = 0;
    };

    Point p;
    assert(p.x == 0.);
    assert(p.y == 0.);
}