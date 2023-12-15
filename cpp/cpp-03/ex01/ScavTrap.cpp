#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string const &name) : ClapTrap(name){
	std::cout << "ScavTrap " << this->getName() << " is born!" << std::endl;
}

ScavTrap::~ScavTrap(){
	std::cout << "ScavTrap " << this->getName() << " is dead!" << std::endl;
}

void ScavTrap::attack(std::string const &target){
	std::cout << "ScavTrap " << this->getName() << " attacks " << target << ", causing " << this->getAttackDamage() << " points of damage!" << std::endl;
}

void ScavTrap::takeDamage(unsigned int amount){
	if (this->getHitPoints() > 0)
	{	
		this->setHitPoints(this->getHitPoints() - amount);
		std::cout << "ScavTrap " << this->getName() << " takes " << amount << " points of damage!" << std::endl;
	}
	if (this->getHitPoints() <= 0)
	{
		std::cout << "ScavTrap " << this->getName() << " is dead!" << std::endl;
	}
}

void ScavTrap::beRepaired(unsigned int amount){
	if (this->getEnergyPoints() <= 0)
	{
		std::cout << "ScavTrap " << this->getName() << " has no energy points left!" << std::endl;
		return ;
	}
	if (this->getHitPoints() <= 0)
	{
		std::cout << "ScavTrap " << this->getName() << " is dead!" << std::endl;
		return ;
	}
	std::cout << "ScavTrap " << this->getName() << " is repaired for " << amount << " points!" << std::endl;
}

void ScavTrap::guardGate(){
	std::cout << "ScavTrap " << this->getName() << " has entered in Gate keeper mode!" << std::endl;
}