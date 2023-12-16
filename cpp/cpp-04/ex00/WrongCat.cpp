#include <iostream>
#include "WrongCat.hpp"
#include "WrongAnimal.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
	std::cout << "WrongCat default constructor called" << std::endl;
	this->name = "WrongCat";
}

WrongCat::WrongCat(std::string const &name) : WrongAnimal("WrongCat")
{
	std::cout << "WrongCat constructor called" << std::endl;
	this->name = name;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor called" << std::endl;
}

std::string WrongCat::getName() const
{
	return (this->name);
}

void WrongCat::makeSound() const
{
	std::cout << this->name << " Woof!" << std::endl;
}