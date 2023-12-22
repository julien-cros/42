#include <iostream>
#include "Cat.hpp"
#include "Animal.hpp"

Cat::Cat(void) : Animal("cat"), name("Cat")
{
	std::cout << "Cat constructor called!" << std::endl;
}

Cat::Cat(std::string const &name) : Animal(name)
{
	this->type = "Cat";
	std::cout << "Cat constructor called!" << std::endl;
}

Cat::~Cat(void)
{
	std::cout << "Cat destructor called!" << std::endl;
}

void Cat::makeSound() const
{
	std::cout << "Miaou!" << std::endl;
}

Cat::Cat(Cat const &other)
{
	std::cout << "Cat copy constructor called!" << std::endl;
	*this = other;
}

Cat &Cat::operator=(Cat const &other)
{
	std::cout << "Cat assignation operator called!" << std::endl;
	if (this != &other)
		this->type = other.type;
	return (*this);
}