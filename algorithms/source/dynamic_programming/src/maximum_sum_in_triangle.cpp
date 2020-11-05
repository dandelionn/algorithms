#include <vector>
#include <iostream>
#include <maximum_sum_in_triangle.h>

int computeMaximumSum(std::vector<std::vector<int>> triangle)
{
	triangle.insert(triangle.begin(), std::vector<int>(triangle.size(), 0));
	for (auto& line : triangle)
	{
		line.insert(line.begin(), 0);
	}
	auto S = std::vector<std::vector<int>>(triangle.size(), std::vector<int>(triangle.size(), 0));
	auto p = std::vector<std::vector<int>>(triangle.size(), std::vector<int>(triangle.size(), 0));
	auto n = triangle.size() - 1;

	for (auto i = 1; i <= n; ++i)
	{
		S[n][i] = triangle[n][i];
	}

	for (auto i = n - 1; i >= 1; --i)
	{
		for (auto j = 1; j <= i; ++j)
		{
			if (S[i + 1][j] > S[i + 1][j + 1])
			{
				S[i][j] = S[i + 1][j] + triangle[i][j];
				p[i][j] = 1;
			}
			else
			{
				S[i][j] = S[i + 1][j + 1] + triangle[i][j];
				p[i][j] = 2;
			}
		}
	}
	return S[1][1];
}

void printPath(std::vector<std::vector<int>> triangle, std::vector<std::vector<int>> S, std::vector<std::vector<int>> p)
{
	std::cout << "Maximum sum " << S[1][1] << "= " << triangle[1][1] << "+";
	auto i = 1;
	auto j = 1;
	auto q = 1;
	auto r = 1;
	for (;i < triangle.size(); ++i)
	{
		if (p[i][j] == 2)
		{
			r = r + 1;
			j++;
		}
		q = q + 1;
		std::cout << triangle[q][r] << "+";
	}
    std::cout<<'\b';
}