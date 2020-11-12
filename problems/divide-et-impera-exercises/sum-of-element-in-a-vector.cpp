#include <iostream>
using namespace std;
int v[100],n;
void divizeaza(int s,int d,int &m)
{
    m=(s+d)/2;
}
void combina(int x,int y,int &z)
{
    z=x+y;
}
void dei(int s,int d,int &z)
{
    int m,x1,x2;
    if(d==s)
       if(v[s]%2==0)
         z=v[s];
       else
          z=0;
    else
       {
           divizeaza(s,d,m);
           dei(s,m,x1);
           dei(m+1,d,x2);
           combina(x1,x2,z);
       }
}
int main()
{
    int i,z;
    cout<<"n=";cin>>n;
    for(i=1;i<=n;i++)
       {
           cout<<"v["<<i<<"]=";
           cin>>v[i];
       }
    dei(1,n,z);
    cout<<"suma="<<z;
}
