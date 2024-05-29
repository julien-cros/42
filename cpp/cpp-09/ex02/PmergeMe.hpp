#ifndef PERGE_ME_HPP
#define PERGE_ME_HPP

#include <iostream>
#include <vector>
#include <list>

class PmergeMe
{
private:
	PmergeMe();
	~PmergeMe();
	PmergeMe(const PmergeMe &src);

	void operator=(const PmergeMe &rhs);

public:
	static void merge(std::vector<int> &arr);
};

#endif // PERGE_ME_HPP
