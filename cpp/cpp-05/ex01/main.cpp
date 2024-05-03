
#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main(void)
{
	try
	{
		Bureaucrat bureaucrat("ok", 3);
		std::cout << bureaucrat << std::endl;
		

		Form form("julen's contract", 2, 1);
		std::cout << form << std::endl;


		bureaucrat.decrementGrade();
		std::cout << bureaucrat << std::endl;

		bureaucrat.signForm(form);

		bureaucrat.incrementGrade();
		std::cout << bureaucrat << std::endl;
		bureaucrat.incrementGrade();

		bureaucrat.signForm(form);
		bureaucrat.signForm(form);
		
		std::cout << std::endl << "getters" << std::endl;
		std::cout << "getName: " << bureaucrat.getName() << std::endl;
		std::cout << "getGrade: " << bureaucrat.getGrade() << std::endl;

		std::cout << "getName:" << form.getName() << std::endl;
		std::cout << "getSignStatus: " << form.getSignStatus() << std::endl;
		std::cout << "getRequierdGradeToSign:" << form.getRequierdGradeToSign() << std::endl;
		std::cout << "getRequierdGradeToExecute:" << form.getRequierdGradeToExecute() << std::endl;

		// bureaucrat.incrementGrade();
		// bureaucrat.incrementGrade();



	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	catch (Form::AlreadySignedException &e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	catch (Form::GradeTooHighException &e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	catch (Form::GradeTooLowException &e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
}