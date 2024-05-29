#include <iostream>
#include "PmergeMe.hpp"

int main(int argc, char *argv[])
{
	if (argc < 2)
	{
		std::cerr << "Usage: " << argv[0] << " <array of positive ints>" << std::endl;
		return 1;
	}

	std::vector<int> data;

	for (int i = 1; i < argc; i++)
	{
		int n = std::atoi(argv[i]);

		if (n < 0)
		{
			std::cerr << "Error: " << n << " is not a positive integer" << std::endl;
			return 1;
		}
		data.push_back(n);
	}

	PmergeMe::merge(data);

	for (size_t i = 0; i < data.size(); i++)
	{
		std::cout << data[i];
		if (i < data.size() - 1)
			std::cout << " ";
		else
			std::cout << std::endl;
	}
}