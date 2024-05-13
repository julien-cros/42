#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <algorithm>
#include <string>

template <typename Type>
int *easyfind(Type &data, int _int)
{
	typename Type::iterator ret = std::find(data.begin(), data.end(), _int);

	if (ret == data.end())
		return NULL;
	else
		return &(*ret);
}

#endif