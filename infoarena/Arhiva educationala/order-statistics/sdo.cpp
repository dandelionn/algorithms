
#include <fstream>
#include <vector>

using VectorIterator = std::vector<long>::iterator;
using Vector = std::vector<long>;

VectorIterator compare(VectorIterator left, VectorIterator right)
{
	VectorIterator pivot = left + rand() % (std::distance(left, right) + 1);
	while (*right > *pivot)
	{
		--right;
	}
	std::swap(*right, *pivot);
	pivot = right;

	while (left < pivot)
	{
		while (*left > *pivot)
		{
			std::swap(*left, *(pivot - 1));
			std::swap(*(pivot - 1), *pivot);
			--pivot;
		}
		++left;
	}

	return pivot;
}

int findOrderStatistics(VectorIterator left, VectorIterator right, VectorIterator k)
{
	VectorIterator pivot = compare(left, right);
	if (k < pivot) return findOrderStatistics(left, pivot - 1, k);
	if (k > pivot) return findOrderStatistics(pivot + 1, right, k);
	return *pivot;
}

int findOrderStatistics(Vector& v, int k)
{
	return findOrderStatistics(v.begin(), v.end() - 1, v.begin() + k);
}

int main()
{
	std::ifstream fin("sdo.in");
	std::ofstream fout("sdo.out");
	int n = 0, k = 0, i = 0;
	long x = 0;
	fin >> n >> k;

	Vector v;
	for (i = 0; i < n; ++i) {
		fin >> x;
		v.push_back(x);
	}

	fout << findOrderStatistics(v, k - 1);

	return 0;
}