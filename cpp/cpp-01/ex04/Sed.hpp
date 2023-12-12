#include <iostream>

#ifndef SED_HPP
#define SED_HPP

class Sed {
	public:
		Sed(std::string in_file);
		~Sed();
		void replace(std::string pattern, std::string replace);

	private:
		std::string in_file;
		std::string out_file;

};

#endif