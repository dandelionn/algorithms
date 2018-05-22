#include <iostream>
#include <math.h>
using namespace std;
float p[100],v[100];
void combina(float x,float y,float &z)
{
    z=x+y;
}
void divizeaza(int s,int d,int &m)
{
    m=(s+d)/2;
}
void dei(int s,int d,float &z,float a)
{
    int m;
    float x1,x2;
    if(s==d)
       z=p[s]*pow(a,v[s]);
    else
       {
           divizeaza(s,d,m);
           dei(s,m,x1,a);
           dei(m+1,d,x2,a);
           combina(x1,x2,z);
       }
}
int main()
{
    int n,i,x;
    float z,a;
    cout<<"n= ";cin>>n;
    cout<<"punctul x= ";cin>>x;
    cout<<"elementul care se ridica la putere= ";cin>>a;
    cout<<"se citesc puterile: "<<'\n';
    for(i=1;i<=n;i++)
       {
           cout<<"puterea termenului "<<i<<"  ";
           cin>>v[i];
       }
    cout<<"se citesc coeficientii: "<<'\n';
    for(i=1;i<=n;i++)
       {
           cout<<"p["<<i<<"]=";
           cin>>p[i];
       }
    dei(1,x,z,a);
    cout<<"valoarea polinomului in punctul x= "<<z;
}
