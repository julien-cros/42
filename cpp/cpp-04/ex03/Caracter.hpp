#ifndef CARACTER_HPP
#define CARACTER_HPP

#include <iostream>
#include <string>
#include "ICharacter.hpp"

class Caracter : public ICharacter
{
	private:
		std::string name;
		AMateria *inventory[4];
	
	public:
		Caracter();
		Caracter(std::string const &name);
		Caracter(Caracter const &src);
		virtual ~Caracter();

		Caracter &operator=(Caracter const &rhs);

		std::string const &getName() const;
		void equip(AMateria *m);
		void unequip(int idx);
		void use(int idx, ICharacter &target);
};

#endif