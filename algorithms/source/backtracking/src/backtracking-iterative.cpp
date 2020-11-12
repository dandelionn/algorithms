#include <iostream>
#include <math.h>
#include <vector>
#include <backtracking-iterative.h>

using namespace std;
int x[100],nsize,k,ev,as;

void init()
{
    x[k]=0;
}

int succesor()
{
    if(x[k]<nsize)
    {
        x[k]++;
        return 1;
    }
	else
	{
		return 0;
	}
}

int valid()
{
	for (int i = 1; i < k; i++)
	{
		if (x[k] == x[i])
		{
			return 0;
		}
	}
    return 1;
}

int solutie()
{
	return k==nsize;
}

void tipar()
{
	for (int i = 1; i <= nsize; i++)
	{
		cout << x[i] << ' ';
	}
    cout<<'\n';
}

void generateIterative(int n)
{
	nsize = n;
    k=1;
    init();
    while(k>0)
    {
        as=1; ev=0;
        while(as && !ev)
        {
            as=succesor();
            if(as)
            ev=valid();
        }
		if (as)
		{
			if (solutie())
			{
				tipar();
			}
			else
			{
				k++;
				init();
			}
		}
		else
		{
			k--;
		}
    }
}
