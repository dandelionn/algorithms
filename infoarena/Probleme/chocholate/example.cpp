#include <fstream>
using namespace std;

ofstream g("example.out");

int i, j, z, y, n,t=7;

int main()
{
   for(n=1;n<=t;n++)
    for(z=1;z<=n;z++)
       for(i=1;i<=n;i++)
         {for(j=1;j<=n;j++)
            {for(y=1;y<=n;y++)
                if(i==y&&z==j)
                   g<<1<<' ';
                else
                   g<<0<<' ';
            g<<'\n';}
          g<<'\n';}
}
