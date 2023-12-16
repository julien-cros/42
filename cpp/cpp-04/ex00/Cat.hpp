#ifndef CAT_HPP
#define CAT_HPP

#include <iostream>
#include "Animal.hpp"

class Cat : public Animal
{
	private:
		std::string name;
		
	public:
		Cat();
		explicit Cat(std::string const &name);
		virtual ~Cat();
		void makeSound() const;
};

#endif