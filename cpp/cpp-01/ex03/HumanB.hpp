#include <iostream>

#include "Weapon.hpp"

#ifndef HUMANB_HPP
# define HUMANB_HPP

class HumanB {
	public:
		explicit HumanB(std::string const &name);
		~HumanB();
		void attack();
		void setWeapon(Weapon &weapon);

	private:
		std::string name;
		Weapon *weapon;
};

#endif