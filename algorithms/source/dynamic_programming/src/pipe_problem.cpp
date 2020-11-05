#include <iostream>
#include <fstream>
#include <vector>
#include <pipe_problem.h>

int canPipeBeBuiltWithThePieces(std::vector<int> T, int pipeLength)
{
	return T[pipeLength] != 0;
}

std::vector<int> extractResult(std::vector<int> T, int pipeLength)
{
	auto result = std::vector<int>(); //if it remains empty the pipe can't be built
	if (canPipeBeBuiltWithThePieces(T, pipeLength))
	{
		for (int i = pipeLength; i != 0;)
		{
			//piece of T[i] metters;
			result.push_back(T[i]);
			i -= T[i];
		}
	}

	return result;
}

std::vector<int> buildPipe(std::vector<int> pieces, int pipeLength)
{
	pieces.insert(pieces.begin(), 0);
	auto T = std::vector<int>(pipeLength + 1, 0);
	T[0] = -1;
	auto m = 0;
	auto n = pieces.size() - 1;
	for (auto i = 1; i <= n; i++)
	{
		for (auto j = m; j >= 0; j--)
		{
			if (j + pieces[i] <= pipeLength && T[j] != 0 && pieces[i] != 0)
			{
				T[j + pieces[i]] = pieces[i];
			}
		}
		if (pieces[i] + m < pipeLength)
		{
			m += pieces[i];
		}
		else
		{
			m = pipeLength;
		}
	}
	return extractResult(T, pipeLength);
}