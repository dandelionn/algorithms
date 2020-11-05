#pragma once
#include <vector>

struct Object {
	int id;
	float weight;
	int count;
	float e;
	Object(float weight, int count, int id) :
		weight(weight), count(count), e(count / weight), id(id) {}
};

std::vector<float> selectObjectsQuantities(std::vector<float> objectWeights, std::vector<int> objectCounts, float maxWeight);
void print(std::vector<Object> v, std::vector<float> quantities);