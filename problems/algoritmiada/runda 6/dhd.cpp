#include <fstream>
#include <math.h>
#include <iostream>
using namespace std;

ifstream f("formula.in");
ofstream g("formula.out");

int n=6,y,sol[101],semn[3],x[101][3],x0;

int ecuatie(int e)
{
    int i,s=0;
    for(i=2;i<=n;i+=2)
       s+=sol[i-1]*sol[i]*pow(e,i/2-1);
    for(i=1;i<=n;i++)
       g<<sol[i]<<' ';
    g<<"             "<<s<<'\n';
    return s;
}
int back(int k)
{
    int i;
    if(k<=n)
      {if(k%2==1)
         for(i=1;i<=2;i++)
            {
                sol[k]=semn[i];
                back(k+1);
            }
      else
         for(i=0;i<=50;i++)
             {
                 sol[k]=i;
                 back(k+1);
             }}
    else
       {int nr=0;
        for(i=1;i<=y;i++)
           if(ecuatie(x[i][1])==x[i][2])
              nr++;
        if(nr==y)
            {return ecuatie(x0);
            k=n+1;}}
}
int main()
{
    int i;
    semn[1]=1;semn[2]=-1;
    f>>y>>x0;
    for(i=1;i<=y;i++)
        f>>x[i][1]>>x[i][2];
    back(1);
}
