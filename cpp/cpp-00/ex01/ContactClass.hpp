#ifndef CONTACTCLASS_HPP
#define CONTACTCLASS_HPP

#include <iostream>
#include <string>

class Contact {

	private:
		std::string first_name;
		std::string last_name;
		std::string nickname;
		std::string phone_number;
		std::string darkest_secret;

	public:

		Contact( void );
		~Contact( void );
		std::string Get_first_name( void );
		std::string Get_last_name( void );
		std::string Get_nickname( void );
		std::string Get_phone_number( void );
		std::string Get_darkest_secret( void );
		void Set_first_name( std::string first_name );
		void Set_last_name( std::string last_name );
		void Set_nickname( std::string nickname );
		void Set_phone_number( std::string phone_number );
		void Set_darkest_secret( std::string darkest_secret );
};

#endif