#ifndef WRONGDOG_HPP
#define WRONGDOG_HPP

#include <iostream>
#include "WrongAnimal.hpp"

class WrongDog : public WrongAnimal
{
	private:
		std::string name;
	
	public:
		WrongDog();
		WrongDog(std::string const &name);
		virtual ~WrongDog();
		std::string getName() const;
		void makeSound() const;
};

#endif