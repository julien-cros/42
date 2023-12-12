#include <iostream>
#include <string>

#include "Zombie.hpp"

Zombie::Zombie(void)
{
	this->name = "Zombie";
	std::cout << this->name << " is born" << std::endl;
}

// cppcheck-suppress passedByValue
Zombie::Zombie(std::string name)
{
	this->name = name;
	std::cout << this->name << " is born" << std::endl;
}

Zombie::~Zombie(void)
{
	std::cout << this->name << " is dead" << std::endl;
}

void Zombie::announce()
{
	std::cout << this->name << " BraiiiiiiinnnzzzZ..." << std::endl;
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

// cppcheck-suppress passedByValue
void Zombie::changeName(std::string name)
{
	this->name = name;
}
