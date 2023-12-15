#ifndef ClapTrap_HPP
#define ClapTrap_HPP

#include <iostream>

class ClapTrap
{
	private:
		std::string name;
		int hitPoints;
		int energyPoints; 
		int attackDamage;

	public:
		explicit ClapTrap(std::string const &name);
		~ClapTrap();

		void attack(std::string const &target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

		std::string getName();
		int getHitPoints();
		int getEnergyPoints();
		int getAttackDamage();

		void setHitPoints(int hitPoints);
};

#endif