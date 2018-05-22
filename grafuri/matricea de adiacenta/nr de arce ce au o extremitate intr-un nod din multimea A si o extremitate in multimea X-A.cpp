#include <iostream>
#include <fstream>
using namespace std;
ifstream f("graf2.txt");
int verific(int A[],int m,int i,int j)
{
    int k,nr1=0,nr2=0;
    for(k=1;k<=m;k++)
       {if(i==A[k])
          nr1++;
       if(j==A[k])
          nr2++;}
    if((nr1==1&&nr2==0)||(nr1==0&&nr2==1))
       cout<<i<<' '<<j<<'\n';
}
int main()
{
    int n,m,a[10][10],A[10],i,j;
    f>>n;
    for(i=1;i<=n;i++)
       for(j=1;j<=n;j++)
          f>>a[i][j];
    cout<<"m= ";cin>>m;
    for(i=1;i<=m;i++)
       cin>>A[i];
    for(i=1;i<=n;i++)
       for(j=1;j<=n;j++)
          if(a[i][j])
             verific(A,n,i,j);
}
