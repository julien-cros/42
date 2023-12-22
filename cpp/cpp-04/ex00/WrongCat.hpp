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
		WrongCat(WrongCat const &other);
		WrongCat &operator=(WrongCat const &other);
		explicit WrongCat(std::string const &name);
		virtual ~WrongCat();
		void makeSound() const;
};

#endif