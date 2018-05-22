#include <fstream>
#include <iostream>
using namespace std;

ifstream f("scmax.in");
ofstream g("scmax.out");

int const Nmax=100000;
long int a[Nmax],poz[Nmax],L[Nmax],n,i,j,nr=1;

int main()
{
    f>>n;
    for(i=1;i<=n;i++)
       f>>a[i];
    f.close();

    L[n]=1;poz[n]=n;

    for(i=n-1;i>=1;i--)
        {
            L[i]=1;poz[i]=i;
            for(j=i+1; j<=n;  j++)
               {if( a[i] < a[j] && L[i] <= L[j] )
                  {L[i]=L[j]+1;
                  poz[i]=j;}}
        }

    int maxim=-1,k;
    for(i=1;i<=n;i++)
       if(maxim<L[i])
         {maxim=L[i];
         k=i;}
    g<<L[k]<<'\n';

    for(i=1,j=k;i<=L[k];i++,j=poz[j])
       g<<a[j]<<' ';
    g.close();
}
