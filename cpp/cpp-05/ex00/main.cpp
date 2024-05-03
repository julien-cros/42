
#include "Bureaucrat.hpp"
#include <iostream>

int main(void)
{
	try
	{
		Bureaucrat bureaucrat("ok", 150);

		std::cout << bureaucrat << std::endl;
		

		bureaucrat.decrementGrade();
		std::cout << bureaucrat << std::endl;
		bureaucrat.incrementGrade();
		std::cout << bureaucrat << std::endl;
		bureaucrat.incrementGrade();
		
		std::cout << "getName(): " << bureaucrat.getName() << std::endl;
		std::cout << "getGrade(): " << bureaucrat.getGrade() << std::endl;

		bureaucrat.incrementGrade();
		bureaucrat.incrementGrade();

	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
}