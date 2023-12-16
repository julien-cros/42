#include <iostream>
#include "Animal.hpp"

Animal::Animal (void) : type("Animal")
{
	std::cout << "Animal construcor called!" << std::endl;
}

Animal::Animal (std::string const &name) : type(name)
{
	std::cout << "Animal constructor called!" << std::endl;
}

Animal::~Animal(void)
{
	std::cout << "Animal destructor called!" << std::endl;
}

std::string Animal::getType() const
{
	return (this->type);
}

void Animal::makeSound() const
{
	std::cout << this->type << "just made sound!" << std::endl;
}