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
		WrongCat(WrongCat const &copy);
		WrongCat &operator=(WrongCat const &copy);
		explicit WrongCat(std::string const &name);
		virtual ~WrongCat();
		void makeSound() const;
};

#endif