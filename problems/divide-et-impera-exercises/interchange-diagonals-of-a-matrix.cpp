#include <iostream>
using namespace std;
int v[10][10],n;
void divizeaza(int s,int d,int &m)
{
    m=(s+d)/2;
}
void dei(int s,int d,int &n)
{
    int m;
    if(d==s)
       {int aux=v[s][s];
       v[s][s]=v[s][n+1-s];
       v[s][n+1-s]=aux;}
    else
      {
          divizeaza(s,d,m);
          dei(s,m,n);
          dei(m+1,d,n);
      }
}
int main()
{
    int i,j;
    cout<<"n= ";cin>>n;
    for(i=1;i<=n;i++)
       for(j=1;j<=n;j++)
          cin>>v[i][j];
    cout<<"tabloul initial: "<<'\n';
    for(i=1;i<=n;i++)
       {for(j=1;j<=n;j++)
          cout<<v[i][j]<<"  ";
       cout<<'\n';}
    dei(1,n,n);
    cout<<"tabloul modificat: "<<'\n';
    for(i=1;i<=n;i++)
       {for(j=1;j<=n;j++)
          cout<<v[i][j]<<"  ";
       cout<<'\n';}
}
