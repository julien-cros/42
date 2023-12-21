#ifndef PHONEBOOKCLASS_HPP
#define PHONEBOOKCLASS_HPP

#include <iostream>
#include <string>
#include "ContactClass.hpp"

#define MAX_CONTACT 2


class PhoneBook {

	public:

		PhoneBook( void );
		~PhoneBook( void );
		void add( void );
		void search( void );
		Contact Contacts[MAX_CONTACT];
		int index;
		int length;

};

#endif
