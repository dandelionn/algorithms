#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;
float r=0.0001,a;
float f(float x)
{
    return x*x*x-a;
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
           if(f(s)*f(m)<=0)
             radical(s,m,z);
           else
             radical(m,d,z);
       }
}
int main()
{
    float x1,x2,z=0;
    cout<<"a^3= ";cin>>a;
    cout<<"intervalul in care se  gaseste solutia [x1,x2]:"<<'\n';
    cout<<"x1= ";cin>>x1;
    cout<<"x2= ";cin>>x2;
    radical(x1,x2,z);
    cout<<"partea intreaga a numarului a= "<<(int) z<<'\n';
    cout<<"a= "<<setiosflags(ios::fixed)<<setprecision(4)<<z<<'\n';
    cout<<"f(x)= "<<f(z)<<'\n';
    cout<<"pow(a,1.0/3.0)= "<<pow(a,1.0/3.0);
}
