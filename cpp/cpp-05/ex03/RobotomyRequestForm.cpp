/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliencros <juliencros@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 13:34:14 by juliencros        #+#    #+#             */
/*   Updated: 2024/04/30 14:39:50 by juliencros       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <iostream>

RobotomyRequestForm::RobotomyRequestForm(const std::string &target): target(target), AForm("RobotomyRequestForm", 72, 45)
{
}


RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy): target(copy.getTarget()), AForm(copy.getName(), copy.getRequierdGradeToSign(), copy.getRequierdGradeToExecute())
{
	*this = copy;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &rhs)
{
	this->signStatus = rhs.getSignStatus();
	this->requierdGradeToExecute = rhs.getRequierdGradeToExecute();
	this->requierdGradeToSign = rhs.getRequierdGradeToSign();
	this->name = rhs.getName();
	this->target = getTarget();

	return (*this);
}

const std::string &RobotomyRequestForm::getTarget() const
{
	return (this->target);
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	if (this->signStatus == false)
		throw GradeNotSignedExeption();
	if (executor.getGrade() > this->getRequierdGradeToExecute())
		throw GradeTooLowException();

	int rand;

	if (rand % 2 == 0)
		std::cout << this->target << " has been robotomised" << std::endl;
	else
		std::cout << "The robotomisation did not work in" << this->target << std::endl;
}
