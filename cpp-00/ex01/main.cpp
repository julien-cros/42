#include <iostream>
#include "PhoneBookClass.hpp"

void ft_print_contacts(PhoneBook phonebook) {

	for (int i = 0; i < phonebook.index; i++) {
		std::cout << phonebook.contacts[i]->first_name << std::endl;
		std::cout << phonebook.contacts[i]->last_name << std::endl;
		std::cout << phonebook.contacts[i]->nickname << std::endl;
		std::cout << phonebook.contacts[i]->phone_number << std::endl;
		std::cout << phonebook.contacts[i]->darkest_secret << std::endl;
	}
}

int main(){

	PhoneBook phonebook;
	phonebook.index = 0;

	std::string command = "";
	while (command != "EXIT") {
		std::cout << "Please enter a command: ADD, SEARCH, EXIT" << std::endl << ">";
		std::cin >> command;
		if (command == "ADD")
			phonebook.add();
		else if (command == "SEARCH")
			phonebook.search();
		else if (command == "EXIT")
			phonebook.exit();
		else
			std::cout << "Invalid command" << std::endl;
		ft_print_contacts(phonebook);
		command = "";
	}
	return (0);
}