#include <iostream>

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void)
{
	ClapTrap clapTrap("ClapTrap");
	ScavTrap scavTrap("ScavTrap");
	FragTrap fragTrap("FragTrap");

	std::cout << std::endl;

	clapTrap.attack("target");
	clapTrap.takeDamage(5);
	clapTrap.beRepaired(5);

	std::cout << std::endl;

	scavTrap.attack("target");
	scavTrap.takeDamage(5);
	scavTrap.beRepaired(5);
	scavTrap.guardGate();

	std::cout << std::endl;

	fragTrap.attack("target");
	fragTrap.takeDamage(5);
	fragTrap.beRepaired(5);
	fragTrap.highFivesGuys();

	std::cout << std::endl;

	return (0);
}