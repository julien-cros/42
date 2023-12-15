#ifndef ScavTrap_HPP
# define ScavTrap_HPP

# include <iostream>
# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
	public:
		explicit ScavTrap(std::string const &name);
		~ScavTrap();
		void guardGate();
};

#endif