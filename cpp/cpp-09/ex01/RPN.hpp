#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>

class RPN
{
public:
	RPN();
	~RPN();
	RPN(const RPN &rhs);
	RPN &operator=(const RPN &rhs);
	double run(const std::string &expression);

private:
	std::stack<int> _num;

	class Error : public std::exception
	{
	public:
		const char *what() const throw() { return "Error"; };
	};
	class InvalidTooBig : public std::exception
	{
	public:
		const char *what() const throw() { return "Your args must be between 0 and 9 included."; };
	};
};

#endif // RPN_HPP