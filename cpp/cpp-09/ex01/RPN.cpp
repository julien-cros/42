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

bool verifyExpression(const std::string &expression)
{
	int op = 0;
	int num = 0;
	for (int i = 0; i < expression.length(); i++)
	{
		if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/')
			op++;
		else if (isdigit(expression[i]))
			num++;
		else if (expression[i] != ' ')
			return false;
	}
	if (op != num - 1)
		return false;
	return true;
}

double RPN::run(const std::string &expression)
{
	if (!verifyExpression(expression))
		throw Error();
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
			throw Error();

		if (expression[i] == '+')
		{
			double b = _num.top();
			_num.pop();
			double a = _num.top();
			_num.pop();
			_num.push(a + b);
		}
		else if (expression[i] == '-')
		{
			double b = _num.top();
			_num.pop();
			double a = _num.top();
			_num.pop();

			_num.push(a - b);
		}
		else if (expression[i] == '*')
		{
			double b = _num.top();
			_num.pop();
			double a = _num.top();
			_num.pop();

			_num.push(a * b);
		}
		else if (expression[i] == '/')
		{
			double b = _num.top();
			_num.pop();
			double a = _num.top();
			_num.pop();
			_num.push(a / b);

			if (b == 0)
				throw Error();
		}
		else
			throw Error();
	}
	return _num.top();
}
