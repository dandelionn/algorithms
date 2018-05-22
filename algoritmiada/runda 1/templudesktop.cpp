#include <iostream>

using namespace std;

#define Nmax 20001
int a[Nmax][Nmax]={0},n,m,i,j,z=1;

int main()
{
    while(z<20000)
    {cout<<"n=";
    cin>>n;
    cout<<"m=";
    cin>>m;
    a[1][1]=1;
    a[2][1]=1;a[2][2]=1;
    for(i=3;i<=n;i++)
       {a[i][1]=a[i-2][1]%666013+a[i-1][1]%666013;
       a[i][i]=a[i][1];
       for(j=2;j<i;j++)
           a[i][j]=a[i-1][j-1]%666013+a[i-1][j]%666013;}
    cout<<a[n][m]%666013<<"\n\n";}
}
