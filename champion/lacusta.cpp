#include <fstream>
#include <iostream>
using namespace std;
ifstream f("lacusta.in");
ofstream g("lacusta.out");
int a[251][251],n,m,minim,s=0,y;
int main()
{
    int i,j,x;
    f>>m>>n;
    for(i=1;i<=m;i++)
       for(j=1;j<=n;j++)
          f>>a[i][j];
    minim=1000;
    s+=a[1][1]+a[m][n];
    for(j=2;j<=n;j++)
        if(a[1][j]+a[2][j]<minim)
          {
                minim=a[1][j]+a[2][j];
                y=j;
          }
    s+=minim;
    for(i=2;i<m-1;i++)
          {
              minim=1000;
              for(j=1;j<=n;j++)
                   if(j!=y&&(a[i][j]+a[i+1][j]<minim))
                           {
                           minim=a[i][j]+a[i+1][j];
                           x=j;
                           }
               y=x;
               s+=minim;
           }
    minim=1000;
    for(j=1;j<=n-1;j++)
       if(j!=y&&(a[m-1][j]+a[m][j]<minim))
                minim=a[m-1][j]+a[m][j];
    s+=minim;
    g<<s;
    f.close();
    g.close();
}
