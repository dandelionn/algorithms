#include <iostream>
#include <backtracking-recursive.h>

using namespace std;
int nElements, c[65] = { 0 }, sol[65];

void generateRecursive(int k)
{
	int i;
	if (k <= nElements)
	{
		for (i = 1; i <= 3; i++)
		{
			if (c[i] == 0)
			{
				sol[k] = i;
				c[i] = 1;
				generateRecursive(k + 1);
				c[i] = 0;
			}
		}
	}
	else
	{
		for (i = 1; i <= nElements; i++)
		{
			std::cout << sol[i] << ' ';
		}
		std::cout << '\n';
	}
}
