#include <fstream>
#include <iostream>
using namespace std;
ofstream f("graf1.txt");
void scrie(int a[][10],int n,int m)
{
    f<<n<<' '<<m<<'\n';
    int i,j;
    for(i=1;i<=n;i++)
       {for(j=1;j<=n;j++)
           f<<a[i][j]<<' ';
       f<<'\n';}
    f.close();
}
int grad(int a[][10],int n,int i)
{
    int g=0,j;
    for(j=1;j<=n;j++)
        g+=a[i][j];
    return g;
}
int main()
{
    int a[10][10],n,m,g,i,j,k;
    cout<<"nr de noduri= ";
    cin>>n;
    cout<<"nr de muchii= ";
    cin>>m;
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            a[i][j]=0;
    for(k=1;k<=m;k++)
        {cout<<"primul nod al muchiei "<<k<<": ";cin>>i;
        cout<<"al doilea nod al muchiei "<<k<<": ";cin>>j;
        a[i][j]=1;a[j][i]=1;}
    cout<<"noduri izolate ";
    for(i=1;i<=n;i++)
       if(grad(a,n,i)==0)
          cout<<i<<' ';
    cout<<'\n'<<"noduri terminale ";
    for(i=1;i<=n;i++)
        if(grad(a,n,i)==1)
           cout<<i<<' ';
    scrie(a,n,m);
}
