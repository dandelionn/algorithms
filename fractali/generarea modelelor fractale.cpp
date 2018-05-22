#include <iostream>
#include <math.h>
#include <winbgim.h>
using namespace std;
int x,y;
float alfa;
void stanga(float unghi)
{
    alfa+=unghi*M_PI/180.;
}
void dreapta(float unghi)
{
    alfa-=unghi*M_PI/180.;
}
void deseneaza(float L)
{
    int x1=x,y1=y;
    x+=(int)(L*cos(alfa));
    y+=(int)(L*sin(alfa));
    line(x,y,x1,y1);
}
void Koch(int n,float L)
{
    if(n==0)
       deseneaza(L);
    else
       {
           Koch(n-1,L/3);stanga(60);
           Koch(n-1,L/3);dreapta(120);
           Koch(n-1,L/3);stanga(60);
           Koch(n-1,L/3);
       }
}
void nucleu_Koch(int n,float L)
{
    Koch(n,L);dreapta(120);
    Koch(n,L);dreapta(120);
    Koch(n,L);dreapta(120);
}
int main()
{
    int n,L;
    cout<<"n= ";cin>>n;
    cout<<"L= ";cin>>L;
    nucleu_Koch(n,L);
}


