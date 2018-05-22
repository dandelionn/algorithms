#include <fstream>
#include <algorithm>
using namespace std;

ifstream f("algsort.in");
ofstream g("algsort.out");

long int a[500011],i,n;

void merge(int p,int u,int m)
{
    long int b[500011],i=p,j=m+1,z=0;
    while(i<=m&&j<=u)
         if(a[i]<=a[j])
            b[++z]=a[i++];
         else
            b[++z]=a[j++];
    if(i<=m)
       for(;i<=m;i++)
           b[++z]=a[i];
    else
       for(;j<=u;j++)
           b[++z]=a[j];
    for(i=1;i<=z;i++)
        a[p++]=b[i];
}
void bin(int p,int u)
{
    if(p<u)
       {
           int m;
           m=(p+u)/2;
           bin(p,m);
           bin(m+1,u);
           merge(p,u,m);

       }
}


int main()
{
    f>>n;
    for(i=1;i<=n;i++)
        f>>a[i];

    bin(1,n);

    for(i=1;i<=n;i++)
        g<<a[i]<<' ';

    f.close();g.close();
}
