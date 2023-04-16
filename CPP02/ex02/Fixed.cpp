#include "Fixed.hpp"

Fixed::Fixed() : fixedValue(0) {}

Fixed::Fixed(const int val) : fixedValue(val << fractionalBits) {}

Fixed::Fixed(const float val) : fixedValue(roundf(val * (1 << fractionalBits))) {}

Fixed::Fixed(const Fixed &other) : fixedValue(other.fixedValue) {}

Fixed::~Fixed() {}

Fixed &Fixed::operator=(const Fixed &other)
{
    fixedValue = other.getRawBits();
    return *this;
}

int Fixed::toInt() const
{
    return fixedValue >> fractionalBits;
}

float Fixed::toFloat() const
{
    return (float)fixedValue / (1 << fractionalBits);
}

int Fixed::getRawBits(void) const
{
    return fixedValue;
}

void Fixed::setRawBits(int const raw)
{
    fixedValue = raw;
}

bool Fixed::operator>(const Fixed &other) const
{
    return (fixedValue > other.getRawBits());
}

bool Fixed::operator<(const Fixed &other) const
{
    return (fixedValue < other.getRawBits());
}

bool Fixed::operator>=(const Fixed &other) const
{
    return (fixedValue >= other.getRawBits());
}

bool Fixed::operator<=(const Fixed &other) const
{
    return (fixedValue <= other.getRawBits());
}

bool Fixed::operator==(const Fixed &other) const
{
    return (fixedValue == other.getRawBits());
}

bool Fixed::operator!=(const Fixed &other) const
{
    return (fixedValue != other.getRawBits());
}

Fixed Fixed::operator+(const Fixed &other) const
{
    Fixed result;
    result.setRawBits(fixedValue + other.getRawBits());
    return result;
}

Fixed Fixed::operator-(const Fixed &other) const
{
    Fixed result;
    result.setRawBits(fixedValue - other.getRawBits());
    return result;
}

Fixed Fixed::operator*(const Fixed &other) const
{
    Fixed result;
    result.setRawBits((fixedValue * other.getRawBits()) >> fractionalBits);
    return result;
}

Fixed Fixed::operator/(const Fixed &other) const
{
    Fixed result;
    result.setRawBits((fixedValue << fractionalBits) / other.getRawBits());
    return result;
}

Fixed &Fixed::operator++()
{
    fixedValue++;
    return *this;
}

Fixed Fixed::operator++(int)
{
    Fixed temp(*this);
    operator++();
    return temp;
}

Fixed &Fixed::operator--()
{
    fixedValue--;
    return *this;
}

Fixed Fixed::operator--(int)
{
    Fixed temp(*this);
    operator--();
    return temp;
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
    return (a < b) ? a : b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
    return (a < b) ? a : b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
    return (a > b) ? a : b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
    return (a > b) ? a : b;
}

ostream &operator<<(ostream &os, const Fixed &fixed)
{
    os << fixed.toFloat();
    return os;
}
