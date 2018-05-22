#include <fstream>
#include <stdlib.h>
#include <ctime>

using namespace std;

ifstream f("Date.in");
ofstream g("Date.out");

int v[3][256],n;

void sort(int n)
{
    int  ok,i,aux;
    do
      {ok=1;
      for(i=1;i<=n-1;i++)
         if(v[2][i]<v[2][i+1])
            {
                aux=v[2][i];
                v[2][i]=v[2][i+1];
                v[2][i+1]=aux;
                aux=v[1][i];
                v[1][i]=v[1][i+1];
                v[1][i+1]=aux;
                ok=0;
            }
      }
    while(ok==0);
}
int main()
{
    clock_t start = clock();
    int nr=0;
    while(nr<=200)
        {f>>n;
        for(int i=1;i<=n;i++)
           {v[1][i]=rand()%i;
           v[2][i]=rand()%i;}
        sort(n);
        for(int i=1;i<=n;i++)
           {g<<v[2][i]<<' ';
           if(i%10==0)
              g<<'\n';}
        g<<'\n';
        nr++;}
    clock_t ends = clock();
    g<<'\n';
    g<< "Running Time : " << (double) (ends - start) / CLOCKS_PER_SEC << endl;
    return 0;
}
