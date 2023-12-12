#include <iostream>
#include "Weapon.hpp"
#include "HumanA.hpp"

HumanA::HumanA(std::string const &name, Weapon &weapon) {
	this->name = name;
	this->weapon = &weapon;
}

HumanA::~HumanA() {
}

void HumanA::attack() {
	std::cout << this->name << " attacks with his " << this->weapon->getType() << std::endl;
}