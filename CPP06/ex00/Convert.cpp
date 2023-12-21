#include "Convert.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::~ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &other) {
    (void)other;
}

void ScalarConverter::convert(const std::string &literal) {
    char c = toChar(literal);
    int i = toInt(literal);
    float f = toFloat(literal);
    double d = toDouble(literal);

    std::cout << "char: ";
    if (c == '\0') {
        std::cout << "impossible" << std::endl;
    } else if (isDisplayableChar(c)) {
        std::cout << "'" << c << "'" << std::endl;
    } else {
        std::cout << "Non displayable" << std::endl;
    }

    std::cout << "int: ";
    if (i == 0 && literal != "0") {
        std::cout << "impossible" << std::endl;
    } else {
        std::cout << i << std::endl;
    }

    std::cout << "float: ";
    if (f == 0.0f && literal != "0.0f") {
        std::cout << "impossible" << std::endl;
    } else {
        std::cout << f << "f" << std::endl;
    }

    std::cout << "double: ";
    if (d == 0.0 && literal != "0.0") {
        std::cout << "impossible" << std::endl;
    } else {
        std::cout << d << std::endl;
    }
}

char ScalarConverter::toChar(const std::string &literal) {
    if (literal.length() == 1) {
        return literal[0];
    } else if (literal == "0") {
        std::cout << "Non displayable" << std::endl;
        return '\0';
    }

    std::cout << "impossible" << std::endl;

    return '\0';
}

int ScalarConverter::toInt(const std::string &literal) {
    try {
        return static_cast<int>(std::stoi(literal));
    } catch (...) {
        std::cout << "impossible" << std::endl;
        return 0;
    }
}

float ScalarConverter::toFloat(const std::string &literal) {
    try {
        return static_cast<float>(std::stof(literal));
    } catch (...) {
        std::cout << "impossible" << std::endl;
        return 0.0f;
    }
}

double ScalarConverter::toDouble(const std::string &literal) {
    try {
        return std::stod(literal);
    } catch (...) {
        std::cout << "impossible" << std::endl;
        return 0.0;
    }
}

bool ScalarConverter::isDisplayableChar(char c) {
    return (c > 32 && c <= 126);
}
