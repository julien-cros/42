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
		WrongDog(WrongDog const &copy);
		WrongDog &operator=(WrongDog const &copy);
		explicit WrongDog(std::string const &name);
		virtual ~WrongDog();
		void makeSound() const;
};

#endif