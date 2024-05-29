#include <iostream>
#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
		return (1);
	try
	{
		BitcoinExchange exchange;

		exchange.exchange(argv[1]);
		std::cout
				<< "ok" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
	return (0);
};