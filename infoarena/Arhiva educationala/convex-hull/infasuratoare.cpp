
#include <fstream>
#include <algorithm>
#include <list>
#include <cmath>
#include <iostream>

using namespace std;


ifstream f("infasuratoare.in");
ofstream g("infasuratoare.out");

struct Punct {
	double x, y;
};

struct cmp {
	bool operator()(Punct A, Punct B) const
	{
		if (A.x < B.x)
		{
			return 1;
		}
		else
		{
			if (A.x == B.x)
			{
				if (A.y < B.y)
				{
					return 1;
				}
				else
				{
					return 0;
				}
			}
			else
			{
				return 0;
			}
		}
	}
};

Punct punct[120001];
int n, i;
double x, y;

list<Punct> solution;
list<Punct>::iterator it;
list<Punct>::iterator pos;

double Distance(Punct P, double a, double b, double c)
{
	return abs(a*P.x + b*P.y + c) / sqrt(a*a + b*b);
}

Punct MostDistantPoint(list<Punct>& s, Punct A, Punct B)
{
	double a = B.y - A.y;
	double b = A.x - B.x;
	double c =  A.y * B.x - A.x * B.y;

	double dist = -1;
	double d;

	for (it = s.begin(); it != s.end(); ++it)
	{
		d = Distance(*it, a, b, c);

		if (d > dist)
		{
			dist = d;
			pos = it;
		}
	}

	Punct mostPoint = *pos;
	s.erase(pos);

	return mostPoint;
}

double Area(Punct A, Punct B, Punct C)
{
	return 0.5 * abs(A.x * B.y + C.x * A.y + B.x * C.y - C.x * B.y - A.x * C.y - B.x * A.y);
}

bool IsExternal(Punct it, Punct A, Punct B, Punct C)
{
	return Area(A, B, C) < (Area(it, A, B) + Area(it, B, C) + Area(it, A, C));
}

void Find_Hull(list<Punct> s, Punct minLeft, Punct maxRight, int c)
{
	if (s.size() > 0)
	{
		Punct mostPoint = MostDistantPoint(s, minLeft, maxRight);

		list<Punct> ext;
		for (it = s.begin(); it != s.end(); ++it)
		{
			if (IsExternal(*it, minLeft, maxRight, mostPoint))
			{
				ext.push_back(*it);
			}
		}

		list<Punct> s1;
		list<Punct> s2;
		for (it = ext.begin(); it != ext.end(); ++it)
		{
			if (it->x < mostPoint.x)
				s1.push_back(*it);
			else
				s2.push_back(*it);
		}

		Find_Hull(s2, minLeft, mostPoint, c);

		if (c == 0)
			solution.push_front(mostPoint);
		else
			solution.push_back(mostPoint);

		Find_Hull(s1, mostPoint, maxRight, c);
	}
}

double Slope(Punct A, Punct B)
{
	return (B.y - A.y) / (B.x - A.x);
}

void Convex_Hull()
{
	Punct minLeft = punct[0];
	Punct maxRight = punct[n - 1];

	if (minLeft.x == maxRight.x)
	{
		return;
	}
	else
	{
		list<Punct> s1;
		list<Punct> s2;
		double panta = Slope(minLeft, maxRight);
		for (i = 1; i<n - 1; i++)
		{
			if (minLeft.x == punct[i].x)
			{
				if (minLeft.y > punct[i].y)
				{
					s1.push_back(punct[i]);
				}
				else
				{
					s2.push_back(punct[i]);
				}
			}
			else
			{
				if (Slope(minLeft, punct[i]) < panta)
				{
					s1.push_back(punct[i]);
				}
				else
				{
					s2.push_back(punct[i]);
				}
			}
		}

		Find_Hull(s1, minLeft, maxRight, 0);
		solution.push_back(maxRight);
		Find_Hull(s2, minLeft, maxRight, 1);
		solution.push_back(minLeft);
	}
}

int main()
{
	f >> n;
	for (i = 0; i<n; i++)
	{
		f >> x >> y;

		punct[i].x = x;
		punct[i].y = y;
	}

	sort(punct, punct + n, cmp());

	Convex_Hull();

	g << solution.size() << "\n";
	for (it = solution.begin(); it != solution.end(); ++it)
	{
	    std::cout<< it->x << " " << it->y << "\n";
		g << it->x << " " << it->y << "\n";
	}
}

