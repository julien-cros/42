#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	public:
		explicit FragTrap(std::string name);
		~FragTrap();
		void highFivesGuys(void);
};

#endif