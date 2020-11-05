#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <maximum_subset_sum.h>

std::vector<int> findMaximalSumSubset(std::vector<int> values)
{
	std::sort(values.begin(), values.end());
	auto result = std::vector<int>();
	auto it = values.begin();
	while (*it > 0 && it != values.end())
	{
		result.push_back(*it);
		++it;
	}
	if (result.empty() && !values.empty())
	{
		result.push_back(values.back());
	}
	return result;
}