#include <iostream>
#include <string>
#include "PhoneBookClass.hpp"

PhoneBook::PhoneBook( void ) {

	std::cout << "PhoneBook constructor called" << std::endl;
	return ;
}

PhoneBook::~PhoneBook( void ) {

	std::cout << "PhoneBook Destructor called called" << std::endl;
	return;
}

contact::contact( void ) {

	std::cout << "contact constructor called" << std::endl;
	return ;
}

contact::~contact( void ) {

	std::cout << "contact Destructor called called" << std::endl;
	return;
}

void PhoneBook::add( void ) {
	if (index == 8)
		index = 0;
	contacts[index] = new contact;
	std::cout << "add called" << std::endl;
	while (contacts[index]->first_name == "" ) {
		std::cout << "Please enter a first name: ";
		std::getline (std::cin, contacts[index]->first_name);
	}
	while (contacts[index]->last_name == "" ) {
		std::cout << "Please enter a last name: ";
		std::getline (std::cin, contacts[index]->last_name);
	}
	while (contacts[index]->nickname == "" ) {
		std::cout << "Please enter a nickname: ";
		std::getline (std::cin, contacts[index]->nickname);
	}
	while (contacts[index]->phone_number == "" ) {
		std::cout << "Please enter a phone number: ";
		std::getline (std::cin, contacts[index]->phone_number);
	}
	while (contacts[index]->darkest_secret == "" ) {
		std::cout << "Please enter the darkest secret: ";
		std::getline (std::cin, contacts[index]->darkest_secret);
	}
	index++;
	return ;
}

void ft_truncate(std::string str) {
	if (str.length() > 10)
	{
		std::cout << str.substr(0, 9) << ".";
		return ;
	}
	else
		std::cout << str;
	std::cout.width(10 - str.length());
}

void PhoneBook::search( void ) {
	int i = 0;
	while (contacts[i]) {
		std::cout << "|";
		std::cout.width(5);
		std::cout << i;
		std::cout.width(5);

		std::cout << "|";
		ft_truncate(contacts[i]->first_name);
		std::cout << "|";
		ft_truncate(contacts[i]->last_name);
		std::cout << "|";
		ft_truncate(contacts[i]->nickname);
		std::cout << "|" << std::endl;

		i++;
	}
	
	while (1) {
		if (index == 0)
		{
			std::cout << "No contacts to search" << std::endl;
			return ;
		}
		std::cout << "Please enter an index: ";
		std::cin >> index;
		if (index < 0 || index > 7)
			std::cout << "Invalid index" << std::endl;
		else
		{
			if (contacts[index]->first_name.length() )
			{
				std::cout << contacts[index]->first_name << std::endl;
				std::cout << contacts[index]->last_name << std::endl;
				std::cout << contacts[index]->nickname << std::endl;
				std::cout << contacts[index]->phone_number << std::endl;
				std::cout << contacts[index]->darkest_secret << std::endl;
				return ;
			}
				std::cout << "No contacts for the moment at the index" << std::endl;
				continue ;
		}
	}
	return ;
}

void PhoneBook::exit( void ) {

	std::cout << "exit" << std::endl;
	exit();
	return ;
}