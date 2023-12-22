#include <iostream>
#include "Dog.hpp"
#include "Animal.hpp"

Dog::Dog() : Animal("Dog"), name("Dog")
{
	std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(std::string const &name) : Animal("Dog"), name(name)
{
	std::cout << "Dog constructor called" << std::endl;
}

Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound() const
{
	std::cout << "Woof!" << std::endl;
}

Dog::Dog(Dog const &other)
{
	std::cout << "Dog copy constructor called" << std::endl;
	*this = other;
}

Dog &Dog::operator=(Dog const &other)
{
	std::cout << "Dog assignation operator called" << std::endl;
	if (this != &other)
		this->type = other.type;
	return (*this);
}