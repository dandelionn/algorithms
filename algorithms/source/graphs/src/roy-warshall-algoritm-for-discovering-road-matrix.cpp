#include <iostream>
#include <fstream>
using namespace std;
ifstream f("graf20.in");
void transformare(int a[][20],int n)
{
    int i,j,k;
    for(k=1;k<=n;k++)
       for(i=1;i<=n;i++)
          for(j=1;j<=n;j++)
              if(a[i][j]==0&&i!=k&&j!=k)
                 a[i][j]=a[i][k]*a[k][j];
}
int main()
{
    int a[20][20],n,i,j;
    f>>n;
    for(i=1;i<=n;i++)
       for(j=1;j<=n;j++)
          f>>a[i][j];
    transformare(a,n);
    cout<<"exista drum intre perechile de noduri: "<<'\n';
    for(i=1;i<=n;i++)
       for(j=1;j<=n;j++)
          if(i!=j)
           cout<<i<<"-"<<j<<'\n';
    f.close();
}
