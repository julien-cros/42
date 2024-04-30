#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern()
{
}

Intern::~Intern()
{
}

Intern::Intern(const Intern &copy)
{
	*this = copy;
}

Intern &Intern::operator=(const Intern &rhs)
{
	*this = rhs;
	return (*this);
}

AForm *Intern::makeForm(const std::string &name, const std::string &target) const
{
	const std::string SupportedForms[3] = {
			"presidential pardon",
			"robotomy request",
			"shrubbery creation"};

	AForm *Forms[3] = {
			new PresidentialPardonForm(target),
			new RobotomyRequestForm(target),
			new ShrubberyCreationForm(target)};

	for (int i = 0; i < 3; i++)
	{
		if (name == SupportedForms[i])
		{
			std::cout << "Intern Created " << name << std::endl;
			return (Forms[i]);
		}
	}
	std::cout << "The " << name << "form does not exist." << std::endl;
	return NULL;
}
