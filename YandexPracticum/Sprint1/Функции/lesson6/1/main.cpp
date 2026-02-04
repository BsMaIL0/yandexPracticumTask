#include <string>
#include <vector>

std::string TypeToString([[maybe_unused]] int arg) {
    return "int";
}

std::string TypeToString([[maybe_unused]] char arg) {
    return "char";
}

std::string TypeToString([[maybe_unused]] double arg) {
    return "double";
}

std::string TypeToString([[maybe_unused]] float arg) {
    return "float";
}

std::string TypeToString([[maybe_unused]] const std::string& arg) {
    return "std::string";
}

std::string TypeToString([[maybe_unused]] const std::vector<int>& arg) {
    return "std::vector<int>";
}

std::string TypeToString([[maybe_unused]] const std::vector<char>& arg) {
    return "std::vector<char>";
}

std::string TypeToString([[maybe_unused]] const std::vector<double>& arg) {
    return "std::vector<double>";
}

std::string TypeToString([[maybe_unused]] const std::vector<float>& arg) {
    return "std::vector<float>";
}

std::string TypeToString([[maybe_unused]] const std::vector<std::string>& arg) {
    return "std::vector<std::string>";
}