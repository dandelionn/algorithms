#include <iostream>
#include <fstream>
using namespace std;
ifstream f("graf6.in");
void succesori(int a[][20],int n,int m,int y,int s[])
{
    int g=0,i,j;
    for(j=1;j<=m;j++)
           if(a[y][j]==-1)
                for(i=1;i<=n;i++)
                    if(i!=y&&a[i][j]==1)
                          s[i]=1;
}
void predecesori(int a[][20],int n,int m,int y,int p[])
{
    int g=0,i,j,nr=0;
    for(j=1;j<=m;j++)
       if(a[y][j]==1)
           for(i=1;i<=n;i++)
               if(i!=y&&a[i][j]==-1)
                   p[i]=1;
}
void vecini(int s[],int p[],int n)
{
    int k;
    for(k=1;k<=n;k++)
       if(s[k]||p[k])
          cout<<k<<' ';
}
int main()
{
    int a[20][20],n,m,i,j,y,s[20],p[20];
    f>>n>>m;
    for(i=1;i<=n;i++)
       for(j=1;j<=m;j++)
           f>>a[i][j];
    for(i=1;i<=n;i++)
       {s[i]=0;p[i]=0;}
    cout<<"nodul ";cin>>y;
    succesori(a,n,m,y,s);
    predecesori(a,n,m,y,p);
    cout<<"Vecinii nodului "<<y<<" sunt: ";
    vecini(s,p,n);
    f.close();
}
