#include <fstream>
#include <algorithm>
#include <math.h>
#include <iomanip>

using namespace std;

ifstream f("cmap.in");
ofstream g("cmap.out");


struct punct{long long int x,y;}a[100001];
long long int n,i,j;
long double d, dist=999999999999999999.0;

struct func{
    bool operator()(punct x,punct y) const
      {  return x.x < y.x;   }
};

long double ddistance(punct a,punct b)
{
    return sqrt((long double)((long long)((long long)(a.x-b.x)*(a.x-b.x)+(long long)(a.y-b.y)*(a.y-b.y))));
}

int main()
{
    f>>n;
    for(i=1;i<=n;i++)
        f>>a[i].x>>a[i].y;

    sort(a+1,a+n+1,func());
    for(i=1;i<=n-1;i++)
            for(j=i+1;j<=n && a[j].x-a[i].x < dist;j++)
                  if(abs(a[j].y-a[i].y) < dist)
                       {d=ddistance(a[i],a[j]);
                       if(d<dist)
                           dist=d;}

    g<<std::fixed<<setprecision(7)<<dist;
}
