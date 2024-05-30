#include "RPN.hpp"

RPN::RPN()
{
}

RPN::~RPN()
{
}

RPN::RPN(const RPN &rhs)
{
}

RPN &RPN::operator=(const RPN &rhs)
{
	return *this;
}

double RPN::run(const std::string &expression)
{

	for (int i = 0; i < expression.length(); i++)
	{
		char c = expression[i];
		if (expression[i] == ' ')
			continue;
		else if (isdigit(c))
		{
			_num.push(c - '0');
			continue;
		}

		if (_num.size() < 2)
			throw InvalidExpression();

		if (expression[i] == '+' && i % 2 == 0)
		{
			double b = _num.top();
			_num.pop();
			double a = _num.top();
			_num.pop();
			_num.push(a + b);
			std::cout << a << " + " << b << " = " << a + b << std::endl;
		}
		else if (expression[i] == '-' && i % 2 == 0)
		{
			double b = _num.top();
			_num.pop();
			double a = _num.top();
			_num.pop();

			_num.push(a - b);
			std::cout << a << " - " << b << " = " << a - b << std::endl;
		}
		else if (expression[i] == '*' && i % 2 == 0)
		{
			double b = _num.top();
			_num.pop();
			double a = _num.top();
			_num.pop();

			_num.push(a * b);
			std::cout << a << " * " << b << " = " << a * b << std::endl;
		}
		else if (expression[i] == '/' && i % 2 == 0)
		{
			double b = _num.top();
			_num.pop();
			double a = _num.top();
			_num.pop();
			_num.push(a / b);

			if (b == 0)
				throw InvalidExpression();
			std::cout << a << " / " << b << " = " << a / b << std::endl;
		}
		else
			throw InvalidExpression();
	}
	return _num.top();
}
