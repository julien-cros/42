#include <iostream>
#include "Sed.hpp"

int main(int argc, char **argv) {
	if (argc != 4) {
		std::cout << "Usage: ./sed <filename> <string to replace> <string to replace with>" << std::endl;
		return 1;
	}
	Sed sed(argv[1]);
	sed.replace(argv[2], argv[3]);

	return 0;
}