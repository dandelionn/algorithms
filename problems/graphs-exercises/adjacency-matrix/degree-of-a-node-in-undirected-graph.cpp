#include <fstream>
#include <iostream>
using namespace std;
ofstream f("graf2.in");
void scrie(int a[][10],int n,int m)
{
    int i,j;
    f<<n<<' '<<m<<'\n';
    for(i=1;i<=n;i++)
        {for(j=1;j<=n;j++)
           f<<a[i][j]<<' ';
        f<<'\n';}
    f.close();
}
int grad_intern(int a[][10],int n,int j)
{
    int i,g=0;
    for(i=1;i<=n;i++)
        g+=a[i][j];
    return g;
}
int grad_extern(int a[][10],int n,int i)
{
    int j,g=0;
    for(j=1;j<=n;j++)
        g+=a[i][j];
    return g;
}
int main()
{
    int a[10][10],i,j,n,m,k;
    cout<<"nr noduri=";cin>>n;
    cout<<"nr arce=";cin>>m;
    for(i=1;i<=n;i++)
       for(j=1;j<=n;j++)
          a[i][j]=0;
    for(k=1;k<=m;k++)
        {
            cout<<"extremitatea initiala "<<k<<": ";cin>>i;
            cout<<"extremitatea finala "<<k<<": ";cin>>j;
            a[i][j]=1;
        }
    cout<<"noduri izolate ";
    for(i=1;i<=n;i++)
        if(grad_intern(a,n,i)+grad_extern(a,n,i)==0)
           cout<<i<<' ';
    cout<<'\n'<<"noduri terminale ";
    for(i=1;i<=n;i++)
        if(grad_intern(a,n,i)+grad_extern(a,n,i)==1)
           cout<<i<<' ';
    scrie(a,n,m);
}
