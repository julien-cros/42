#include <iostream>
#include "Cat.hpp"
#include "Animal.hpp"

Cat::Cat(void) : Animal("cat"), name("Cat"), brain(new Brain())
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
	delete this->brain;
	std::cout << "Cat destructor called!" << std::endl;
}

void Cat::makeSound() const
{
	std::cout << "Miaou!" << std::endl;
}