#include <iostream>

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string const &name) : name(name), hitPoints(10), energyPoints(10), attackDamage(0)
{
	std::cout << "ClapTrap constructor called" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destructor called" << std::endl;
}

void ClapTrap::attack(std::string const &target)
{
	if (this->energyPoints == 0)
	{
		std::cout << "ClapTrap " << this->name << " has no energy points left!" << std::endl;
		return ;
	}
	this->energyPoints--;
	std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing " << this->attackDamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->hitPoints > 0)
	{	
		this->hitPoints -= amount;
		std::cout << "ClapTrap " << this->name << " takes " << amount << " points of damage!" << std::endl;
	}
	if (this->hitPoints <= 0)
	{
		std::cout << "ClapTrap " << this->name << " is dead!" << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->energyPoints <= 0)
	{
		std::cout << "ClapTrap " << this->name << " has no energy points left!" << std::endl;
		return ;
	}
	if (this->hitPoints <= 0)
	{
		std::cout << "ClapTrap " << this->name << " is dead!" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << this->name << " is repaired for " << amount << " points!" << std::endl;
}