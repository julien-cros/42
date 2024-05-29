#include <iostream>
#include "MutantStack.hpp"

int main()
{
	MutantStack<int> stack;
	stack.push(5);
	stack.push(17);
		std::cout << "Top number: " << stack.top() << std::endl;
	stack.pop();
		std::cout << "Stack size: " << stack.size() << std::endl;
	stack.push(3);
	stack.push(5);
	stack.push(737);

	stack.push(0);
	MutantStack<int>::iterator it = stack.begin();
	MutantStack<int>::iterator ite = stack.end();
	++it;
	--it;
	std::cout << std::endl
						<< "from start: " << std::endl;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::cout << std::endl
						<< "from end: " << std::endl;
	it = stack.begin();
	while (ite != it)
	{
		std::cout << *ite << std::endl;
		--ite;
	}
	std::cout << std::endl;
	std::stack<int>
			s(stack);
}