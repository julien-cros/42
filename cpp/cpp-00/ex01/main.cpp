#include <iostream>
#include "PhoneBookClass.hpp"

int main(){

	PhoneBook phonebook;

	std::string command = "";
	while (1) {
		std::cout << "Please enter a command: ADD, SEARCH, EXIT" << std::endl << ">";
		std::cin >> command;
		if (std::cin.eof())
			break ;
		if (command == "EXIT")
			break ;
		if (command == "ADD")
			phonebook.add();
		else if (command == "SEARCH")
			phonebook.search();
		else
			std::cout << "Invalid command" << std::endl;
		command.clear();
		std::cin.clear();
	}
	return (0);
}