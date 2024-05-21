#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <deque>

class Span
{
private:
	unsigned int N;
	std::deque<int> _deque;

public:
	Span();
	~Span();
	Span(unsigned int _size);
	Span(const Span &copy);

	Span &operator=(const Span &rhs);

	void addNumber(int value);
	int shortestSpan();
	int longestSpan();
	void fill(int i);

	class MaxSizeException : public std::exception
	{
	public:
		const char *what() const throw() { return "Reached limit"; };
	};

	class TooLittleException : public std::exception
	{
	public:
		const char *what() const throw() { return "There id not enough numbers"; };
	};
};

#endif