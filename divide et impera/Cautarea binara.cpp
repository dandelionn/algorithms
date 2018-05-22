#include <iostream>
using namespace std;
int v[100],n,x;
void divizeaza(int s,int d,int &m)
{
    m=(s+d)/2;
}
void cauta(int s,int d,int &z)
{
    int m;
    if(d>s)
       {divizeaza(s,d,m);
       if(v[m]==x)
          z=m;
       else
          if(x>v[m])
             cauta(m+1,d,z);
          else
             cauta(s,m,z);}
}
int main()
{
    int i,z=0;
    cout<<"n=";cin>>n;
    cout<<"x=";cin>>x;
    for(i=1;i<=n;i++)
       {
           cout<<"v["<<i<<"]=";
           cin>>v[i];
       }
    cauta(1,n,z);
    if(z==0)
       cout<<"elementul "<<x<<" nu exista in vector";
    else
       cout<<"elementul exista pe pozitia "<<z;
}
