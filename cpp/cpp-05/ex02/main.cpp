#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main(void)
{
	try
	{
		Bureaucrat bureaucrat("Dylan", 1);
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
	catch (Bureaucrat::GradeTooLowException &e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	catch (AForm::GradeTooLowException &e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	catch (AForm::GradeTooHighException &e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	catch (AForm::AlreadySignedException &e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	catch (AForm::FormNotSignedExeption &e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
}