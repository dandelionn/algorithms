#include <vector>
#include <algorithm>
#include <expression_of_minimal_value.h>

int sumOppositeSignedValuesStartingFromEnd(const std::vector<int>& valuesA, const std::vector<int>& valuesB)
{
	auto sum = 0;
	auto itA = valuesA.rend();
	auto itB = valuesB.rend();
	while (itA != valuesA.rbegin() && itB != valuesB.rbegin() && *itA > 0 && *itB < 0)
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
	std::sort(valuesB.begin(), valuesB.end(), std::greater());

	auto sum = sumPositiveValuesStartingFromEnd(valuesA, valuesB);
	sum += sumRemainingValuesFromBegin(valuesA, valuesB);

	return sum;
}

void sort1(int v[], int n)
{
	int i, j, aux;
	for (i = 1; i < n; i++)
		for (j = i + 1; j <= n; j++)
			if (v[i] > v[j])
			{
				aux = v[i];
				v[i] = v[j];
				v[j] = aux;
			}
}

void sort2(int v[], int n)
{
	int i, j, aux;
	for (i = 1; i < n; i++)
		for (j = i + 1; j <= n; j++)
			if (v[i] < v[j])
			{
				aux = v[i];
				v[i] = v[j];
				v[j] = aux;
			}
}

void greedy()
{
	int i = n, j = m, k = 0;
	while (c[i] > 0 && a[j] < 0 && k < n)
	{
		k++;
		exp += c[i] * a[j];
		i--;
		j--;
	}
	p = i; r = j; i = 1; j = 1;
	while (c[i] < 0 && a[j]>0 && k < n)
	{
		k++;
		exp += c[i] * a[j];
		i++;
		j++;
	}
	if (c[i] < 0)
		while (k < n)
		{
			k++;
			exp += c[i] * a[j];
			i++;
			j++;
		}
	else
	{
		i = p; j = r;
		while (k < n)
		{
			k++;
			exp += c[i] * a[j];
			i--;
			j--;
		}
	}
	cout << '\b' << "=" << exp;
}
int main()
{
	citeste();
	sort1(c, n);
	sort2(a, m);
	greedy();
}
