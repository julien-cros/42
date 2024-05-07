#ifndef WHATEVER_HPP
#define WHATEVER_HPP

template <typename Type>
void swap(Type &a, Type &b)
{
	Type buffer = a;
	a = b;
	b = buffer;
}

template <typename Type>
Type min(Type &a, Type &b)
{
	if (a < b)
		return (a);
	return (b);
}

template <typename Type>
Type max(Type &a, Type &b)
{
	if (a < b)
		return (b);
	return (a);
}

#endif