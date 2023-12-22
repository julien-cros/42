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
		WrongDog(WrongDog const &other);
		WrongDog &operator=(WrongDog const &other);
		explicit WrongDog(std::string const &name);
		virtual ~WrongDog();
		void makeSound() const;
};

#endif