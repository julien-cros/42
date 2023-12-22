#include <iostream>
#include "WrongDog.hpp"
#include "WrongAnimal.hpp"

WrongDog::WrongDog() : WrongAnimal("WrongDog")
{
	std::cout << "WrongDog default constructor called" << std::endl;
	this->name = "WrongDog";
}

WrongDog::WrongDog(std::string const &name) : WrongAnimal("WrongDog")
{
	std::cout << "WrongDog constructor called" << std::endl;
	this->name = name;
}

WrongDog::~WrongDog()
{
	std::cout << "WrongDog destructor called" << std::endl;
}

void WrongDog::makeSound() const
{
	std::cout << this->name << " Miaou!" << std::endl;
}

WrongDog::WrongDog(WrongDog const &other)
{
	std::cout << "WrongDog copy constructor called" << std::endl;
	*this = other;
}

WrongDog &WrongDog::operator=(WrongDog const &other)
{
	std::cout << "WrongDog assignation operator called" << std::endl;
	if (this != &other)
		this->name = other.name;
	return (*this);
}