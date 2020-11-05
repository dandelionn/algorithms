#include <fstream>
#include <vector>
#include <s_as_sum_of_n_given_numbers.h>

namespace s_as_sum_of_n_given_numbers {
	std::vector<int> extractResult(std::vector<int> T, int sum)
	{
		auto result = std::vector<int>();
		auto i = sum;
		if (T[i] != 0)
		{
			while (i != 0)
			{
				result.push_back(T[i]);
				i -= T[i];
			}
		}
		return result;
	}
}

std::vector<int> findNumbers(std::vector<int> numbers, int sum)
{
	auto m = 0;
	numbers.insert(numbers.begin(), 0);
	auto T = std::vector<int>(sum + 1, 0);
	T[0] = -1;
	for (auto i = 1; i <= numbers.size() && m != sum; i++)
	{
		for (auto j = m; j >= 0; j--)
		{
			if (j + numbers[i] <= sum && T[j] != 0)
			{
				T[j + numbers[i]] = numbers[i];
			}
		}
		if (numbers[i] + m < sum)
			m += numbers[i];
		else
			m = sum;
	}
	return s_as_sum_of_n_given_numbers::extractResult(T, sum);
}