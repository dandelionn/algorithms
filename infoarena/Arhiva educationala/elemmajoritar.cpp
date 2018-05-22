#include <fstream>
#include <iostream>
#include <algorithm>
using namespace std;

ifstream f("elmaj.in");
ofstream g("elmaj.out");
struct element{long int v,k;}x;
long int a[1000001],i,k,elm,n;

int main()
{
    f>>n;
    for(i=1;i<=n;i++)
        f>>a[i];
    sort(a+1,a+n+1);

    x.v=a[1];  x.k=1; k=1;

    for(i=2;i<=n;i++)
        if(a[i]==a[i-1])
            k++;
        else
           {if(k>x.k)
              {x.k=k;
              x.v=a[i-1];}
           k=1;}
    if(x.k>=n/2+1)
       g<<x.v<<' '<<x.k;
    else
       g<<-1;
    f.close();g.close();
}
