#include <iostream>
#include <fstream>

using namespace std;

ifstream f("livada.in");
ofstream g("livada.out");

struct puncte{float x,y;char l;}a[100];

int main()
{
    int i,j,n;

    f>>n;
    for(i=1;i<=n;i++)
        f>>a[i].x>>a[i].y>>a[i].l;

    for(j=1;j<=n;j++)
           if(i!=j)
              {
                  g<<"panta dreptei "<<"O"<<a[j].l<<":  ";
                  g<<a[j].y-3<<"/";
                  g<<a[j].x-3;
                  if((a[j].y-3)!=0&&(a[j].x-3!=0))
                     g<<"     /  "<<(a[j].y-3)/(a[j].x-3)<<'\n';
                  else
                      if((a[j].y-3)==0)
                         g<<"    / 0"<<'\n';
                      else
                           g<<"    /  10000"<<'\n';
              }
}
