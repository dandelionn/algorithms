#include <fstream>
#include <iostream>
using namespace std;

ifstream f("euclid3.in");
ofstream g("euclid3.out");



void euclid(int a,int b,int &d,int &x,int &y)
{
    if(b==0)
       {
           d=a;
           x=1;
           y=0;
       }
    else
       {
           int x0,y0;
           euclid(b, a%b , d, x0, y0);
           x=y0;
           y=x0-(a/b)*y0;
           cout<<d<<' '<<x<<' '<<y<<'\n';
       }
}

int i,T,a,b,c,x,y,d;

int main()
{
    f>>T;

    for(i=1;i<=T;i++)
        {f>>a>>b>>c;
        euclid(a, b, d, x, y);
        cout<<"\n"<<x<<' '<<y<<"\n\n";
        if(c%d)
           g<<0<<' '<<0<<'\n';
        else
           {x=x*(c/d);
           y=y*(c/d);
           g<<x<<' '<<y<<'\n';}}
    f.close();
    g.close();
    return 0;
}
