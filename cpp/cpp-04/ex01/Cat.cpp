#include <iostream>
#include "Cat.hpp"
#include "Animal.hpp"

Cat::Cat(void) : Animal("cat"), name("Cat")
{
	std::cout << "Cat constructor called!" << std::endl;
	this->brain = new Brain();
}

Cat::Cat(std::string const &name) : Animal(name), name(name)
{
	std::cout << "Cat constructor called!" << std::endl;
	this->brain = new Brain();
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

Cat &Cat::operator=(Cat const &copy)
{
	std::cout << "Cat assignation operator called!" << std::endl;
	brain = new Brain();
	if (this != &copy)
	{
		this->name = copy.name;
		for (int i = 0; i < 100; i++)
			this->brain->setIdea(i, copy.brain->getIdea(i));
	}
	return (*this);
}

Cat::Cat(Cat const &copy) : Animal(copy), name(copy.name)
{
	std::cout << "Cat copy constructor called!" << std::endl;
	this->brain = new Brain();
	for (int i = 0; i < 100; i++)
		this->brain->setIdea(i, copy.brain->getIdea(i));
}