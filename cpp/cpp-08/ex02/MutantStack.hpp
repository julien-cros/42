#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>
#include <iterator>

template <typename T>
class MutantStack : public std::stack<T>
{
public:
	MutantStack() : std::stack<T>(){};
	~MutantStack(){};
	MutantStack(const MutantStack &copy) : std::stack<T>() { *this = copy; };

	MutantStack &operator=(const MutantStack &rhs)
	{
		std::stack<T>::operator=();
		{
			return *this;
		};
	};

	typedef typename std::stack<T>::container_type::iterator iterator;

	iterator begin()
	{
		return (this->c.begin());
	}
	iterator end()
	{
		return (this->c.end());
	}
};

#endif