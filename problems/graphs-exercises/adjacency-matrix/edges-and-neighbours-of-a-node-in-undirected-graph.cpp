#include <iostream>
#include <fstream>
using namespace std;
ifstream f("graf1.in");
int grad(int a[][10],int n,int i)
{
    int j,g=0;
    for(j=1;j<=n;j++)
        g+=a[i][j];
    return g;
}
int nr_muchii(int a[][10],int n)
{
    int i,j,nr=0;
    for(i=1;i<=n;i++)
       for(j=1;j<=n;j++)
          if(a[i][j]==1)
              nr++;
    return nr;
}
int main()
{
    int n,a[10][10],i,j,vec,m;
    f>>n;
    for(i=1;i<=n;i++)
       for(j=1;j<=n;j++)
           f>>a[i][j];
    vec=grad(a,n,1);
    for(i=2;i<=n;i++)                                      //nr de vecinatati=gradul nodului
        if(grad(a,n,i)>vec)
          vec=grad(a,n,i);
    cout<<"nodurile cu nr maxim de vecinatati sunt: ";
    for(i=1;i<=n;i++)
       if(grad(a,n,i)==vec)
          cout<<i<<' ';
    m=nr_muchii(a,n)/2;
    cout<<'\n'<<"nr de muchii= "<<m;
    cout<<'\n'<<"muchiile sunt:"<<'\n';
    for(i=1;i<=n;i++)
        for(j=i+1;j<=n;j++)
           if(a[i][j])
              cout<<i<<' '<<j<<'\n';
}
