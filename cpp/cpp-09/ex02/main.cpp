#include <iostream>
#include <ctime>
#include <random>
#include "PmergeMe.hpp"

int main(int argc, char *argv[])
{
	if (argc < 2)
	{
		std::cerr << "Usage: " << argv[0] << " <array of positive ints>" << std::endl;
		return 1;
	}

	std::vector<int> vector;
	std::list<int> list;

	for (int i = 1; i < argc; i++)
	{
		int n = std::atoi(argv[i]);

		if (n < 0)
		{
			std::cerr << "Error: " << n << " is not a positive integer" << std::endl;
			return 1;
		};
		vector.push_back(n);
		list.push_back(n);
	}

	std::cout << "before: ";
	for (size_t i = 0; i < vector.size(); i++)
	{
		std::cout << vector[i];
		if (i < vector.size() - 1)
			std::cout << " ";
		else
			std::cout << std::endl;
	}
	unsigned long start = clock();
	PmergeMe::merge(vector);
	unsigned long end = (clock() - start) / (double)CLOCKS_PER_SEC * 1000000;

	std::cout << "after: ";
	for (size_t i = 0; i < vector.size(); i++)
	{
		std::cout << vector[i];
		if (i < vector.size() - 1)
			std::cout << " ";
		else
			std::cout << std::endl;
	}
	std::cout << "Time to process a range of " << vector.size() << " elements with std::vector: " << end << "us" << std::endl;

	start = clock();
	PmergeMe::merge(list);
	end = (clock() - start) / (double)CLOCKS_PER_SEC * 1000000;

	std::cout << "Time to process a range of " << list.size() << " elements with std::list: " << end << "us" << std::endl;
}