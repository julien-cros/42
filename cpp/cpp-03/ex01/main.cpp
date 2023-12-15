#include <iostream>

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
	ScavTrap ScavTrap("ScavTrap");
	ClapTrap clapTrap("ClapTrap");

	ScavTrap.attack("ClapTrap");
	ScavTrap.takeDamage(10);
	ScavTrap.beRepaired(10);
	ScavTrap.guardGate();

	clapTrap.attack("ScavTrap");
	clapTrap.takeDamage(10);
	clapTrap.beRepaired(10);

	return (0);
	
}