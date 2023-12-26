#include "Convert.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::~ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &other) {
    *this = other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter &other) {
    return *this;
}

void ScalarConverter::convert(const std::string &input) {
    try {
        int intValue = std::stoi(input);
        char c = toChar(intValue);
        std::cout << "char: " << "'" << c << "'" << std::endl;
    } catch (const std::exception &e) {
        std::cout << "char: impossible" << std::endl;
    }

    try {
        int i = toInt(std::stoi(input));
        std::cout << "int: " << i << std::endl;
    } catch (const std::exception &e) {
        std::cout << "int: impossible" << std::endl;
    }

    try {
        float f = toFloat(std::stof(input));
        std::cout << "float: " << f << (f == static_cast<int>(f) ? ".0f" : "f") << std::endl;
    } catch (const std::exception &e) {
        std::cout << "float: impossible" << std::endl;
    }

    try {
        double d = toDouble(std::stod(input));
        std::cout << "double: " << d << (d == static_cast<int>(d) ? ".0" : "") << std::endl;
    } catch (const std::exception &e) {
        std::cout << "double: impossible" << std::endl;
    }
}

char ScalarConverter::toChar(int value) {
    if (!isDisplayableChar(static_cast<char>(value))) {
        std::cout << "char: Non displayable\n";
    }
    return static_cast<char>(value);
}

int ScalarConverter::toInt(int value) {
    return value;
}

float ScalarConverter::toFloat(float value) {
    if (std::isnan(value)) {
        return NAN;
    } else if (std::isinf(value)) {
        return value > 0 ? INFINITY : -INFINITY;
    }
    return value;
}

double ScalarConverter::toDouble(double value) {
    if (std::isnan(value)) {
        return NAN;
    } else if (std::isinf(value)) {
        return value > 0 ? INFINITY : -INFINITY;
    }
    return value;
}

bool ScalarConverter::isDisplayableChar(int value) {
    return (value >= 32 && value <= 126);
}
