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
		ClapTrap(ClapTrap const &rhs);
		~ClapTrap();

		void attack(std::string const &target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

		ClapTrap & operator=(ClapTrap const & rhs);
		std::string const & getName() const;
		int getHitPoints();
		int getEnergyPoints();

		void setHitPoints(int hitPoints);
};

#endif