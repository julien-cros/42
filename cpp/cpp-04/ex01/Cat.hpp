#ifndef CAT_HPP
#define CAT_HPP

#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
	private:
		std::string name;
		Brain *brain;

	public:
		Cat();
		explicit Cat(std::string const &name);
		virtual ~Cat();
		void makeSound() const;
};

#endif