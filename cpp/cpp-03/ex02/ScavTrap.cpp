#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string const &name) : ClapTrap(name){
	std::cout << "ScavTrap constructor called" << std::endl;
}

ScavTrap::~ScavTrap(){
	std::cout << "ScavTrap destructor called" << std::endl;
}

void ScavTrap::guardGate(){
	if (this->getEnergyPoints() == 0)
	{
		std::cout << "ScavTrap " << this->getName() << " has no energy points left!" << std::endl;
		return ;
	}
	else if (this->getHitPoints() <= 0)
	{
		std::cout << "ScavTrap " << this->getName() << " is dead!" << std::endl;
		return ;
	}
	std::cout << "ScavTrap " << this->getName() << " has entergit ed in Gate keeper mode!" << std::endl;
}

ScavTrap & ScavTrap::operator=(ScavTrap const & rhs)
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

ScavTrap::ScavTrap(ScavTrap const &rhs)
{
	std::cout << "ScavTrap copy constructor called" << std::endl;
	*this = rhs;
}