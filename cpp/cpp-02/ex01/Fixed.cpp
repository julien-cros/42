#include <iostream>
#include "Fixed.hpp"

Fixed::Fixed() : value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &rhs)
{
	std::cout << "Copy constructor called" << std::endl;
	this->setRawBits(rhs.getRawBits());
}

Fixed::Fixed(const int value) : value(value << Fixed::bits)
{
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float value) : value(roundf(value * (1 << Fixed::bits)))
{
	std::cout << "Float constructor called" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &rhs)
{
	std::cout << "Assignation operator called" << std::endl;
	this->setRawBits(rhs.getRawBits());
	return (*this);
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->value);
}

void Fixed::setRawBits(int const raw)
{
	this->value = raw;
}

int Fixed::toInt(void) const
{
	return (this->value >> Fixed::bits);
}

float Fixed::toFloat(void) const
{
	return ((float)this->value / (1 << Fixed::bits));
}

std::ostream &operator<<(std::ostream &out, const Fixed &rhs)
{
	out << rhs.toFloat();
	return (out);
}