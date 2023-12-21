#ifndef CONVERT_HPP
#define CONVERT_HPP

#include <iostream>
#include <exception>

class ScalarConverter
{
private:
    static char toChar(const std::string &literal);
    static int toInt(const std::string &literal);
    static float toFloat(const std::string &literal);
    static double toDouble(const std::string &literal);

    static bool isDisplayableChar(char c);

public:
    ScalarConverter();
    ScalarConverter(const ScalarConverter &oth);
    ~ScalarConverter();

    static void convert(const std::string &literal);
};

#endif
