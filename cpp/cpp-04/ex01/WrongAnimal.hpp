#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>
class WrongAnimal
{
	protected:
		std::string type;
	
	public:
		WrongAnimal();
		explicit WrongAnimal(std::string const &type);
		virtual ~WrongAnimal();
		std::string getType() const;
		void makeSound() const;
};

#endif