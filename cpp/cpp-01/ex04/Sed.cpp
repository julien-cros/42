#include <iostream>
#include <fstream>
#include "Sed.hpp"

Sed::Sed(std::string in_file) : in_file(in_file), out_file(in_file + ".replace")
{
}

Sed::~Sed()
{
}

void Sed::replace(std::string pattern, std::string replace) {
	std::ifstream ifs(this->in_file);
	std::ofstream ofs(this->out_file);
	std::string line;

	if (ifs.fail()) {
		std::cout << "Error opening infile" << std::endl;
		ofs.close();
		return;
	}
	if (ofs.fail()) {
		std::cout << "Error opening outfile" << std::endl;
		ifs.close();
		return;
	}
	while (std::getline(ifs, line)) {
		size_t pos = line.find(pattern);
		while (pos != std::string::npos) {
			line.erase(pos, pattern.length());
			line.insert(pos, replace);
			pos = line.find(pattern, pos + replace.length());
		}
		ofs << line << std::endl;
	}
	ifs.close();
	ofs.close();
}