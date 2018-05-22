#include <iostream>
#include <fstream>
using namespace std;
ifstream f("graf20.txt");
void citeste(int a[][20],int &n)
{
    int i,j;
    f>>n;
    for(i=1;i<=n;i++)
       for(j=1;j<=n;j++)
           f>>a[i][j];
    f.close();
}
void transforma(int a[][20],int n)
{
    int i,j,k;
    for(k=1;k<=n;k++)
        for(i=1;i<=n;i++)
           for(j=1;j<=n;j++)
               if(a[i][j]==0&&i!=k&&j!=k)
                  a[i][j]=a[i][k]*a[k][j];
}
void componente(int a[][20],int v[],int n)
{
    int i,j,m=0;
    for(i=1;i<=n;i++)
       if(v[i]==0)
          {
              v[i]=1;
              m++;
              cout<<"componenta conexa "<<m<<": "<<i<<' ';
              for(j=1;j<=n;j++)
                  if(a[i][j]==1&&i!=j)
                     {v[j]=1;
                     cout<<j<<' ';}
              cout<<'\n';
          }
}
int main()
{
    int n,a[20][20],v[20]={0};
    citeste(a,n);
    transforma(a,n);
    componente(a,v,n);
}
