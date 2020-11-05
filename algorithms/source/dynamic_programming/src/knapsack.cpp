#include <knapsack.h>
#include <vector>
#include <iostream>

//  The knapsack problem: given a set of items, each with a weight and a value, 
//  determine the number of each item to include in a collection  so that the total weight
//	is less than or equal to a given limit and the total value is as large as possible

int solveKnapsackProblem(std::vector<object> objects, int maxWeight)
{
	auto p = std::vector<std::vector<int>>(20, std::vector<int>(20, 0));
	auto C = std::vector<std::vector<int>>(20, std::vector<int>(20, 0));
	objects.insert(objects.begin(), object(0,0));
	for (int i = 1; i < objects.size(); i++)
	{
		for (int j = 1; j <= maxWeight; j++)
		{
			if ((objects[i].weight <= j) && (objects[i].count + C[i - 1][j - objects[i].weight] > C[i - 1][j]))
			{
				C[i][j] = objects[i].count + C[i - 1][j - objects[i].weight];
				p[i][j] = i;
			}
			else
			{
				C[i][j] = C[i - 1][j];
				p[i][j] = p[i - 1][j];
			}
		}
	}
	return C[objects.size() - 1][maxWeight];
}

void print(std::vector<object> objects, int maxWeight, int p[20][20], int C[20][20])
{
	int i = objects.size() - 1, j = maxWeight, k;
    std::cout << "Total profit: " << C[i][j] << '\n';
	while (p[i][j] != 0)
	{
		k = p[i][j];
		std::cout << "object: " << k << " weight: " << objects[k].weight << " profit: " << objects[k].count << '\n';
		j -= objects[p[i][j]].weight;
		while (p[i][j] == k)
		{
			i--;
		}
	}
}