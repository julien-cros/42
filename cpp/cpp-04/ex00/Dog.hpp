#ifndef DOG_HPP
#define DOG_HPP

#include <iostream>
#include "Animal.hpp"

class Dog : public Animal
{
	private:
		std::string name;
		
	public:
		Dog();
		Dog(std::string const &name);
		virtual ~Dog();
		void makeSound() const;
};

#endif