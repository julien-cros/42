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

void WrongCat::makeSound() const
{
	std::cout << this->name << " Woof!" << std::endl;
}

WrongCat::WrongCat(WrongCat const &copy)
{
	std::cout << "WrongCat copy constructor called" << std::endl;
	*this = copy;
}

WrongCat &WrongCat::operator=(WrongCat const &copy)
{
	std::cout << "WrongCat assignation operator called" << std::endl;
	if (this != &copy)
		this->name = copy.name;
	return (*this);
}