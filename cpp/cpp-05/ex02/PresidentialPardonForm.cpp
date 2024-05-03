/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcros <jcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 13:34:46 by juliencros        #+#    #+#             */
/*   Updated: 2024/05/03 15:54:21 by jcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"


PresidentialPardonForm::PresidentialPardonForm(const std::string &target): target(target), AForm("PresidentialPardonForm", 25, 5)
{
}
PresidentialPardonForm::~PresidentialPardonForm()
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy): target(copy.getTarget()), AForm(copy.getName(), copy.getRequierdGradeToSign(), copy.getRequierdGradeToExecute())
{
	*this = copy;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &rhs)
{
	this->signStatus = rhs.getSignStatus();
	this->name = rhs.getName();
	this->target = rhs.getTarget();
	this->requierdGradeToSign = rhs.getRequierdGradeToSign();
	this->requierdGradeToExecute = rhs.getRequierdGradeToExecute();

	return (*this);
}

const std::string &PresidentialPardonForm::getTarget() const
{
	return(this->target);	
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	if (this->signStatus == false)
		throw FormNotSignedExeption();
	if (executor.getGrade() > this->getRequierdGradeToExecute())
		throw GradeTooLowException();

	std::cout << this->target << " has been pardoned by Zafod Beeblebrox" << std::endl;
}
