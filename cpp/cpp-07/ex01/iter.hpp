#ifndef ITER_HPP
#define ITER_HPP

template <typename Type>
void iter(Type *array, int length, void (*f)(Type &))
{
	int i = 0;
	while (i < length)
	{
		f(array[i]);
		i++;
	}
}

template <typename Type>
void increment(Type &a)
{
	a += 1;
}

#endif