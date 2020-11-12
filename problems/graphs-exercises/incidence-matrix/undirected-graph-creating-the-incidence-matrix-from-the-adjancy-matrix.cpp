#include <iostream>
#include <fstream>
using namespace std;
ifstream f("graf1.txt");
ofstream g("graf9.txt");
void transformare(int a[][20],int b[][20],int n,int m)
{
    int i,j,k=0;
    for(i=1;i<=n-1;i++)
       for(j=i+1;j<=n;j++)
           if(a[i][j])
               {b[i][++k]=1;b[j][k]=1;}
}
void muchii(int b[][20],int n,int m)
{
    int i,j;
    for(i=1;i<=m;i++)
        {for(j=1;j<=n;j++)
            if(b[j][i]==1)
               g<<j<<' ';
        g<<'\n';}
}
void izolate(int b[][20],int n,int m)
{
    int x=0,i,j;
    cout<<"Noduri izolate: ";
    for(i=1;i<=n;i++)
       {x=0;
       for(j=1;j<=m;j++)
           x+=b[i][j];
       if(x==0)
          cout<<i<<' ';}
}
int main()
{
    int n,m,a[20][20],b[20][20],i,j;
    f>>n>>m;
    g<<n<<' '<<m<<'\n';
    for(i=1;i<=n;i++)
       for(j=1;j<=n;j++)
           f>>a[i][j];
    for(i=1;i<=n;i++)
       for(j=1;j<=m;j++)
           b[i][j]=0;
    transformare(a,b,n,m);
    muchii(b,n,m);
    izolate(b,n,m);
    f.close();
    g.close();
}
