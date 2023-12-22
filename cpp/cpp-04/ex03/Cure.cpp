#include "Cure.hpp"

Cure::Cure() : AMateria("cure") {
}

Cure::Cure(Cure const &src) : AMateria(src) {
}

Cure::~Cure() {
}

Cure &	Cure::operator=(Cure const &cpy) {
	if (this != &cpy) {
		this->type = cpy.type;
	}
	return *this;
}

AMateria *	Cure::clone() const {
	return new Cure(*this);
}

void	Cure::use(ICharacter &target) {
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}