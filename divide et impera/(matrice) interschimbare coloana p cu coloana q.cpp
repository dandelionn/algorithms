#include <iostream>
using namespace std;
int v[10][10],n,m;
void divizeaza(int s,int d,int &m)
{
    m=(s+d)/2;
}
void dei(int s,int d,int &p,int &q)
{
    int m;
    if(d==s)
       {int aux=v[s][p];
       v[s][p]=v[s][q];
       v[s][q]=aux;}
    else
      {
          divizeaza(s,d,m);
          dei(s,m,p,q);
          dei(m+1,d,p,q);
      }
}
int main()
{
    int i,j,p,q;
    cout<<"n= ";cin>>n;
    cout<<"m= ";cin>>m;
    cout<<"p= ";cin>>p;
    cout<<"q= ";cin>>q;
    for(i=1;i<=n;i++)
       for(j=1;j<=m;j++)
          cin>>v[i][j];
    cout<<"tabloul initial: "<<'\n';
    for(i=1;i<=n;i++)
       {for(j=1;j<=m;j++)
          cout<<v[i][j]<<"  ";
       cout<<'\n';}
    dei(1,n,p,q);
    cout<<"tabloul modificat: "<<'\n';
    for(i=1;i<=n;i++)
       {for(j=1;j<=m;j++)
          cout<<v[i][j]<<"  ";
       cout<<'\n';}
}
