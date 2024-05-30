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

	PmergeMe &operator=(const PmergeMe &rhs);
	static void insertElement(std::vector<int> &vec, int value, int end);
	static void insertElement(std::list<int> &lst, int value, int end);
	static int binarySearch(const std::vector<int> &vec, int value, int end);
	static int binarySearch(const std::list<int> &lst, int value, int end);

public:
	static void merge(std::vector<int> &arr);
	static void merge(std::list<int> &arr);
};

#endif // PERGE_ME_HPP
