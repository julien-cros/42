#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main(void)
{
	try
	{
		Bureaucrat bureaucrat("Dylan", 10);
		Bureaucrat bureaucrat2("Benoit", 2);

		// ShrubberyCreationForm form("garden");
		// RobotomyRequestForm form("my teacher");
		PresidentialPardonForm form("my friend");

		std::cout << form << std::endl;

		bureaucrat.signForm(form);
		bureaucrat.executeForm(form);
		bureaucrat2.signForm(form);
		bureaucrat2.executeForm(form);

		std::cout << form << std::endl;
	}
	catch (AForm::GradeTooLowException &e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	catch (AForm::GradeTooHighException &e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
}