#include <iostream>
using namespace std;
int v[100],n,x;
void combina(int x,int y,int &z)
{
    z=x+y;
}
void divizeaza(int s,int d,int &m)
{
    m=(s+d)/2;
}
void dei(int s,int d,int &z,int &x)
{
    int m,x1,x2;
    if(s==d)
      if(v[s]==x)
        z=1;
      else
        z=0;
    else
      {
          divizeaza(s,d,m);
          dei(s,m,x1,x);
          dei(m+1,d,x2,x);
          combina(x1,x2,z);
      }
}
int main()
{
    int z,i;
    cout<<"n=";cin>>n;
    cout<<"x=";cin>>x;
    for(i=1;i<=n;i++)
       {
           cout<<"v["<<i<<"]=";
           cin>>v[i];
       }
    dei(1,n,z,x);
    cout<<"numarul "<<x<<" se gaseste de "<<z<<" ori";
}
