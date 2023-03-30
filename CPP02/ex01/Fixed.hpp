#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>
using std::cout;
using std::endl;
using std::ostream;

class Fixed
{
private:
    int fixedValue;
    static const int fractionalBits = 8;

public:
    Fixed(void);
    Fixed(const int val);
    Fixed(const float val);
    Fixed(const Fixed &other);
    ~Fixed(void);

    Fixed &operator=(const Fixed &other);

    int getRawBits(void) const;
    void setRawBits(int const raw);

    float toFloat(void) const;
    int toInt(void) const;
};

ostream &operator<<(ostream &os, const Fixed &fixed);

#endif
