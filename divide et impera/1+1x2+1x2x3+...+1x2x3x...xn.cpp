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
void dei(int s,int d,int &z,int &aux)
{
    int m,x1,x2;
    if(d==s)
        {
           aux*=s;
           z=aux;
        }
    else
       {
           divizeaza(s,d,m);
           dei(s,m,x1,aux);
           dei(m+1,d,x2,aux);
           combina(x1,x2,z);
       }
}
int main()
{
    int z,aux=1;
    cout<<"n=";cin>>n;
    dei(1,n,z,aux);
    cout<<"suma="<<z;
}
