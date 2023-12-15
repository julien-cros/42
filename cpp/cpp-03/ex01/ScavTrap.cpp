#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string const &name) : ClapTrap(name){
	std::cout << "ScavTrap " << this->getName() << " is born!" << std::endl;
}

ScavTrap::~ScavTrap(){
	std::cout << "ScavTrap " << this->getName() << " is dead!" << std::endl;
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
	std::cout << "ScavTrap " << this->getName() << " has entered in Gate keeper mode!" << std::endl;
}