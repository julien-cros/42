#ifndef AMAteria_HPP
# define AMAteria_HPP

# include <iostream>
# include <string>
# include "ICharacter.hpp"

class ICharacter;
class AMateria
{
	protected:
		std::string type;

	public:
		AMateria();
		AMateria(std::string const & type);
		AMateria(AMateria const & src);
		~AMateria();
		AMateria & operator=(AMateria const & rhs);
		std::string const & getType() const;
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};

#endif