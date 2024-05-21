#include <iostream>
#include "Span.hpp"

int main()
{
	try
	{
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << "little Span:" << std::endl << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl << std::endl;

		Span big = Span(10000);
		big.fill(10000);

		std::cout << "big Span:" << std::endl << big.shortestSpan() << std::endl;
		std::cout << big.longestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}