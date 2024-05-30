#include "RPN.hpp"

int main(int argc, char *argv[])
{

	try
	{
		if (argc < 2)
		{
			std::cerr << "Usage: " << argv[0] << " <expression>" << std::endl;
			return 1;
		}
		else if (strlen(argv[1]) < 5)
		{
			std::cerr << "Usage:" << argv[0] << " \"int  int operator(+ - * /)\"" << std::endl;
			return 1;
		}

		RPN rpn;
		double res = rpn.run(argv[1]);

		std::cout << res << std::endl;

		return 0;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		return 1;
	}
}