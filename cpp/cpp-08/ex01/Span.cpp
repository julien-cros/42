#include "Span.hpp"
#include <deque>
#include <algorithm>

Span::Span() : N(0)
{
}

Span::~Span()
{
}

Span::Span(unsigned int N) : N(N)
{
}

Span::Span(const Span &copy) : N(copy.N), _deque(copy._deque)
{
}

Span &Span::operator=(const Span &rhs)
{
	this->N = rhs.N;
	this->_deque = rhs._deque;

	return *this;
}

void Span::addNumber(int value)
{
	if (_deque.size() == N)
		throw MaxSizeException();

	_deque.push_back(value);
}

int Span::shortestSpan()
{
	if (_deque.size() < 2)
		throw TooLittleException();

	std::deque<int>
			copy = _deque;
	std::sort(copy.begin(), copy.end());

	int between = copy[1] - copy[0];
	for (size_t i = 0; i < copy.size() - 1; i++)
	{
		// std::cout << (copy[i] - copy[i - 1]) << "  ";
		if ((copy[i + 1] - copy[i]) < between)
			between = copy[i + 1] - copy[i];
	}
	return (between);
}

int Span::longestSpan()
{
	if (_deque.size() < 2)
		throw TooLittleException();

	std::deque<int>
			copy = _deque;
	std::sort(copy.begin(), copy.end());
	return (copy[copy.size() - 1] - copy[0]);
}