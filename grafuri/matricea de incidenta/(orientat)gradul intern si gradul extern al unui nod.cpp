#include <iostream>
#include <fstream>
using namespace std;
ofstream f("graf6.txt");
int grad_int(int a[][20],int m,int p)
{
    int g=0,i;
    for(i=1;i<=m;i++)
        if(a[p][i]==1)
           g++;
    return g;
}
int grad_ext(int a[][20],int m,int p)
{
    int g=0,i;
    for(i=1;i<=m;i++)
       if(a[p][i]==-1)
          g++;
    return g;
}
int main()
{
    int a[20][20],n,m,i,j,k,p;
    cout<<"n=";cin>>n;
    cout<<"m=";cin>>m;
    for(i=1;i<=n;i++)
       for(j=1;j<=m;j++)
           a[i][j]=0;
    for(k=1;k<=m;k++)
       {
           cout<<"nodul initial al arcului "<<k<<": ";cin>>i;
           cout<<"nodul final al arcului "<<k<<": ";cin>>j;
           a[i][k]=-1;a[j][k]=1;
       }
   f<<n<<' '<<m<<'\n';
   for(i=1;i<=n;i++)
      {for(j=1;j<=m;j++)
          f<<a[i][j]<<' ';
      f<<'\n';}
   cout<<"nodul ";cin>>p;
   cout<<"gradul intern al nodului p este: "<<grad_int(a,m,p)<<'\n';
   cout<<"gradul extern al nodului p este: "<<grad_ext(a,m,p);
   f.close();
}
