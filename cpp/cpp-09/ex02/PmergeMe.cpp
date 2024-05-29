/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliencros <juliencros@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 12:42:51 by juliencros        #+#    #+#             */
/*   Updated: 2024/05/28 15:12:25 by juliencros       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <list>

PmergeMe::PmergeMe() {}

PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &src) { (void)src; }

void PmergeMe::operator=(const PmergeMe &rhs) { (void)rhs; }

int binarySearch(const std::vector<int> &vec, int value, int end)
{
	int start = 0;
	while (start < end)
	{
		int mid = start + (end - start) / 2;
		if (vec[mid] < value)
		{
			start = mid + 1;
		}
		else
		{
			end = mid;
		}
	}
	return start;
}

// Function to insert an element into a sorted vector
void insertElement(std::vector<int> &vec, int value, int end)
{
	int pos = binarySearch(vec, value, end);
	vec.insert(vec.begin() + pos, value);
}

void PmergeMe::merge(std::vector<int> &arr)
{
	int n = arr.size();

	if (n <= 1)
		return;

	std::vector<int> larger((n + 1) / 2);
	std::vector<int> smaller((n + 1) / 2, 0);

	for (int i = 0; i < n / 2; ++i)
	{
		if (arr[2 * i] > arr[2 * i + 1])
		{
			larger[i] = arr[2 * i];
			smaller[i] = arr[2 * i + 1];
		}
		else
		{
			larger[i] = arr[2 * i + 1];
			smaller[i] = arr[2 * i];
		}
	}
	if (n % 2 == 1)
		larger[n / 2] = arr[n - 1];

	merge(larger);

	std::vector<int> s;

	s.push_back(smaller[0]);

	for (int i = 0; i < larger.size(); ++i)
		insertElement(s, larger[i], s.size());

	std::vector<int> remainingSmallerElements(smaller.begin() + 1, smaller.end());

	static std::uint64_t jacobsthal_nums[63] = {
			2u, 2u, 6u, 10u, 22u, 42u, 86u, 170u, 342u, 682u, 1366u,
			2730u, 5462u, 10922u, 21846u, 43690u, 87382u, 174762u, 349526u, 699050u,
			1398102u, 2796202u, 5592406u, 11184810u, 22369622u, 44739242u, 89478486u,
			178956970u, 357913942u, 715827882u, 1431655766u, 2863311530u, 5726623062u,
			11453246122u, 22906492246u, 45812984490u, 91625968982u, 183251937962u,
			366503875926u, 733007751850u, 1466015503702u, 2932031007402u, 5864062014806u,
			11728124029610u, 23456248059222u, 46912496118442u, 93824992236886u, 187649984473770u,
			375299968947542u, 750599937895082u, 1501199875790165u, 3002399751580331u,
			6004799503160661u, 12009599006321322u, 24019198012642644u, 48038396025285288u,
			96076792050570576u, 192153584101141152u, 384307168202282304u, 768614336404564608u,
			1537228672809129216u, 3074457345618258432u, 6148914691236516864u};

	int idx = 0, smallIndex = 1;
	while (smallIndex < remainingSmallerElements.size() && idx < sizeof(jacobsthal_nums) / sizeof(jacobsthal_nums[0]))
	{
		for (int j = 0; j < jacobsthal_nums[idx] && smallIndex < remainingSmallerElements.size(); ++j)
		{
			insertElement(s, remainingSmallerElements[smallIndex], s.size());
			++smallIndex;
		}
		++idx;
	}

	// Move sorted elements back to the original array
	for (int i = 0; i < s.size(); ++i)
		arr[i] = s[i];
}
