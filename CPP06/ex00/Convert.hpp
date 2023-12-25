#include <string>
#include <iostream>
#include <cstdlib>
#include <cmath>

class ScalarConverter
{
public:
    ScalarConverter();
    ~ScalarConverter();
    ScalarConverter(const ScalarConverter &other);
    ScalarConverter &operator=(const ScalarConverter &other);

    static bool isDisplayableChar(char c);

    static void convert(const std::string &input);

private:
    static char toChar(char value);
    static int toInt(int value);
    static float toFloat(float value);
    static double toDouble(double value);
};
