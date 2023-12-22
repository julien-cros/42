#include "MateriaSource.hpp"

MateriaSource::MateriaSource() : index(0) {
	for (int i = 0; i < 4; i++) {
		this->memory[i] = NULL;
	}
}

MateriaSource::MateriaSource(MateriaSource const &src) {
	*this = src;
}

MateriaSource::~MateriaSource() {
	for (int i = 0; i < 4; i++) {
		if (this->memory[i] != NULL) {
			delete this->memory[i];
		}
	}
}

MateriaSource &	MateriaSource::operator=(MateriaSource const &cpy) {
	if (this != &cpy) {
		for (int i = 0; i < 4; i++) {
			if (this->memory[i] != NULL) {
				delete this->memory[i];
			}
		}
		for (int i = 0; i < 4; i++) {
			if (cpy.memory[i] != NULL) {
				this->memory[i] = cpy.memory[i]->clone();
			}
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
}

AMateria *	MateriaSource::createMateria(std::string const &type) {
	for (int i = 0; i < 4; i++) {
		if (this->memory[i] != NULL && this->memory[i]->getType() == type) {
			return this->memory[i]->clone();
		}
	}
	return NULL;
}