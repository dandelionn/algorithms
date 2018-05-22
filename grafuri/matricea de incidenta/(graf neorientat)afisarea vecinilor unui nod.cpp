#include <iostream>
#include <fstream>
using namespace std;
ifstream f("graf5.txt");
void vecini(int a[][20],int n,int m,int p)
{
    int i,j;
    for(j=1;j<=m;j++)
      if(a[p][j]==1)
           for(i=1;i<=n;i++)
               if(i!=p)
                  if(a[i][j]==1)
                      {cout<<i<<' ';i=n+1;}
}
int main()
{
    int n,m,a[20][20],i,j,p;
    f>>n>>m;
    for(i=1;i<=n;i++)
       for(j=1;j<=m;j++)
          f>>a[i][j];
    cout<<"nodul ";cin>>p;
    cout<<"vecinii nodului "<<p<<" sunt: ";
    vecini(a,n,m,p);
    f.close();
}
