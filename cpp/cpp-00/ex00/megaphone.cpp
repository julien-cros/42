#include <iostream>

char toupper(char c){
	if ( c < 97 || c > 122)
		return(c);
	return (c - 32 );
}

int main (int argc, char **argv){
	(void)argv;
	if (argc == 1)
		return (std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *"<< std::endl, 1);
	if (argc != 2)
		return (std::cout << "Too many arguments!" << std::endl, 1);
	for (int i = 0; argv[1][i]; i++)
		std::cout << toupper(argv[1][i]);
	std::cout << std::endl;
	return 0;
}
