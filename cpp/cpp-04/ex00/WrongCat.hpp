#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include <iostream>
#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	private:
		std::string name;
	
	public:
		WrongCat();
		WrongCat(std::string const &name);
		virtual ~WrongCat();
		std::string getName() const;
		void makeSound() const;
};

#endif