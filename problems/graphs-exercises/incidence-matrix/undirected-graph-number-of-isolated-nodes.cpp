#include <iostream>
#include <fstream>
using namespace std;
ifstream f("date.in");
int verif(int a[][20],int n,int m)
{
    int i,j,x,y,nr,z;
    for(i=1;i<=m;i++)
       {nr=0;
       for(j=1;j<=n;j++)
           {if(a[j][i]!=1&&a[j][i]!=0)
              return 0;
            if(a[j][i]==1&&nr!=3)
                nr++;
            else
                 return 0;}}
    for(i=1;i<=m-1;i++)
        {for(j=1;j<=n;j++)
             if(a[j][i]==1&&i==0)
                x=j;
             else
                if(a[j][i]==1)
                   y=j;
        for(z=i+1;z<=m-1;z++)
            if(a[x][i]==a[x][z]||a[y][i]==a[y][z])
               return 0;}
   return 1;
}
int izolate(int a[][20],int n,int m)
{
    int i,j,nr=0,g;
    for(i=1;i<=n;i++)
       {g=0;
       for(j=1;j<=m;j++)
          g+=a[i][j];
       if(g==0)
         nr++;}
    return nr;
}
int main()
{
    int n,m,a[20][20],i,j;
    f>>n>>m;
    for(i=1;i<=n;i++)
       for(j=1;j<=m;j++)
          f>>a[i][j];
    if(verif(a,n,m))
       cout<<"Nr de noduri izolate= "<<izolate(a,n,m);
}
