#pragma once
#include <vector>

struct object {
	int weight;
	int count;
	object(int weight, int count) : weight(weight), count(count) {}
};

int solveKnapsackProblem(std::vector<object> objects, int maxWeight);