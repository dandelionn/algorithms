#include <vector>
#include <mergesort.h>

void interclass(std::vector<int>& values, int left, int right, int m)
{
	auto i = left;
	auto j = m + 1;
	auto k = 1;
	auto buffer = std::vector<int>();
    while( i <= m && j <= right )
    {
        if( values[i] < values[j] )
        {
            buffer.push_back(values[i]);
            i++;
        }
        else
        {
			buffer.push_back(values[j]);
            j++;
        }
    }
	if (i <= m)
	{
		while (i <= m)
		{
			buffer.push_back(values[i]);
			i++;
		}
	}
	else
	{
		while (j <= right)
		{
			buffer.push_back(values[j]);
			j++;
		}
	}
	for (k = 0, i = left; i <= right; k++, i++)
	{
		values[i] = buffer[k];
	}
}

void MergeSort(std::vector<int>& values, int left, int right)
{
    int m;
    if( left < right )
    {
		m = (left + right) / 2;
        MergeSort(values, left, m);
        MergeSort(values, m+1, right);
        interclass(values, left, right, m);
    }
}