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

std::string WrongDog::getName() const
{
	return (this->name);
}

void WrongDog::makeSound() const
{
	std::cout << this->name << " Miaou!" << std::endl;
}