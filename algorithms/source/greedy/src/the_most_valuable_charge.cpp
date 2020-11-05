#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <the_most_valuable_charge.h>

std::vector<Object> createObjects(std::vector<float> objectWeights, std::vector<int> objectCounts)
{
	std::vector<Object> objects;
	for (auto i = 0; i < objectWeights.size(); i++)
	{
		objects.push_back(Object(objectWeights[i], objectCounts[i], i));
	}
	return objects;
}

void sort(std::vector<Object>& v)
{
	auto comparator = [](auto& x, auto& y) -> bool { return x.e < y.e; };
	std::sort(v.begin(), v.end(), comparator);
}

std::vector<float> selectObjectsQuantities(std::vector<Object> sortedObjects, float weight) //greedy
{
	std::vector<float> quantities;
	auto leftWeight = weight;
	for (auto it = sortedObjects.begin(); it != sortedObjects.end() && leftWeight != 0; ++it)
	{
		if (leftWeight >= it->weight)
		{
			quantities.push_back(1.F);
			leftWeight -= it->weight;
		}
		else
		{
			quantities.push_back(leftWeight / it->weight);
			leftWeight = 0.F;
		}
	}

	return quantities;
}

std::vector<float> selectObjectsQuantities(std::vector<float> objectWeights, std::vector<int> objectCounts, float maxWeight)
{
	auto objects = createObjects(objectWeights, objectCounts);
	sort(objects);
	std::vector<float> quantities;
	auto leftWeight = maxWeight;
	for (auto it = objects.begin(); it != objects.end() && leftWeight != 0; ++it)
	{
		if (leftWeight >= it->weight)
		{
			quantities.push_back(1.F);
			leftWeight -= it->weight;
		}
		else
		{
			quantities.push_back(leftWeight / it->weight);
			leftWeight = 0.F;
		}
	}

	return quantities;
}

void print(std::vector<Object> v, std::vector<float> quantities)
{
	for (int i = 0; i < quantities.size(); i++)
	{
		std::cout << "Object " << v[i].id << " in quantity " << quantities[i] * v[i].weight << '\n';
	}
}