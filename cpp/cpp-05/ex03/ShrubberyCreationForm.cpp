/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliencros <juliencros@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 13:33:28 by juliencros        #+#    #+#             */
/*   Updated: 2024/04/30 14:37:51 by juliencros       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : target(target), AForm::AForm("ShrubberyCreationForm", 145, 137)
{
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{	
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy): target(copy.getTarget()), AForm(copy.getName(), copy.getRequierdGradeToSign(), copy.getRequierdGradeToExecute())
{
	*this = copy;
}


ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &rhs)
{
		this->name = rhs.getName();
		this->signStatus = rhs.getSignStatus();
		this->requierdGradeToSign = rhs.getRequierdGradeToSign();
		this->requierdGradeToExecute = rhs.getRequierdGradeToExecute();
		this->target = rhs.getTarget();
		return (*this);
}

const std::string &ShrubberyCreationForm::getTarget() const
{
		return (this->target);
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	if (this->signStatus == false)
		throw GradeNotSignedExeption();
	if (executor.getGrade() > this->getRequierdGradeToExecute())
		throw GradeTooLowException();

		std::ofstream file(this->target + "_shrubbery");

	file << "            .        +          .      .          ." << std::endl;
	file << "     .            _        .                    ." << std::endl;
	file << "  ,              /;-._,-.____        ,-----.__" << std::endl;
	file << " ((        .    (_:#::_.:::. `-._   /:, /-._, `._," << std::endl;
	file << "  `                 \\   _|`\"=:_::.`.);  \\ __/ /" << std::endl;
	file << "                      ,    `./  \\:. `.   )==-'  ." << std::endl;
	file << "    .      ., ,-=-.  ,\\, +#./`   \\:.  / /           ." << std::endl;
	file << ".           \\/:/`-' , ,\\ '` ` `   ): , /_  -o" << std::endl;
	file << "       .    /:+- - + +- : :- + + -:'  /(o-) \\)     ." << std::endl;
	file << "  .      ,=':  \\    ` `/` ' , , ,:' `'--\".--\"---._/`7" << std::endl;
	file << "   `.   (    \\: \\,-._` ` + '\\, ,\"   _,--._,---\":.__/" << std::endl;
	file << "              \\:  `  X` _| _,\\/'   .-'" << std::endl;
	file << ".               \":._:`\\____  /:'  /      .           ." << std::endl;
	file << "                    \\::.  :\\/:'  /              +" << std::endl;
	file << "   .                 `.:.  /:'  }      ." << std::endl;
	file << "           .           ):_(:;   \\           ." << std::endl;
	file << "                      /:. _/ ,  |" << std::endl;
	file << "                   . (|::.     ,`                  ." << std::endl;
	file << "	   .                |::.    {\\" << std::endl;
	file << "                      |::.\\  \\ `." << std::endl;
	file << "                      |:::(\\    |" << std::endl;
	file << "              O       |:::/{ }  |                  (o" << std::endl;
	file << "               )  ___/#\\::`/ (O \"==._____   O, (O  /`" << std::endl;
	file << "          ~~~w/w~\"~~,\\` `:/,-(~`\"~~~~~~~~\"~o~\\~/~w|/~" << std::endl;
	file << "    ~~~~~~~~~~~~~~~~~~~~~~~\\W~~~~~~~~~~~~\\|/~~" << std::endl;

	file.close();
}
