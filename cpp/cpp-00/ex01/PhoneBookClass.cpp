#include <iostream>
#include <string>
#include "PhoneBookClass.hpp"
#include "ContactClass.hpp"

PhoneBook::PhoneBook(void) : index(0), length(0), Contacts()
{

	std::cout << "PhoneBook constructor called" << std::endl;
	return;
}

PhoneBook::~PhoneBook(void)
{
	std::cout << "PhoneBook Destructor called called" << std::endl;
	return;
}

void PhoneBook::add(void)
{

	std::string str;
	if (this->index == MAX_CONTACT)
		this->index = 0;
	std::cout << "add called" << std::endl;
	while (str == "")
	{
		std::cout << "Please enter a first name: ";
		getline(std::cin, str);
		Contacts[this->index].Set_first_name(str);
		if (std::cin.eof())
			return;
	}
	str.clear();
	while (str == "")
	{
		std::cout << "Please enter a last name: ";
		getline(std::cin, str);
		Contacts[this->index].Set_last_name(str);
		if (std::cin.eof())
			return;
	}
	str.clear();
	while (str == "")
	{
		std::cout << "Please enter a nickname: ";
		getline(std::cin, str);
		Contacts[this->index].Set_nickname(str);
		if (std::cin.eof())
			return;
	}
	str.clear();
	while (str == "")
	{
		std::cout << "Please enter a phone number: ";
		getline(std::cin, str);
		Contacts[this->index].Set_phone_number(str);
		if (std::cin.eof())
			return;
	}
	str.clear();
	while (str == "")
	{
		std::cout << "Please enter the darkest secret: ";
		getline(std::cin, str);
		Contacts[this->index].Set_darkest_secret(str);
		if (std::cin.eof())
			return;
	}
	str.clear();
	index++;
	if (this->length < MAX_CONTACT)
		this->length++;
	return;
}

void ft_truncate(std::string str)
{
	if (str.length() > 10)
	{
		std::cout << str.substr(0, 9) << ".";
		return;
	}
	else
		std::cout << str;
	std::cout.width(10 - str.length() + 1);
}

void PhoneBook::search(void)
{
	int i = 0;
	if (this->length == 0)
	{
		std::cout << "No contacts to display" << std::endl;
		return;
	}
	while (i < this->length)
	{
		std::cout << "|";
		std::cout << i;
		std::cout.width(9);
		std::cout << "|";
		ft_truncate(Contacts[i].Get_first_name());
		std::cout << "|";
		ft_truncate(Contacts[i].Get_last_name());
		std::cout << "|";
		ft_truncate(Contacts[i].Get_nickname());
		std::cout << "|" << std::endl;
		i++;
	}

	while (1)
	{
		int input;
		std::cout << "Please enter an index: ";
		std::cin >> input;
		if (std::cin.eof())
			return;
		if (std::cin.fail())
		{
			std::cout << "Invalid index search" << std::endl;
			std::cin.clear();
			std::cin.ignore(100000, '\n');
			continue;
		}
		if (input < 0 || input > MAX_CONTACT - 1)
			std::cout << "Invalid index" << std::endl;
		else
		{
			if (input < this->length)
			{
				std::cout << Contacts[input].Get_first_name() << std::endl;
				std::cout << Contacts[input].Get_last_name() << std::endl;
				std::cout << Contacts[input].Get_nickname() << std::endl;
				std::cout << Contacts[input].Get_phone_number() << std::endl;
				std::cout << Contacts[input].Get_darkest_secret() << std::endl;
				return;
			}
			else
				std::cout << "No contacts for the moment at the index" << std::endl;
		}
	}
	return;
}
