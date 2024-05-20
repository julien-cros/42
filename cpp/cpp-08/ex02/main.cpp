#include <iostream>
#include "MutantStack.hpp"

int main()
{
	MutantStack<int> stack;

	stack.push(10);
	stack.push(5);
	stack.push(3);
	stack.push(7);
	stack.push(2);
	stack.push(4);
	std::cout << "Top number: " << stack.top() << std::endl;

	stack.pop();

	std::cout << "Stack size: " << stack.size() << std::endl;

	MutantStack<int>::iterator itBegin = stack.begin();
	// MutantStack<int>::iterator itEnd = stack.end();

	for (int i = 0; i <= stack.size(); i++)
		std::cout << *itBegin++ << std::endl;
}