#include <iostream>

#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed
{
	private:
		int					value;
		static const int	bits = 8;

	public:
		Fixed();
		Fixed(const Fixed &copy);
		explicit Fixed(const int value);
		explicit Fixed(const float value);
		~Fixed();
		Fixed &operator=(const Fixed &copy);
		int getRawBits(void) const;
		void setRawBits(int const raw);
		int toInt(void) const;
		float toFloat(void) const;
};

std::ostream &operator<<(std::ostream &out, const Fixed &rhs);

#endif