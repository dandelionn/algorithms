#include <iostream>
using namespace std;
int v[100],n;
void combina(int x1,int x2,int &z1,int y1,int y2,int &z2)
{
    if(x1>y1)
      z1=y1;
    else
      z1=x1;
    if(x2>y2)
      z2=x2;
    else
      z2=y2;
}
void divizeaza(int s,int d,int &m)
{
    m=(s+d)/2;
}
void dei(int s,int d,int &z1,int &z2)
{
    int m,x1,y1,x2,y2;
    if(d==s)
         z1=z2=v[s];
    else
      {
          divizeaza(s,d,m);
          dei(s,m,x1,x2);
          dei(m+1,d,y1,y2);
          combina(x1,x2,z1,y1,y2,z2);
      }
}
int main()
{
    int i,z1,z2;
    cout<<"n=";cin>>n;
    for(i=1;i<=n;i++)
       {cout<<"v["<<i<<"]=";
       cin>>v[i];}
    dei(1,n,z1,z2);
    cout<<"min="<<z1<<" "<<"max="<<z2;
}
