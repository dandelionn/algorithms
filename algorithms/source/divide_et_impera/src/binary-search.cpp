#include <iostream>
#include <vector>
#include <binary-search.h>

void BinarySearch(std::vector<int>& values, int searchedValue, int left, int right, int &position)
{
	if (right > left)
	{
		auto m = (left + right) / 2;
		if (values[m] == searchedValue)
		{
			position = m;
		}
		else
		{
			if (searchedValue > values[m])
			{
				BinarySearch(values, searchedValue, m + 1, right, position);
			}
			else
			{
				BinarySearch(values, searchedValue, left, m, position);
			}
		}
	}
}