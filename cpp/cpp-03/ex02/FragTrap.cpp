#include <iostream>

#include "ClapTrap.hpp"
#include "FragTrap.hpp"

FragTrap::FragTrap(std::string const &name) : ClapTrap(name)
{
	std::cout << "FragTrap constructor called" << std::endl;
	this->setHitPoints(100);
	this->setEnergyPoints(100);
	this->setAttackDamage(30);
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor called" << std::endl;
}

void FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << this->getName() << " requests a high five!" << std::endl;
}

FragTrap & FragTrap::operator=(FragTrap const & rhs)
{
	if (this != &rhs)
	{
		this->energyPoints = rhs.energyPoints;
		this->attackDamage = rhs.attackDamage;
		this->hitPoints = rhs.hitPoints;
		this->name = rhs.name;
	}
	return (*this);
}

FragTrap::FragTrap(FragTrap const &rhs)
{
	std::cout << "FragTrap copy constructor called" << std::endl;
	*this = rhs;
}