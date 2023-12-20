#ifndef DOG_HPP
#define DOG_HPP

#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
	private:
		std::string name;
		Brain *brain;
		
	public:
		Dog();
		explicit Dog(std::string const &name);
		virtual ~Dog();
		Dog &operator=(Dog const &copy);
		void makeSound() const;
		Dog(Dog const &copy);
};

#endif