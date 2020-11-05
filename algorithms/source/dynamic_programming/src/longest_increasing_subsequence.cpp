#include <vector>
#include <longest_increasing_subsequence.h>

int searchSolution(std::vector<int> L, int n)
{
	int solutionIndex, max = -1;
	for (auto i = 1; i <= n; ++i)
	{
		if (max < L[i])
		{
			max = L[i];
			solutionIndex = i;
		}
	}
	return solutionIndex;
}

std::vector<int> extractSolution(std::vector<int> values, std::vector<int> L, std::vector<int> p, int solutionIndex)
{
	//L[k] solution length;
	auto result = std::vector<int>();
	auto i = 1;
	auto j = solutionIndex;
	for (; i <= L[solutionIndex]; ++i, j = p[j])
	{
		result.push_back(values[j]);
	}
	return result;
}

std::vector<int> findLongestIncreasingSequence(std::vector<int> values)
{
	values.insert(values.begin(), 0);
	auto n = values.size() - 1;
	auto L = std::vector<int>(n+1, 0);
	auto p = std::vector<int>(n+1, 0);
	L[n] = 1;
	p[n] = n;
	for (auto i = n - 1; i >= 1; --i)
	{
		L[i] = 1; p[i] = i;
		for (auto j = i + 1; j <= n; ++j)
		{
			if (values[i] <= values[j] && L[i] <= L[j])
			{
				L[i] = L[j] + 1; 
				p[i] = j;
			}
		}
	}
	auto solutionIndex = searchSolution(L, n);
	return extractSolution(values, L, p, solutionIndex);
}
