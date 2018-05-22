#include <iostream>
using namespace std;
int n;
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
    int x1,x2,m;
    if(d==s)
       if(s%2==0)
          z=-s*5;
       else
          z=s*5;
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
    int z;
    cout<<"n= ";cin>>n;
    dei(1,n,z);
    cout<<"suma= "<<z;
}
