#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <climits>
#include <limits>
#include <cmath>
#include <iomanip>

enum e_type
{
	CHAR,
	NUM,
	UNKNOWN,
	INF,
};

class ScalarConverter
{
private:
	static e_type setType(const std::string &input);

	static void printChar(const std::string &input);
	static void printNum(const std::string &input);
	static void printSpecial(const std::string &input);

public:
	static void convert(const std::string &input);

	class InvalidScalarException : public std::exception
	{
	public:
		const char *what() const throw() { return "Invalid scalar exception"; }
	};
};

#endif