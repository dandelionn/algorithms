#include <vector>
#include <algorithm>
#include <expression_of_maximal_value.h>

int sumPositiveValuesStartingFromEnd(const std::vector<int>& valuesA, const std::vector<int>& valuesB)
{
	auto sum = 0;
	auto itA = valuesA.rend();
	auto itB = valuesB.rend();
	while (itA != valuesA.rbegin() && itB != valuesB.rbegin() && *itA > 0 && *itB > 0)
	{
		sum += *itA * *itB;
	}
	return sum;
}

int sumRemainingValuesFromBegin(const std::vector<int>& valuesA, const std::vector<int>& valuesB)
{
	auto sum = 0;
	auto itA = valuesA.begin();
	auto itB = valuesB.begin();
	while (itA != valuesA.end() && itB != valuesB.end())
	{
		sum += *itA * *itB;
	}
	return sum;
}

int computeExpressionOfMaximalValue(std::vector<int> valuesA, std::vector<int> valuesB)
{
	std::sort(valuesA.begin(), valuesA.end());
	std::sort(valuesB.begin(), valuesB.end());
	
	auto sum = sumPositiveValuesStartingFromEnd(valuesA, valuesB);
	sum += sumRemainingValuesFromBegin(valuesA, valuesB);
	
	return sum;
}