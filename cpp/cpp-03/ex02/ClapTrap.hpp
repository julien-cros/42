#ifndef ClapTrap_HPP
#define ClapTrap_HPP

#include <iostream>

class ClapTrap
{
	protected:
		std::string name;
		int hitPoints;
		int energyPoints; 
		int attackDamage;

	public:
		ClapTrap();
		explicit ClapTrap(std::string const &name);
		ClapTrap(ClapTrap const &cpy);
		~ClapTrap();

		void attack(std::string const &target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

		ClapTrap & operator=(ClapTrap const &rhs);
		std::string getName();
		int getHitPoints();
		int getEnergyPoints();

		void setHitPoints(int hitPoints);
		void setEnergyPoints(int energyPoints);
		void setAttackDamage(int attackDamage);
};

#endif