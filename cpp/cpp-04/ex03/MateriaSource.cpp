#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
}

MateriaSource::MateriaSource(MateriaSource const &src)
{
	*this = src;
}

MateriaSource::~MateriaSource()
{
}

MateriaSource &MateriaSource::operator=(MateriaSource const &rhs)
{
	if (this != &rhs)
	{
	}
	return (*this);
}

void MateriaSource::learnMateria(AMateria *m)
{
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
	return (NULL);
}

// int main()