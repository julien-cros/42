/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliencros <juliencros@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 13:30:55 by juliencros        #+#    #+#             */
/*   Updated: 2024/04/30 14:40:16 by juliencros       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDINFORM_HPP
#define PRESIDENTIALPARDINFORM_HPP

#include <iostream>
#include "AForm.hpp"


class PresidentialPardonForm : public AForm
{
	private:
		std::string target;
	
	 public:
	 	PresidentialPardonForm(const std:: string &target);
		~PresidentialPardonForm();
		PresidentialPardonForm(const PresidentialPardonForm &copy);

		PresidentialPardonForm &operator=(const PresidentialPardonForm &rhs);
		const std::string &getTarget() const;
		
		void execute(Bureaucrat const & executor) const;

};


#endif