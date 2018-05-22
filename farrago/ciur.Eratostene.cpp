#include <fstream>
#include <math.h>
using namespace std;
ifstream f("ciur.in");
ofstream g("ciur.out");
bool a[2000000];
int nr=0,i,j,n;
int main()
{
    f>>n;
    for(i=2;i<=n;i++)
       a[i]=1;
    for(i=2;i<=sqrt(n);i++)
       if(a[i])
         for(j=i;j<=n/i;j++)
            a[i*j]=0;
    for(i=2;i<=n;i++)
       if(a[i])
         nr++;
    g<<nr;
    f.close();
    g.close();
}
