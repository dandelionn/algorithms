#include <fstream>
#include <iostream>

using namespace std;

ifstream f("newyork.in");
ofstream g("newyork.out");

#define nmax  50000

long int a[1001][1001],s=0;
int v[5],n,m;

void init()
{
    int i,j;
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            if(i!=j)
              a[i][j]=nmax;
            else
              a[i][j]=0;
}
void citire()
{
    int i,x,y,t;
    f>>n>>m;
    init();
    for(i=1;i<=4;i++)
       f>>v[i];
    for(i=1;i<=m;i++)
        {f>>x>>y>>t;
        a[x][y]=t;
        a[y][x]=t;}
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
          cout<<a[i][j]<<' ';
       cout<<'\n';}
    cout<<'\n'<<s;
    g.close();
}
void search()
{
    int i,j;
    long int h=100000000;
    for(j=1;j<=n;j++)
        {h=100000000;
        for(i=1;i<=4;i++)
            if(v[i]==j)
               h=0;
            else
               if(a[v[i]][j]<h)
                  h=a[v[i]][j];
        s+=h;}
}
int main()
{
    citire();
    transformare();
    search();
    afisare();
}
