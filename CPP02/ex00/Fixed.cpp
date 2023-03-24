#include "Fixed.hpp"

Fixed::Fixed() : fixedValue(0)
{
    cout << "Default constructor called" << endl;
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
    cout << "Copy assigment operator called" << endl;
    this->fixedValue = other.getRawBits();
    return *this;
}

int Fixed::getRawBits() const
{
    cout << "getRawBits member function called" << endl;
    return this->fixedValue;
}

void Fixed::setRawBits(const int fixedValue)
{
    cout << "setRawBits member function called" << endl;
    this->fixedValue = fixedValue;
}
