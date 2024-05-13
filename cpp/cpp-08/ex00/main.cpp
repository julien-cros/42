#include <iostream>
#include <vector>
#include <list>
#include "easyfind.hpp"

template <typename Type>
void find(Type &data, int value)
{
	const int *ret = easyfind(data, value);

	if (ret)
		std::cout << value << " has been find" << std::endl;
	else
		std::cout << value << " has not been find" << std::endl;
}

int main()
{
	int ints[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int toFind = 3;
	int cannot = 19;

	std::list<int> _list(ints, ints + 10);
	std::cout << "For a list container ";
	find(_list, toFind);

	std::vector<int> _vector(ints, ints + 10);
	std::cout << "For a vector container ";
	find(_vector, toFind);
	std::cout << "For a vector container ";
	find(_vector, cannot);
}