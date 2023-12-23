#include "MateriaSource.hpp"
#include "IMateriaSource.hpp"

MateriaSource::MateriaSource() : index(0) {
	
}

MateriaSource::MateriaSource(MateriaSource const &src) {
	*this = src;
}

MateriaSource::~MateriaSource() {
	int	idx = -1;
	
	while (++idx < index) {
		delete this->memory[idx];
	}
}

MateriaSource &	MateriaSource::operator=(MateriaSource const &cpy) {
	if (this != &cpy) {
		{
			this->index = cpy.index;
		int idx = -1; while (++idx < 4)
			this->memory[idx] = cpy.memory[idx];
		}
	}
	return *this;
}

void	MateriaSource::learnMateria(AMateria *materia) {
	if (this->index < 4) {
		this->memory[this->index] = materia;
		this->index++;
	}
	else {
		std::cout << "MateriaSource memory is full" << std::endl;
	}
}

AMateria *	MateriaSource::createMateria(std::string const &type) {
	int	idx = -1; while (++idx < index) {
		if (this->memory[idx]->getType() == type)
			return this->memory[idx];
	}
	std::cout << "MateriaSource memory doesn't contain " << type << std::endl;
	return NULL;
}

IMateriaSource::~IMateriaSource()
{
}