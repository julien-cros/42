/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliencros <juliencros@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 09:27:36 by juliencros        #+#    #+#             */
/*   Updated: 2024/04/23 11:41:11 by juliencros       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(const std::string &name, int requierdGradeToSign, int requierdGradeToExecute) : name(name), signStatus(false), requierdGradeToSign(requierdGradeToSign), requierdGradeToExecute(requierdGradeToExecute)
{
}

Form::~Form()
{
}

Form &Form::operator=(const Form &rhs)
{
	this->name = rhs.name;
	this->signStatus = false;
	this->requierdGradeToSign = rhs.requierdGradeToSign;
	this->requierdGradeToExecute = rhs.requierdGradeToExecute;
	return (*this);
}

Form::Form(const Form &copy)
{
	*this = copy;
}
const std::string &Form::getName() const
{
	return (this->name);
}

const bool Form::getSignStatus() const
{
	return (this->signStatus);
}

const int Form::getRequierdGradeToSign() const
{
	return(this->requierdGradeToSign);
}


const int Form::getRequierdGradeToExecute() const
{
	return (this->requierdGradeToExecute);
}

const char *Form::GradeTooHighException::what() const throw()
{
	return("Grade too high.");
}

const char *Form::GradeTooLowException::what() const throw()
{
	return("Grade too low.");
}

const char *Form::AlreadySignedException::what() const throw()
{
	return ("The form is alerady signed");
}

void Form::beSigned(const Bureaucrat &Bureaucrat)
{
	if (Bureaucrat.getGrade() > this->getRequierdGradeToSign())
		throw GradeTooLowException();
	else if (this->getSignStatus() == true)
		throw AlreadySignedException();
	else this->signStatus = true;

}

std::ostream &operator<<(std::ostream &o, const Form &form)
{
	return (o << "the form " << form.getName() << " has to be sign by a " << form.getRequierdGradeToSign() << " grade and executed by a " << form.getRequierdGradeToExecute() << " grade. The form is " << (form.getSignStatus() ? "signed" : "not Signed")  << std::endl);
}