#include <iostream>
#include <fstream>
using namespace std;
int n,c[65]={0},sol[65];

ofstream g("room94.out");

void back(int k)
{
    int i;
    if(k<=n)
      for(i=1;i<=3;i++)
             {
                 sol[k]=i;
                 c[i]=1;
                 back(k+1);
                 c[i]=0;
             }
    else
       {for(i=1;i<=n;i++)
           g<<sol[i]<<' ';
       g<<'\n';}
}
int main()
{
    cin>>n;
    back(1);
}
