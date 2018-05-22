#include <fstream>
#include <iostream>
#include <algorithm>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int a[1025],b[1025],c[1025][1025],v[1025],m,n;
int main()
{
    int i,j,nr=0;
    f>>n>>m;
    for(i=1;i<=n;i++)
        f>>a[i];
    for(j=1;j<=m;j++)
        f>>b[j];
    f.close();
    for(i=1;i<=n;i++)
       for(j=1;j<=m;j++)
           {if(a[i]==b[j])
              c[i][j]=c[i-1][j-1]+1;
           else
              c[i][j]=max(c[i-1][j],c[i][j-1]);}
    i=n;j=m;
    while(i)
         {
             if(a[i]==b[j])
                 {
                     nr++;
                     v[nr]=a[i];
                     i--;
                     j--;
                 }
             else
                 if(c[i-1][j]<c[i][j-1])
                     j--;
                 else
                     i--;
         }
    g<<nr<<'\n';
    for(i=nr;i>=1;i--)
       g<<v[i]<<' ';
    g.close();
}
