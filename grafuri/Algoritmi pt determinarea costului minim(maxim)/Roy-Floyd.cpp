#include <iostream>
#include <fstream>
using namespace std;
ifstream f("cost.txt");
int const nrmax=5000;
void init(int a[][20],int n)
{
    int i,j;
    for(i=1;i<=n;i++)
       for(j=1;j<=n;j++)
           a[i][j]=nrmax;

}
void transformare(int a[][20],int n)
{
    int i,j,k;
    for(k=1;k<=n;k++)
       for(i=1;i<=n;i++)
           for(j=1;j<=n;j++)
               if(i!=j)
                  {
                  if(k!=i&&k!=j)
                      if(a[i][k]+a[k][j]<a[i][j])
                         a[i][j]=a[i][k]+a[k][j];}
               else
                  a[i][j]=0;
}
int main()
{
    int a[20][20],n,c,i,j;
    f>>n;
    init(a,n);
    while(f>>i>>j>>c)
         a[i][j]=c;
    transformare(a,n);
    for(i=1;i<=n;i++)
       {for(j=1;j<=n;j++)
           cout<<a[i][j]<<' ';
       cout<<'\n';}
    f.close();
}
