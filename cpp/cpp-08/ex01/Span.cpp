#include "Span.hpp"
#include <deque>
#include <algorithm>
#include <numeric>
#include <limits>
#include <iterator>
#include <random>

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
	if (_deque.size() >= N)
		throw MaxSizeException();

	_deque.push_back(value);
}

int Span::shortestSpan()
{
	if (_deque.size() < 2)
		throw TooLittleException();

	std::deque<int> copy = _deque;
	std::sort(copy.begin(), copy.end());
	std::deque<int> diffArray(copy);

	std::adjacent_difference(copy.begin(), copy.end(), diffArray.begin());
	int minValue = *std::min_element((diffArray.begin()), diffArray.end());
	return (minValue);
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

void Span::fill(int i)
{
	for (int j = 0; j < i; j++)
	{
		addNumber(rand());
			}
}