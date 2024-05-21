#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <algorithm>
#include <string>

template <typename T>
int *easyfind(T &data, int _int)
{
	typename T::iterator ret = std::find(data.begin(), data.end(), _int);

	if (ret == data.end())
		return NULL;
	else
		return &(*ret);
}

#endif