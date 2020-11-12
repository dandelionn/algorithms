#include <iostream>
#include <iomanip>
using namespace std;
const float r=0.0001;
float f(float x)
{
    return x*x*x+x-1;
}
void divizeaza(float s,float d,float &m)
{
    m=(s+d)/2;
}
void radacina(float s,float d,float &z)
{
    float m;
    if(d-s<r)
      z=(s+d)/2;
    else
      {
          divizeaza(s,d,m);
          if(f(s)*f(m)<0)
             radacina(s,m,z);
          else
             radacina(m,d,z);
      }
}
int main()
{
    float z=0;
    radacina(0,1,z);
    cout<<"radacina= "<<setiosflags(ios::fixed)<<setprecision(4)<<z<<'\n';
    cout<<"f(x)= "<<f(z);
}
