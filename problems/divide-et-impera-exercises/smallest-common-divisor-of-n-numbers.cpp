#include <iostream>
using namespace std;
int v[100],n;
void divizeaza(int s,int d,int &m)
{
    m=(s+d)/2;
}
void dei(int s,int d,int &z,int &nr,int &k)
{
    int m;
    if(s==d)
        {

            if(nr>0)
               {k++;
               if(v[s]<z)
                 z=v[s];}
            else
               if(v[s]%z!=0)
                 {
                    if(nr==0)
                        z--;
                    else
                        {z=z/2;
                        nr=0;}
                    dei(1,k,z,nr,k);
                 }
        }
    else
       {
           divizeaza(s,d,m);
           dei(s,m,z,nr,k);
           dei(m+1,d,z,nr,k);
           if(nr==k)
                 {
                 nr=-1;
                 dei(1,k,z,nr,k);
                 }
       }
}
int main()
{
    int i,z=999999,nr,k;
    cout<<"n= ";cin>>n;
    for(i=1;i<=n;i++)
       {cout<<"v["<<i<<"]=";
       cin>>v[i];}
    nr=n;k=0;
    dei(1,n,z,n,k);
    cout<<"c.m.m.d.c="<<z;
}
