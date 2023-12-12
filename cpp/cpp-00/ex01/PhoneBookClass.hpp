#ifndef PHONEBOOKCLASS_HPP
#define PHONEBOOKCLASS_HPP

#include <iostream>
#include <string>

#define MAX_CONTACT 8

class contact {

	public:

		contact( void );
		~contact( void );
		std::string first_name;
		std::string last_name;
		std::string nickname;
		std::string phone_number;
		std::string darkest_secret;
};

class PhoneBook {

	public:

		PhoneBook( void );
		~PhoneBook( void );
		void add( void );
		void search( void );
		contact *contacts[MAX_CONTACT];
		int index;
		int length;
};

#endif
