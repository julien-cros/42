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
		Dog(Dog const &other);
		Dog &operator=(Dog const &other);
		explicit Dog(std::string const &name);
		virtual ~Dog();
		void makeSound() const;
};

#endif