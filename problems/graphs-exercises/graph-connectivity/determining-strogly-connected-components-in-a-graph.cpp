#include <iostream>
#include <fstream>
using namespace std;
ifstream f("graf20.in");
void citeste(int a[][20],int &n)
{
    int i,j;
    f>>n;
    for(i=1;i<=n;i++)
       for(j=1;j<=n;j++)
          f>>a[i][j];
    f.close();
}
void predecesor(int a[][20],int ap[][20],int n)
{
    int i,j;
    for(i=1;i<=n;i++)
       for(j=1;j<=n;j++)
          ap[i][j]=a[j][i];
}
void transforma(int t[][20],int n)
{
    int k,i,j;
    for(k=1;k<=n;k++)
       for(i=1;i<=n;i++)
          for(j=1;j<=n;j++)
             if(t[i][j]==0&&k!=i&&k!=j)
                t[i][j]=t[i][k]*t[k][j];
}
void intersectie(int a[][20],int ap[][20],int b[][20],int n)
{
    int i,j;
    for(i=1;i<=n;i++)
       for(j=1;j<=n;j++)
           b[i][j]=a[i][j]*ap[i][j];
}
void componente(int b[][20],int v[],int n)
{
    int i,j,m=0;
    for(i=1;i<=n;i++)
       if(v[i]==0)
          {
              m++;
              v[i]=1;
              cout<<"componenta conexa "<<m<<": "<<i<<' ';
              for(j=1;j<=n;j++)
                 if(i!=j&&b[i][j]==1)
                    {v[j]=1;
                    cout<<j<<' ';}
              cout<<'\n';
          }
}
int main()
{
    int a[20][20],ap[20][20],v[20]={0},n,b[20][20];
    citeste(a,n);
    predecesor(a,ap,n);
    transforma(a,n);
    transforma(ap,n);
    intersectie(a,ap,b,n);
    componente(b,v,n);
}
