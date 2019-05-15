#include <iostream>
#include <fstream>
using namespace std;

ifstream f("arbore.txt");
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
int frunza(int i)
{
    return st[i]+dr[i]==0;
}
int nr_frunze(int i)
{
    if(frunza(i))
       return 1;
    else
        if(st[i]==0)
            return nr_frunze(dr[i]);
        else
           if(dr[i]==0)
               return nr_frunze(st[i]);
           else
               return nr_frunze(st[i])+nr_frunze(dr[i]);
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
    cout<<nr_frunze(r);
}
