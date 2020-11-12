#include <iostream>
#include <fstream>
#include <vector>

std::vector<std::vector<int>> createSparseTable(std::vector<int> input)
{
	std::vector<std::vector<int>> table;
	table.push_back(input);

	for (auto i = 1; i < input.size(); i <<= 1)
	{
		auto prev = table.back();
		auto v = std::vector<int>();
		for (auto it = prev.begin(); it + i < prev.end(); ++it)
		{
			v.push_back(std::min(*it, *(it + i)));
		}
		table.push_back(v);
	}

	return table;
}

std::vector<int> createLg(int n)
{
	std::vector<int> lg;
	lg.push_back(0);
	lg.push_back(0);
	for (auto i = 2; i <= n; ++i)
	{
		lg.push_back(lg[i / 2] + 1);
	}

	return lg;
}

int getMin(const std::vector<std::vector<int>>& table, const std::vector<int>& lg, int x, int y)
{
	auto power = lg[y - x + 1];
	int min = std::min(table[power][x], table[power][y - (1 << power) + 1]);

	return min;
}

int main()
{
	std::ifstream fin("rmq.in");
	std::ofstream fout("rmq.out");
	auto n = 0, m = 0, x = 0, y = 0;
	fin >> n >> m;

	std::vector<int> v;
	for (auto i = 0; i < n; ++i)
	{
		fin >> x;
		v.push_back(x);
	}

	auto table = createSparseTable(v);
	auto lg = createLg(n);
	for (auto i = 0; i < m; ++i)
	{
		fin >> x >> y;
		fout << getMin(table, lg, x - 1, y - 1) << '\n';
	}

	return 0;
}