#include <iostream>
#include "MutantStack.hpp"

// int main()
// {
// 	MutantStack<int> stack;

// 	stack.push(10);
// 	stack.push(5);
// 	stack.push(3);
// 	stack.push(7);
// 	stack.push(2);
// 	stack.push(4);
// 	std::cout << "Top number: " << stack.top() << std::endl;

// 	stack.pop();

// 	std::cout << "Stack size: " << stack.size() << std::endl;

// 	MutantStack<int>::iterator itBegin = stack.begin();
// 	// MutantStack<int>::iterator itEnd = stack.end();

// 	for (int i = 0; i <= stack.size(); i++)
// 		std::cout << *itBegin++ << std::endl;
// }

int main()
{
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);

	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
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
	it = mstack.begin();
	while (ite != it)
	{
		std::cout << *ite << std::endl;
		--ite;
	}
	std::cout << std::endl;
	std::stack<int>
			s(mstack);
}