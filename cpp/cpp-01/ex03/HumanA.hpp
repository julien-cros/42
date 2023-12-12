#include <iostream>

#include "Weapon.hpp"

#ifndef HUMANA_HPP
# define HUMANA_HPP

class HumanA
{
public:
	HumanA(std::string const &name, Weapon &weapon);
	~HumanA();
	void attack();

private:
	std::string name;
	Weapon *weapon;
};

#endif