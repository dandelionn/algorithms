#include <iostream>
#include <fstream>
#include <math.h>
#include <vector>
#include <algorithm>

// polygon: v[i] * x ^ n + v[i] * x ^ (n-1) + ...

long computePolygon(std::vector<long> coeficients, long x)
{
	std::reverse(coeficients.begin(), coeficients.end());
	auto sum = 0L;
	for (auto i = 0; i < coeficients.size(); ++i)
	{
        sum += coeficients[i] * pow(x, i);
	}
	return sum;
}
