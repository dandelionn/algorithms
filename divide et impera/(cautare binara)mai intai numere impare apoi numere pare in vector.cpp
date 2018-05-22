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
    if(d>=s&&(v[1]%2!=1&&x%2!=0))
      {
          divizeaza(s,d,m);
          if(v[m]%2!=x%2)
             if(x%2==1)
                cauta(m+1,d,z);
             else
                cauta(s,m,z);
          else
             if(v[m]==x)
                z=m;
             else
                if(x>v[m])
                   cauta(m+1,d,z);
                else
                   cauta(s,m,z);
      }
}
int main()
{
    int i,n,z=0;
    cout<<"n= ";cin>>n;
    cout<<"x= ";cin>>x;
    for(i=1;i<=n;i++)
       {cout<<"v["<<i<<"]=";
       cin>>v[i];}
    cauta(1,n,z);
    if(!z)
      cout<<"elementul "<<x<<" nu exista in vector";
    else
      cout<<"elementul exista pe pozitia "<<z;
}
