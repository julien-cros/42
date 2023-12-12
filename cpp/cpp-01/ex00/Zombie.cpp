#include <iostream>
#include <string>

#include "Zombie.hpp"

// cppcheck-suppress passedByValue
Zombie::Zombie(std::string name)
{
	this->name = name;
}

Zombie::~Zombie()
{
	std::cout << "<" << this->name << "> is dead" << std::endl;
}

void Zombie::announce()
{
	std::cout << "<" << this->name << "> BraiiiiiiinnnzzzZ..." << std::endl;
}

// cppcheck-suppress passedByValue
Zombie *newZombie(std::string name)
{
	return new Zombie(name);
}

void randomChump(std::string name)
{
	Zombie zombie(name);
	zombie.announce();
}
