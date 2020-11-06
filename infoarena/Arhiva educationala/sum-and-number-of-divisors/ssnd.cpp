#include <fstream>
#include <math.h>
#include <iostream>
#include <bitset>

std::ifstream f("ssnd.in");
std::ofstream g("ssnd.out");

using namespace std;

constexpr int MAXN = 1000001;

int primes[100001];
int K = 0;

void findPrimes()  ///Ciurul lui Eratosthenes
{
	bitset <MAXN> filter;

	for (int i = 0; i < MAXN; ++i)
	{
		filter[i] = 1;
	}
	for (int i = 2; i < MAXN; ++i)
	{
		if (filter[i])
		{
			primes[K] = i;
			++K;

			for (auto j = i + i; j < MAXN; j += i)
			{
				filter[j] = 0;
			}
		}
	}
}

inline int power(int n, int p, int mod)  ///Ridicare la putere in timp logaritmic
{
	auto r = 1;

	while (p != 1)
	{
		if (p % 2 == 1)
			r = (1LL * n * r) % mod;
		n = (1LL * n * n) % mod;
		p = p / 2;
	}

	return (1LL * n * r) % mod;
}

//(a - b) mod p = ((a mod p - b mod p) + p) mod p
//(a / b) mod p = ((a mod p) * (b^(-1) mod p)) mod p
//Where b^(-1) mod p is the modular inverse of b mod p. For p = prime, b^(-1) mod p = b^(p - 2) mod p

void solve(long long x)
{
	auto sum = 1;
	auto nr = 1;

	for (int i = 0; i < K && 1LL * primes[i] * primes[i] <= x; ++i)
	{
		auto nr_d = 0;
		while (x % primes[i] == 0)
		{
			++nr_d;
			x /= primes[i];
		}

		if (nr_d > 0)
		{
			auto mi = power(primes[i] - 1, 9971, 9973);                 ///For p = prime, b^(-1) mod p = b^(p - 2) mod p
			auto prime_pow = power(primes[i], nr_d + 1, 9973) - 1;

			sum = (1LL * sum * prime_pow * mi) % 9973;
			nr *= nr_d + 1;
		}
	}
	if (x > 1)
	{
		nr = nr * 2;
		sum = (1LL * sum * ((x + 1) % 9973)) % 9973;
	}

	g << nr << ' ' << sum << '\n';
}

int main()
{
	auto t = 0;
	auto x = 0LL;

	findPrimes();

	f >> t;
	while (t > 0)
	{
		f >> x;
		solve(x);
		--t;
	}
}