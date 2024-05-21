#include <iostream>
#include <vector>
#include <list>
#include "easyfind.hpp"

template <typename Type>
void find(Type &data, int value)
{
	const int *ret = easyfind(data, value);

	if (ret)
		std::cout << value << " has been found" << std::endl;
	else
		std::cout << value << " has not been found" << std::endl;
}

int main()
{
	int ints[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int valid = 3;
	int invalid = 19;

	std::list<int> _list(ints, ints + 10);
	std::cout << "For a list container ";
	find(_list, valid);

	std::vector<int> _vector(ints, ints + 10);
	std::cout << "For a vector container ";
	find(_vector, valid);
	std::cout << "For a vector container ";
	find(_vector, invalid);
}