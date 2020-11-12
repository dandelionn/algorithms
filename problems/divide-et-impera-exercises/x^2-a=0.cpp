#include <iomanip>
#include <iostream>
#include <math.h>
using namespace std;
float r=0.0001;
int a;
float f(float x)
{
    return x*x-a;
}
void divizeaza(float s,float d,float &m)
{
    m=(s+d)/2;
}
void radical(float s,float d,float &z)
{
    float m;
    if(d-s<r)
       z=(s+d)/2;
    else
       {
           divizeaza(s,d,m);
           cout<<s<<' '<<m<<'\n';
           if(f(s)*f(m)<=0)
              radical(s,m,z);
           else
              radical(m,d,z);
       }
}
int main()
{
    float z=0,x1,x2;
    cout<<"x^2= ";cin>>a;
    cout<<"solutia se gaseste in intervalul intervalul [x1,x2]: "<<'\n';
    cout<<"x1= ";cin>>x1;
    cout<<"x2= ";cin>>x2;
    radical(x1,x2,z);
    cout<<"x= "<<setiosflags(ios::fixed)<<setprecision(4)<<z<<'\n';
    cout<<"f(z)= "<<f(z)<<'\n';
    cout<<"sqrt(x)= "<<sqrt(a);
}
