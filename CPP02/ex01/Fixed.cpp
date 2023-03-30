#include "Fixed.hpp"

Fixed::Fixed() : fixedValue(0)
{
    cout << "Default constructor called" << endl;
}

Fixed::Fixed(const int val)
{
    cout << "Int constructor called" << endl;
    fixedValue = val << fractionalBits;
}

Fixed::Fixed(const float val)
{
    cout << "Float constructor called" << endl;
    fixedValue = roundf(val * (1 << fractionalBits));
}

Fixed::Fixed(const Fixed &other)
{
    cout << "Copy constructor called" << endl;
    *this = other;
}

Fixed::~Fixed()
{
    cout << "Destructor called" << endl;
}

Fixed &Fixed::operator=(const Fixed &other)
{
    cout << "Copy assignment operator called" << endl;
    if (this != &other)
        fixedValue = other.getRawBits();
    return *this;
}

int Fixed::getRawBits() const
{
    cout << "getRawBits member function called" << endl;
    return fixedValue;
}

void Fixed::setRawBits(int const raw)
{
    fixedValue = raw;
}

float Fixed::toFloat() const
{
    return (float)fixedValue / (1 << fractionalBits);
}

int Fixed::toInt() const
{
    return fixedValue >> fractionalBits;
}

ostream &operator<<(ostream &os, const Fixed &fixed)
{
    os << fixed.toFloat();
    return os;
}
