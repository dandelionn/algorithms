#include <iostream>
#include <fstream>
using namespace std;

ifstream f("arbore1.txt");
int st[20],dr[20],n;
int rad()
{
    int i,j,ok;
    for(i=1;i<=n;i++)
       {ok=0;
       for(j=1;j<=n;j++)
          if(st[j]==i||dr[j]==i)
            ok=1;
       if(ok==0)
          return i;}
}
void srd(int i)
{
    if(st[i]!=0)
       srd(st[i]);
    cout<<i<<' ';
    if(dr[i]!=0)
       srd(dr[i]);
}
int main()
{
    int i,j,r;
    f>>n;
    for(i=1;i<=n;i++)
        f>>st[i];
    for(i=1;i<=n;i++)
        f>>dr[i];
    r=rad();
    srd(r);
}
