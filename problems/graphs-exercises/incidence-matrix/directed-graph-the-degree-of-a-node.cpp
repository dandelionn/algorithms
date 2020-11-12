#include <iostream>
#include <fstream>
using namespace std;
ofstream f("graf5.in");
int grad(int a[][20],int m,int p)
{
    int g=0,i;
    for(i=1;i<=m;i++)
        g+=a[p][i];
    return g;
}
int main()
{
    int n,m,a[20][20],i,j,k,p;
    cout<<"n= ";cin>>n;
    cout<<"m= ";cin>>m;
    for(i=1;i<=n;i++)
       for(j=1;j<=m;j++)
          a[i][j]=0;
    for(k=1;k<=m;k++)
        {
            cout<<"primul nod al muchiei "<<k<<": ";cin>>i;
            cout<<"al doilea nod al muchiei"<<k<<": ";cin>>j;
            a[i][k]=1;a[j][k]=1;
        }
    f<<n<<' '<<m<<'\n';
    for(i=1;i<=n;i++)
        {for(j=1;j<=m;j++)
            f<<a[i][j]<<' ';
        f<<'\n';}
    cout<<"nodul ";cin>>p;
    cout<<"gradul nodului "<<p<<" este: "<<grad(a,m,p);
    f.close();
}
