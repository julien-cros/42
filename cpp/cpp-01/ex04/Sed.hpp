#include <iostream>

#ifndef SED_HPP
#define SED_HPP

class Sed {
	public:
		explicit Sed(std::string const &in_file);
		~Sed();
		void replace(std::string const &pattern, std::string const &replace);

	private:
		std::string in_file;
		std::string out_file;

};

#endif