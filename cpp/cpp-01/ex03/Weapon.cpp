#include <iostream>
#include "Weapon.hpp"

// cppcheck-suppress passedByValue
Weapon::Weapon(std::string type) {
	this->type = type;
}

Weapon::~Weapon() {
}


std::string &Weapon::getType() {
	return (this->type);
}

// cppcheck-suppress passedByValue
void Weapon::setType(std::string type) {
	this->type = type;
}