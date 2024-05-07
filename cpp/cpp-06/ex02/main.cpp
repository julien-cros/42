#include "base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

Base *generate(void)
{
	int random = rand() % 3;
	if (random == 0)
	{
		std::cout << "A instance created" << std::endl;
		return new A();
	}
	else if (random == 1)
	{
		std::cout << "B instance created" << std::endl;
		return new B();
	}
	else
	{
		std::cout << "C instance created" << std::endl;
		return new C();
	}
}

void identify(Base *p)
{
	if (dynamic_cast<A *>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << "C" << std::endl;
}

void identify(Base &p)
{
	try
	{
		A &a = dynamic_cast<A &>(p);
		(void)a;
		std::cout << "A" << std::endl;
	}
	catch (std::exception &e)
	{
	}
	try
	{
		B &b = dynamic_cast<B &>(p);
		(void)b;
		std::cout << "B" << std::endl;
	}
	catch (std::exception &e)
	{
	}
	try
	{
		C &c = dynamic_cast<C &>(p);
		(void)c;
		std::cout << "C" << std::endl;
	}
	catch (const std::exception &e)
	{
	}
}

int main()
{
	srand(time(NULL));

	Base *pointer = generate();
	Base &reference = *pointer;

	identify(&reference);
	identify(*pointer);

	delete pointer;

	return (0);
}
