#include <string>
#include <iostream>
#include <cmath>

class ScalarConverter
{
private:
    ScalarConverter();
    ScalarConverter(const ScalarConverter &other);
    ScalarConverter &operator=(const ScalarConverter &other);
    ~ScalarConverter();

public:
    static bool isDisplayableChar(int value);
    static void convert(const std::string &input);

    static char toChar(int value);
    static int toInt(int value);
    static float toFloat(float value);
    static double toDouble(double value);
};
