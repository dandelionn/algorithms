#include <iostream>
using namespace std;
int n,v[100];
void combina(int x,int y,int &z)
{
    z=x+y;
}
void divizeaza(int s,int d,int &m)
{
    m=(s+d)/2;
}
void dei(int s,int d,int &z)
{
    int m,x1,x2;
    if(s==d)
      if(v[s]>0)
        z=1;
      else
        if(v[s]<0)
          z=-1;
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
    if(z==n&&v[1]>0)
      cout<<"numai numere pozitive";
    else
      if(z==-n&&v[1]<0)
         cout<<"numai numere negative";
      else
         cout<<"pozitive si negative";
}
