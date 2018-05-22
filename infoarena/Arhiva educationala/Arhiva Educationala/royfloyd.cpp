#include <fstream>
#include <iostream>
using namespace std;
ifstream f("royfloyd.in");
ofstream g("royfloyd.out");
int a[101][101],n;
void citire()
{
    int i,j;
    f>>n;
    for(i=1;i<=n;i++)
       for(j=1;j<=n;j++)
           f>>a[i][j];
    f.close();
}
void transformare()
{
    int k,i,j;
    for(k=1;k<=n;k++)
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
                if(a[i][k]&&a[k][j]&&(a[i][j]>a[i][k]+a[k][j]||!a[i][j])&&i!=j)
                    a[i][j]=a[i][k]+a[k][j];
}
void afisare()
{
    int i,j;
    for(i=1;i<=n;i++)
       {for(j=1;j<=n;j++)
          g<<a[i][j]<<' ';
       g<<'\n';}
    g.close();
}
int main()
{
    citire();
    transformare();
    afisare();
}
