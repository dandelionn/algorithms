#include <iostream>
#include <stdlib.h>
using namespace std;
void generare(int a[][10],int n,int m)
{
    int i,j,k=0;
    while(k<m)
        {
            i=rand()%n+1;
            j=rand()%n+1;
            if(i!=j&&a[i][j]==0)
               {a[i][j]=1;
               k++;}
        }
}
int main()
{
    int a[10][10],n,m,i,j;
    cout<<"n= ";cin>>n;
    cout<<"m= ";cin>>m;
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
           a[i][j]=0;
    while(m>n*(n-1)/2-1)
         {
             cout<<"m= ";cin>>m;
         }
    generare(a,n,m);
    for(i=1;i<=n;i++)
       {for(j=1;j<=n;j++)
           cout<<a[i][j]<<' ';
       cout<<'\n';}
}