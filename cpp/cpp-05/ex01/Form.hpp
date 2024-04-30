/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliencros <juliencros@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 09:27:42 by juliencros        #+#    #+#             */
/*   Updated: 2024/04/23 11:40:46 by juliencros       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;
class Form
{
private:
	std::string name;
	bool signStatus;
	int requierdGradeToSign;
	int requierdGradeToExecute;

public:
	Form(const std::string &name, int requierdGradeToSign, int requierdGradeToExecute);
	Form(const Form &copy);
	~Form();

	Form &operator=(const Form &rhs);

	const std::string &getName() const;
	const bool getSignStatus() const;
	const int getRequierdGradeToSign() const;
	const int getRequierdGradeToExecute() const;
	void beSigned(const Bureaucrat & Bureaucrat);

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
};

std::ostream &operator<<(std::ostream &o, const Form &form);

#endif