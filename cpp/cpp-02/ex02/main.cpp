#include <iostream>
#include "Fixed.hpp"

int main( void ) {

	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;

	std::cout << std::endl << "My tests:" << std::endl;

	Fixed c(42);
	Fixed d(21);
	Fixed e(42);
	Fixed f(21);

	std::cout << "c = " << c << std::endl;
	std::cout << "d = " << d << std::endl;
	std::cout << "e = " << e << std::endl;
	std::cout << "f = " << f << std::endl;
	
	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;

	std::cout << "c + d = " << c + d << std::endl;
	std::cout << "c - d = " << c - d << std::endl;
	std::cout << "c * d = " << c * d << std::endl;
	std::cout << "c / d = " << c / d << std::endl;

	std::cout << "c > d = " << (c > d) << std::endl;
	std::cout << "c < d = " << (c < d) << std::endl;
	std::cout << "c >= d = " << (c >= d) << std::endl;
	std::cout << "c <= d = " << (c <= d) << std::endl;
	std::cout << "c == d = " << (c == d) << std::endl;
	std::cout << "c != d = " << (c != d) << std::endl;

	std::cout << "min(c, d) = " << Fixed::min(c, d) << std::endl;
	std::cout << "min(c, e) = " << Fixed::min(c, e) << std::endl;
	std::cout << "min(c, f) = " << Fixed::min(c, f) << std::endl;

	std::cout << "max(c, d) = " << Fixed::max(c, d) << std::endl;
	std::cout << "max(c, e) = " << Fixed::max(c, e) << std::endl;
	std::cout << "max(c, f) = " << Fixed::max(c, f) << std::endl;

	std::cout << "c++ = " << c++ << std::endl;
	std::cout << "++c = " << ++c << std::endl;
	std::cout << "c-- = " << c-- << std::endl;
	std::cout << "--c = " << --c << std::endl;

}