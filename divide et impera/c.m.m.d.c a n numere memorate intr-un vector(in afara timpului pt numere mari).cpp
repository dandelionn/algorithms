#include <iostream>
using namespace std;
int v[100],n;
void combina(int x,int y,int &z)
{
    if(x<y)
       z=x;
    else
       z=y;
}
void divizeaza(int s,int d,int &m)
{
    m=(s+d)/2;
}
void dei(int s,int d,int &z,int &nr,int &k)
{
    int m,x1=z,x2=z;
    if(s==d)
        {
            if(nr!=0)
               {k++;
                z=v[s];}
            else
               if(v[s]%z!=0)
                 {
                      z--;
                 dei(1,k,z,nr,k);}
        }
    else
       {
           divizeaza(s,d,m);
           dei(s,m,x1,nr,k);
           dei(m+1,d,x2,nr,k);
           combina(x1,x2,z);
           if(nr==k)
                 {
                 nr=0;
                 dei(1,k,z,nr,k);
                 }
       }
}
int main()
{
    int i,z,nr,k;
    cout<<"n= ";cin>>n;
    for(i=1;i<=n;i++)
       {cout<<"v["<<i<<"]=";
       cin>>v[i];}
    nr=n;k=0;
    dei(1,n,z,n,k);
    cout<<"c.m.m.d.c="<<z;
}
