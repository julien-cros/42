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
}

contact::~contact( void ) {

	std::cout << "contact Destructor called called" << std::endl;
	return;
}

void PhoneBook::add( void ) {
	if (this->index == MAX_CONTACT)
		this->index = 0;
	contacts[this->index] = new contact;
	std::cout << "add called" << std::endl;
	while (contacts[this->index]->first_name == "" ) {
		std::cout << "Please enter a first name: ";
		std::getline (std::cin, contacts[this->index]->first_name);
		if (std::cin.eof())
			return ;
	}
	while (contacts[this->index]->last_name == "" ) {
		std::cout << "Please enter a last name: ";
		std::getline (std::cin, contacts[this->index]->last_name);
		if (std::cin.eof())
			return ;
	}
	while (contacts[this->index]->nickname == "" ) {
		std::cout << "Please enter a nickname: ";
		std::getline (std::cin, contacts[this->index]->nickname);
		if (std::cin.eof())
			return ;
	}
	while (contacts[this->index]->phone_number == "" ) {
		std::cout << "Please enter a phone number: ";
		std::getline (std::cin, contacts[this->index]->phone_number);
		if (std::cin.eof())
			return ;
	}
	while (contacts[this->index]->darkest_secret == "" ) {
		std::cout << "Please enter the darkest secret: ";
		std::getline (std::cin, contacts[this->index]->darkest_secret);
		if (std::cin.eof())
			return ;
	}
	index++;
	if (this->length < MAX_CONTACT)
		this->length++;
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
	std::cout.width(10 - str.length() + 1);
}

void PhoneBook::search( void ) {
	int i = 0;
	if (this->length == 0)
	{
		std::cout << "No contacts to display" << std::endl;
			return ;
	}
	while (i < this->length) {
		std::cout << "|";
		std::cout << i;
		std::cout.width(9);
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
		int input;
		std::cout << "Please enter an index: ";
		std::cin >> input;
		if (std::cin.eof())
			return ;
		if (input < 0 || input > MAX_CONTACT - 1)
			std::cout << "Invalid index" << std::endl;
		else
		{
			if (input < this->length)
			{
				std::cout << contacts[input]->first_name << std::endl;
				std::cout << contacts[input]->last_name << std::endl;
				std::cout << contacts[input]->nickname << std::endl;
				std::cout << contacts[input]->phone_number << std::endl;
				std::cout << contacts[input]->darkest_secret << std::endl;
				return ;
			}
			else
				std::cout << "No contacts for the moment at the index" << std::endl;
		}
	}
	return ;
}
