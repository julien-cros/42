#include <iostream>
#include <string>

#include "ZombieClass.hpp"

ZombieClass::ZombieClass(std::string name)
{
	this->name = name;
}

ZombieClass::~ZombieClass()
{
	(void)name;
}

void ZombieClass::announce()
{
	std::cout << "<" << this->name << "> BraiiiiiiinnnzzzZ..." << std::endl;
}

ZombieClass *newZombie(std::string name)
{
	return new ZombieClass(name);
}

void randomChump(std::string name)
{
	ZombieClass zombie(name);
	zombie.announce();
}
