#ifndef ScavTrap_HPP
# define ScavTrap_HPP

# include <iostream>
# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
	public:
		ScavTrap();
		explicit ScavTrap(std::string const &name);
		ScavTrap(ScavTrap const &rhs);
		ScavTrap & operator=(ScavTrap const & rhs);
		~ScavTrap();
		void guardGate();
};

#endif