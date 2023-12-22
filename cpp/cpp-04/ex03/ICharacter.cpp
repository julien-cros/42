 #include "ICharacter.hpp"

ICharacter::ICharacter() {}

ICharacter::ICharacter(ICharacter const &src) {
	*this = src;
}

ICharacter::~ICharacter() {}

ICharacter &ICharacter::operator=(ICharacter const &rhs) {
	(void)rhs;
	return (*this);
}
