/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcros <jcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 09:27:42 by juliencros        #+#    #+#             */
/*   Updated: 2024/05/03 15:54:21 by jcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;
class AForm
{
	protected:
		std::string name;
		bool signStatus;
		int requierdGradeToSign;
		int requierdGradeToExecute;

public:
	AForm(const std::string &name, int requierdGradeToSign, int requierdGradeToExecute);
	AForm(const AForm &copy);
	~AForm();

	AForm &operator=(const AForm &rhs);

	const std::string &getName() const;
	const bool getSignStatus() const;
	const int getRequierdGradeToSign() const;
	const int getRequierdGradeToExecute() const;
	void beSigned(const Bureaucrat & Bureaucrat);

	virtual void execute(Bureaucrat const & executor) const = 0;

	class GradeTooLowException : public std::exception
	{
	public:
		const char *what() const throw();
	};

	class GradeTooHighException : public std::exception
	{
	public:
		const char *what() const throw();
	};
	class AlreadySignedException : public std::exception
	{
		public:
			const char *what() const throw();
	};
	class FormNotSignedExeption : public std::exception
	{
		public:
			const char *what() const throw();
	};
};

std::ostream &operator<<(std::ostream &o, const AForm &aform);

#endif