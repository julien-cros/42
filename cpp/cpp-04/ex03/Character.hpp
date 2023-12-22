#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <iostream>
# include <string>
# include "ICharacter.hpp"

class Character : public ICharacter {
	public:
		Character(std::string name);
		Character(Character const &src);
		virtual	~Character();

		Character &			operator=(Character const &rSym);
		virtual std::string const &	getName() const;

		virtual void		equip(AMateria *m);
		virtual void		unequip(int idx);
		virtual void		use(int idx, ICharacter &target);
	private:
		int			index;
		std::string			name;
		AMateria	*inventory[4];
};

#endif