#include <iostream>
#include "Fixed.hpp"

Fixed::Fixed() : value(0)
{
}

Fixed::Fixed(const Fixed &rhs)
{
	this->setRawBits(rhs.getRawBits());
}

Fixed::Fixed(const int value) : value(value << Fixed::bits)
{
}

Fixed::Fixed(const float value) : value(roundf(value * (1 << Fixed::bits)))
{
}

Fixed::~Fixed()
{
}

Fixed &Fixed::operator=(const Fixed &rhs)
{
	this->setRawBits(rhs.getRawBits());
	return (*this);
}

int Fixed::getRawBits(void) const
{
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

Fixed Fixed::operator+(const Fixed &rhs) const
{
	return (Fixed(this->toFloat() + rhs.toFloat()));
}

Fixed Fixed::operator-(const Fixed &rhs) const
{
	return (Fixed(this->toFloat() - rhs.toFloat()));
}

Fixed Fixed::operator*(const Fixed &rhs) const
{
	return (Fixed(this->toFloat() * rhs.toFloat()));
}

Fixed Fixed::operator/(const Fixed &rhs) const
{
	return (Fixed(this->toFloat() / rhs.toFloat()));
}

Fixed &Fixed::operator++(void)
{
	this->value++;
	return *this;
}

Fixed &Fixed::operator--(void)
{
	this->value--;
	return(*this);
}

Fixed Fixed::operator++(int)
{
	Fixed tmp(*this);
	operator++();
	return(tmp);
}

Fixed Fixed::operator--(int)
{
	Fixed tmp(*this);
	operator--();
	return(*this);
}

bool Fixed::operator>(const Fixed &rhs) const
{
	return (this->value > rhs.value);
}

bool Fixed::operator<(const Fixed &rhs) const
{
	return (this->value < rhs.value);
}

bool Fixed::operator>=(const Fixed &rhs) const
{
	return (this->value >= rhs.value);
}

bool Fixed::operator<=(const Fixed &rhs) const
{
	return (this->value >= rhs.value);
}

bool Fixed::operator==(const Fixed &rhs) const
{
	if (this->getRawBits() == rhs.getRawBits())
		return (true);
	return(false);
}


bool Fixed::operator!=(const Fixed &rhs) const
{
	if (this->getRawBits() == rhs.getRawBits())
		return (false);
	return(true);
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a.getRawBits() < b.getRawBits())
		return (a);
	return (b);
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	if (a.getRawBits() < b.getRawBits())
		return (a);
	return (b);
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a.getRawBits() > b.getRawBits())
		return (a);
	return (b);
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	if (a.getRawBits() > b.getRawBits())
		return (a);
	return (b);
}

