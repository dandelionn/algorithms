#include <algorithm>
#include <vector>
#include <quicksort.h>

void divide(std::vector<int>& values, int left, int right, int &m)
{
	auto i = left;
	auto j = right;
	auto pi = 0;
	auto pj = 1;
    while( i < j )
    {
        if(values[i] > values[j])
        {
            std::swap(values[i], values[j]);
            std::swap(pi, pj);
        }
        i = i + pi;
        j = j - pj;
    }
    m = i;
}

void QuickSort(std::vector<int>& values, int left, int right)
{
    int m;
    if(left<right)
      {
          divide(values, left, right, m);
          QuickSort(values, left,m-1);
          QuickSort(values, m+1,right);
      }
}