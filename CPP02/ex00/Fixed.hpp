#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
using std::cout;
using std::endl;

class Fixed
{
private:
    int fixedValue;
    static const int fractionalBits = 8;

public:
    Fixed();
    Fixed(const Fixed &other);
    ~Fixed();
    Fixed &operator=(const Fixed &other);

    int getRawBits() const;
    void setRawBits(const int fixedValue);
};

#endif
