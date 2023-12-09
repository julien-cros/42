#ifndef PHONEBOOKCLASS_HPP
#define PHONEBOOKCLASS_HPP

#include <iostream>
#include <string>

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
		void exit( void );
		contact *contacts[8];
		int index;
};

#endif
