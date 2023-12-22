#include <iostream>
#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	std::cout << "WrongAnimal default constructor called" << std::endl;
	this->type = "WrongAnimal";
}

WrongAnimal::WrongAnimal(std::string const &type)
{
	std::cout << "WrongAnimal constructor called" << std::endl;
	this->type = type;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal destructor called" << std::endl;
}

std::string WrongAnimal::getType() const
{
	return (this->type);
}

void WrongAnimal::makeSound() const
{
	std::cout << this->type << "WrongAnimal!" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const &copy)
{
	std::cout << "WrongAnimal copy constructor called" << std::endl;
	*this = copy;
}

WrongAnimal &WrongAnimal::operator=(WrongAnimal const &copy)
{
	std::cout << "WrongAnimal assignation operator called" << std::endl;
	if (this != &copy)
		this->type = copy.type;
	return (*this);
}