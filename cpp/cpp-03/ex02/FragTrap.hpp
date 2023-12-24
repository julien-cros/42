#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	public:
		FragTrap();
		explicit FragTrap(std::string const &name);
		FragTrap(FragTrap const &rhs);
		FragTrap & operator=(FragTrap const &rhs);
		~FragTrap();
		void highFivesGuys(void);
};

#endif