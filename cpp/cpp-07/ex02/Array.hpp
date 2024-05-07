#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template <typename Type>
class Array
{
private:
	Type *_array;
	unsigned int _size;

public:
	Array();
	Array(unsigned int n);
	Array(const Array &copy);
	~Array();

	Array &
	operator=(const Array &rhs);
	Type &operator[](unsigned int index);
	const unsigned int size() const;

	class OutOfBoundsException : public std::exception
	{
	public:
		virtual const char *what() const throw()
		{
			return "out of bounds";
		}
	};
};

template <typename Type>
Array<Type>::Array()
{
	_array = NULL;
	_size = 0;
}

template <typename Type>
Array<Type>::~Array()
{
	delete[] _array;
}

template <typename Type>
Array<Type>::Array(unsigned int n)
{
	_array = new Type[n];
	_size = n;
}

template <typename Type>
Array<Type>::Array(const Array &copy)
{
	_array = new Type[copy._size];
	_size = copy._size;
}
template <typename Type>
Array<Type> &Array<Type>::operator=(const Array &rhs)
{
	if (_array != NULL)
		delete[] _array;

	_array = new Type[rhs._size];
	_size = rhs._size;

	for (int i = 0; i++; i < rhs._size)
		_array[i] = rhs._array[i];

	return (*this);
}

template <typename Type>
const unsigned int Array<Type>::size() const
{
	return (_size);
}

template <typename Type>
Type &Array<Type>::operator[](unsigned int index)
{
	if (index < 0 || index >= _size)
		throw OutOfBoundsException();
	return (_array[index]);
}

#endif