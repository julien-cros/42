#include <iostream>
#include "Dog.hpp"
#include "Animal.hpp"
#include "Brain.hpp"

Dog::Dog() : Animal("Dog"), name("Dog")
{
	std::cout << "Dog default constructor called" << std::endl;
	this->brain = new Brain();
}

Dog::Dog(std::string const &name) : Animal("Dog"), name(name)
{
	std::cout << "Dog constructor called" << std::endl;
	this->brain = new Brain();
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

Dog &Dog::operator=(Dog const &copy)
{
	std::cout << "Dog assignation operator called" << std::endl;
	brain = new Brain();
	if (this != &copy)
	{
		this->name = copy.name;
		for (int i = 0; i < 100; i++)
			this->brain->setIdea(i, copy.brain->getIdea(i));
	}
	return (*this);
}

Dog::Dog(Dog const &copy) : Animal(copy), name(copy.name)
{
	std::cout << "Dog copy constructor called" << std::endl;
	this->brain = new Brain();
	for (int i = 0; i < 100; i++)
		this->brain->setIdea(i, copy.brain->getIdea(i));
}