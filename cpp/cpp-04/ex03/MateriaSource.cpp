#include "MateriaSource.hpp"

MateriaSource::MateriaSource() : index(0) {
	
}

MateriaSource::MateriaSource(MateriaSource const &src) {
	*this = src;
}

MateriaSource::~MateriaSource() {
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

void	MateriaSource::getMemory() const {
	std::cout << "MateriaSource memory:" << std::endl;
	for (int i = 0; i < 4; i++) {
		if (this->memory[i] != NULL) {
			std::cout << "memory[" << i << "] = " << this->memory[i]->getType() << std::endl;
		}
		else {
			std::cout << "memory[" << i << "] = NULL" << std::endl;
		}
	}
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