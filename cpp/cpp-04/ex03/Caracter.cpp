#include "Caracter.hpp"	

Caracter::Caracter() : name("default")
{
	for (int i = 0; i < 4; i++)
		this->inventory[i] = NULL;
}

Caracter::Caracter(std::string const &name) : name(name)
{
	for (int i = 0; i < 4; i++)
		this->inventory[i] = NULL;
}

Caracter::Caracter(Caracter const &src)
{
	*this = src;
}

Caracter::~Caracter()
{
	for (int i = 0; i < 4; i++)
	{
		if (this->inventory[i])
			delete this->inventory[i];
	}
}

Caracter &Caracter::operator=(Caracter const &rhs)
{
	if (this != &rhs)
	{
		this->name = rhs.name;
		for (int i = 0; i < 4; i++)
		{
			if (this->inventory[i])
				delete this->inventory[i];
			this->inventory[i] = rhs.inventory[i]->clone();
		}
	}
	return (*this);
}

std::string const &Caracter::getName() const
{
	return (this->name);
}

void Caracter::equip(AMateria *m)
{
	for (int i = 0; i < 4; i++)
	{
		if (!this->inventory[i])
		{
			this->inventory[i] = m;
			return ;
		}
	}
}

void Caracter::unequip(int idx)
{
	if (idx >= 0 && idx < 4)
		this->inventory[idx] = NULL;
}

