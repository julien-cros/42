#include "ContactClass.hpp"

Contact::Contact( void ) {
}

Contact::~Contact( void ) {

	std::cout << "contact Destructor called called" << std::endl;
	return;
}


std::string Contact::Get_first_name( void ) {
	return this->first_name;
}

std::string Contact::Get_last_name( void ) {
	return this->last_name;
}

std::string Contact::Get_nickname( void ) {
	return this->nickname;
}

std::string Contact::Get_phone_number( void ) {
	return this->phone_number;
}

std::string Contact::Get_darkest_secret( void ) {
	return this->darkest_secret;
}

void Contact::Set_first_name( std::string first_name ) {
	this->first_name = first_name;
}

void Contact::Set_last_name( std::string last_name ) {
	this->last_name = last_name;
}

void Contact::Set_nickname( std::string nickname ) {
	this->nickname = nickname;
}

void Contact::Set_phone_number( std::string phone_number ) {
	this->phone_number = phone_number;
}

void Contact::Set_darkest_secret( std::string darkest_secret ) {
	this->darkest_secret = darkest_secret;
}