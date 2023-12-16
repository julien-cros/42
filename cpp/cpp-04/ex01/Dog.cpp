#include <iostream>
#include "Dog.hpp"
#include "Animal.hpp"

Dog::Dog() : Animal("Dog"), name("Dog"), brain(new Brain())
{
	std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(std::string const &name) : Animal("Dog"), name(name)
{
	std::cout << "Dog constructor called" << std::endl;
}

Dog::~Dog()
{
	delete this->brain;
	std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound() const
{
	std::cout << "Woof!" << std::endl;
}