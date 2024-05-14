#include <iostream>
#include "Array.hpp"

int main()
{
	try
	{
		Array<int> intCalss(10);
		std::cout << "the size is : " << intCalss.size() << std::endl;

		intCalss[5] = 3;
		intCalss[6] = 9;
		std::cout << "intClass[5] : " << intCalss[5] << std::endl;
		std::cout << "intClass[6] : " << intCalss[6] << std::endl;
		return (0);
	}
	catch (std::exception &e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
}