#include <cassert>
#include <string>

using namespace std::literals;

struct Point {
    double x = 0;
    double y = 0;
};

struct RGBAColor {
    float red{};
    float green{};
    float blue{};
    float alpha = 1;
};

struct TextWithStyle {
    int size = 8;
    RGBAColor color = RGBAColor(0, 0, 0, 1);
    Point position = Point(100, 100);
    bool is_bold = true;
    bool is_italic = false;
    std::string text = "Specify text";
};

int main() {
    TextWithStyle text_with_style;

    assert(text_with_style.size == 8);

    assert(text_with_style.color.red == 0.f);
    assert(text_with_style.color.green == 0.f);
    assert(text_with_style.color.blue == 0.f);
    assert(text_with_style.color.alpha == 1.f);

    assert(text_with_style.position.x == 100.);
    assert(text_with_style.position.y == 100.);

    assert(text_with_style.is_bold);
    assert(!text_with_style.is_italic);

    assert(text_with_style.text == "Specify text"s);
}