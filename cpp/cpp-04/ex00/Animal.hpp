#ifndef ANIMAL_HPP
#define ANIMAL_HPP

# include <iostream>
class Animal
{
	protected:
		std::string type;
	
	public:
		Animal();
		explicit Animal(std::string const &type);
		Animal(Animal const &other);
		Animal &operator=(Animal const &other);
		virtual ~Animal();
		std::string getType() const;
		virtual void makeSound() const;
};

#endif