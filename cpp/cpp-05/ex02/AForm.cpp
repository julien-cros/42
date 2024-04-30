/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliencros <juliencros@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 09:27:36 by juliencros        #+#    #+#             */
/*   Updated: 2024/04/30 14:41:53 by juliencros       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(const std::string &name, int requierdGradeToSign, int requierdGradeToExecute) : name(name), signStatus(false), requierdGradeToSign(requierdGradeToSign), requierdGradeToExecute(requierdGradeToExecute)
{
}

AForm::~AForm()
{
}

AForm &AForm::operator=(const AForm &rhs)
{
	this->name = rhs.name;
	this->signStatus = false;
	this->requierdGradeToSign = rhs.requierdGradeToSign;
	this->requierdGradeToExecute = rhs.requierdGradeToExecute;
	return (*this);
}

AForm::AForm(const AForm &copy)
{
	*this = copy;
}
const std::string &AForm::getName() const
{
	return (this->name);
}

const bool AForm::getSignStatus() const
{
	return (this->signStatus);
}

const int AForm::getRequierdGradeToSign() const
{
	return(this->requierdGradeToSign);
}


const int AForm::getRequierdGradeToExecute() const
{
	return (this->requierdGradeToExecute);
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return("Grade too high.");
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return("Grade too low.");
}

const char *AForm::AlreadySignedException::what() const throw()
{
	return ("The form is alerady signed");
}

const char *AForm::GradeNotSignedExeption::what() const throw()
{
	return ("The form has to be signed before being execute");
}

void AForm::beSigned(const Bureaucrat &Bureaucrat)
{
	if (Bureaucrat.getGrade() > this->getRequierdGradeToSign())
		throw GradeTooLowException();
	else if (this->getSignStatus() == true)
		throw AlreadySignedException();
	else this->signStatus = true;

}

std::ostream &operator<<(std::ostream &o, const AForm &form)
{
	return (o << "The form " << form.getName() << " has to be sign by a " << form.getRequierdGradeToSign() << " grade and executed by a " << form.getRequierdGradeToExecute() << " grade. The form is " << (form.getSignStatus() ? "signed" : "not Signed")  << std::endl);
}