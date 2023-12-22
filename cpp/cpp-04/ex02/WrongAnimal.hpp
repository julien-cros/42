#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>
class WrongAnimal
{
	protected:
		std::string type;
	
	public:
		WrongAnimal();
		WrongAnimal(WrongAnimal const &copy);
		WrongAnimal &operator=(WrongAnimal const &copy);
		explicit WrongAnimal(std::string const &type);
		virtual ~WrongAnimal();
		std::string getType() const;
		virtual void makeSound() const;
};

#endif