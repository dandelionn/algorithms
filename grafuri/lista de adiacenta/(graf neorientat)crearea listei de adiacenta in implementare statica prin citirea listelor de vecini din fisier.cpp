#include <iostream>
#include <fstream>
using namespace std;
ifstream f("graf13.txt");
ofstream g("graf15.txt");
void transpune(int a[][30],int b[][20],int n)
{
    int k,i,j;
    for(i=1;i<=n;i++)
        {k=a[1][i];
        if(a[1][i]!=0)
           {for(j=k;a[1][i]!=0;j++)
               {b[i][a[0][j]]=1;
               b[a[0][j]][i]=1;}
           b[i][a[0][j]]=1;
           b[a[0][j]][i]=1;}}
    for(i=1;i<=n;i++)
       {for(j=1;j<=n;j++)
           g<<b[i][j]<<' ';
       g<<'\n';}
}
int grad(int a[][30],int n)
{
    int k,i,nrmax=0,nr;
    for(i=1;i<=n;i++)
       {k=a[1][i];
       nr=0;
       if(a[1][i]!=0)
          {for(i=k;a[1][i]!=0;i++)
               nr++;
           nr++;}
       if(nr>nrmax)
          nrmax=nr;}
    return nrmax;
}
void grad_max(int a[][30],int n,int nrmax)
{
    int nr,i,k;
    for(i=1;i<=n;i++)
       {
           k=a[1][i];
           nr=0;
           if(a[1][i]!=0)
              {
                  for(i=k;a[1][i]!=0;i++)
                      nr++;
                  nr++;
              }
           if(nr==nrmax)
              cout<<i<<' ';
       }
}
int main()
{
    int n,m,a[2][30],i,j,k,nr,b[20][20];
    f>>n>>m;
    for(i=1;i<=n;i++)
       for(j=1;j<=n;j++)
           b[i][j]=0;
    k=n+1;
    for(i=1;i<=n;i++)
        {a[0][i]=i;
         f>>nr;
         a[1][j]=k;
         if(nr)
            for(j=1;j<=nr;j++)
               {
                  f>>a[0][k];
                  if(j<nr)
                     a[1][k]=k+1;
                  else
                     a[1][k]=0;
                  k++;
               }}
     cout<<"nodurile cu gradul cel mai mare sunt ";
     grad_max(a,n,grad(a,n));
     transpune(a,b,n);
     f.close();
     g.close();
}
