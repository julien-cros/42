#include "ScalarConverter.hpp"

void ScalarConverter::convert(const std::string &input)
{
	if (input.length() == 0)
	{
		std::cout << "Error: Empty input" << std::endl;
		return;
	}

	const e_type _type = setType(input);

	switch (_type)
	{
	case CHAR:
		printChar(input);
		break;
	case (NUM):
		printNum(input);
		break;
	case (INF):
		printSpecial(input);
		break;
	case (UNKNOWN):
		throw InvalidScalarException();
		break;
	}
}

e_type ScalarConverter::setType(const std::string &input)
{
	bool findDot = false;
	int i = 0;

	if (input.length() == 1 && !isdigit(input[0]))
		return CHAR;
	else if (input == "+inf" || input == "-inf" || input == "+inff" || input == "-inff" || input == "nan" || input == "nanf")
		return INF;
	if (input[0] == '-' || input[0] == '+')
		i++;
	while (i < input.length() - 1)
	{
		if (input[i] == '.' && findDot == true)
			return (UNKNOWN);
		if (input[i] == '.')
			findDot = true;
		else if (!isdigit(input[i]))
			return (UNKNOWN);
		i++;
	}

	if ((input[i] == 'f' && !isdigit(input[i - 1])) || (i == 1 && findDot == true) || (i == 0 && input[i] == 'f'))
		return (UNKNOWN);
	return NUM;
}

void ScalarConverter::printChar(const std::string &input)
{
	double value = double(input[0]);

	if (isprint(input[0]))
	{
		std::cout << "char: '" << input[0] << "'" << std::endl;
	}
	else
		std::cout << "char: Non displayable" << std::endl;
	std::cout << "int: " << static_cast<int>(value) << std::endl;
	std::cout << "float: " << static_cast<float>(value) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(value) << std::endl;
}

void ScalarConverter::printNum(const std::string &input)
{
	double value = std::stod(input);

	if (value > INT_MAX || value < INT_MIN)
	{
		std::cout << "int: impossible" << std::endl;
		std::cout << "char: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
	}
	else
	{
		std::cout << "char: ";
		if (isprint(static_cast<char>(value)))
			std::cout << "'" << static_cast<char>(value) << "'" << std::endl;
		else
			std::cout << "Non displayable" << std::endl;
		std::cout << "int: " << static_cast<int>(value) << std::endl;
		std::cout << "float: " << static_cast<float>(value) << "f" << std::endl;
		std::cout << "double: " << static_cast<double>(value) << std::endl;
	}
}

void ScalarConverter::printSpecial(const std::string &input)
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	if (input == "+inf" || input == "+inff")
	{
		std::cout << "float: "
							<< "+inff" << std::endl;
		std::cout << "double: "
							<< "+inf" << std::endl;
	}
	else if (input == "-inf" || input == "-inff")
	{
		std::cout << "float: "
							<< "-inff" << std::endl;
		std::cout << "double: "
							<< "-inf" << std::endl;
	}
	else
	{
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
	}
}