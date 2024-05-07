#include <iostream>
#include "Array.hpp"

int main()
{
	Array<int> intCalss(10);
	std::cout << "the size is : " << intCalss.size() << std::endl;

	intCalss[5] = 3;
	std::cout << "intClass[5] : " << intCalss[5] << std::endl;
	return (0);
}