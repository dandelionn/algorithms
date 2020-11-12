#include <iostream>
using namespace std;
int p[100],q[100],r[100],n,m;
int maxim(int x,int y)
{
    if(x>y)
      return x;
    else
      return y;
}
int minim(int x,int y)
{
    if(x>y)
      return y;
    else
      return x;
}
void divizeaza(int s,int d,int &mijl)
{
    mijl=(s+d)/2;
}
void dei(int s,int d)
{
    int mijl;
    if(d==s)
       if(d<=minim(n,m)+1)
          r[d]=p[d]+q[d];
       else
         if(n<m)
            r[d]=q[d];
         else
            r[d]=p[d];
    else
        {
            divizeaza(s,d,mijl);
            dei(s,mijl);
            dei(mijl+1,d);
        }
}
int main()
{
    int i;
    cout<<"n= ";cin>>n;
    cout<<"m= ";cin>>m;
    for(i=1;i<=n+1;i++)
       {
           cout<<"p["<<i-1<<"]=";
           cin>>p[i];
       }
    for(i=1;i<=m+1;i++)
       {
           cout<<"q["<<i-1<<"]=";
           cin>>q[i];
       }
    dei(1,maxim(n,m)+1);
    for(i=maxim(n,m)+1;i>=1;i--)
       if(r[i]!=0)
          {
              if(r[i]!=1)
                {
                    cout<<r[i];
                    if(i!=1)
                       cout<<"*";}
              if(i>2)
                 cout<<"x^"<<i-1;
              else
                 if(i==2)
                    cout<<"x";
              if(i!=1)
                 cout<<" + ";
          }
}
