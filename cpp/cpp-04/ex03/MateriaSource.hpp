#ifndef MATTERIASOURCE_HPP
# define MATTERIASOURCE_HPP

# include <iostream>
# include <string>
# include "ICharacter.hpp"
# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {
	public:
		MateriaSource();
		MateriaSource(MateriaSource const &src);
		virtual	~MateriaSource();

		MateriaSource &	operator=(MateriaSource const &cpy);

		virtual void	learnMateria(AMateria *materia);
		virtual AMateria *	createMateria(std::string const &type);

	private:
		int			index;
		AMateria *	memory[4];
};

#endif