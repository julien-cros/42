#include <iostream>
#include "iter.hpp"

int main()
{

	int array[6] = {1, 2, 3, 4, 5, 6};
	iter<int>(array, 6, increment);

	std::cout << std::endl
						<< "int:";

	for (int i = 0; i < 6; i++)
		std::cout << array[i] << " ";

	std::cout << std::endl
						<< "char:";

	char char_array[6] = {'a', 'b', 'c', 'd', 'e', 'f'};
	iter<char>(char_array, 6, increment);
	for (int i = 0; i < 6; i++)
		std::cout << char_array[i] << " ";

	return (0);
}