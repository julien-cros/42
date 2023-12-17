#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>

class Brain
{
	private:
		std::string ideas[100];
	
	public:
		Brain();
		Brain(Brain const &copy);
		Brain &operator=(Brain const &copy);
		virtual ~Brain();
		std::string getIdea(int index) const;
		void setIdea(int index, std::string const &idea);
};

#endif