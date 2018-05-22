#include <fstream>

using namespace std;

ifstream f("carti.in");
ofstream g("carti.out");

struct el{int x,y;};
int n,d=2,nr,t=0,i=0,j;
el a[1001];
long long int m,c;

int main()
{
    f>>n>>m;
    c=m;
    while(m!=1&&d<=n&&d<=c/2)
        {nr=0;
        while(m%d==0)
            {nr++;
            m/=d;}
        if(nr)
           {i++;
           t+=nr;
           a[i].x=d;
           a[i].y=nr;}
           d++;}
    if(c<=n&&t==0)
       {g<<'1'<<'\n';
       g<<c<<' '<<'1'<<'\n';}
    else
        if(m!=1)
           g<<'0';
        else
            {g<<t<<'\n';
            for(j=1;j<=i;j++)
                g<<a[j].x<<' '<<a[j].y<<'\n';}
    return 0;
}
