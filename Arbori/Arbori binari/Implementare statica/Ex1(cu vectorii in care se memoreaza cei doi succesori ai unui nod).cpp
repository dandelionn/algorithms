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
int max(int x,int y)
{
    if(x>y)
       return x;
    else
       return y;
}
int h(int i)
{
    if(st[i]==0&&dr[i]==0)
       {if(i!=0)
            cout<<"nodul "<<i<<" este nod terminal;"<<'\n';
       return 0;}
    else
       {if(st[i]==0||dr[i]==0)
          cout<<"nodul "<<i<<" are un fiu;"<<'\n';
       if(st[i]!=0&&dr[i]!=0)
          {cout<<"nodul "<<i<<" are doi fii;"<<'\n';
          cout<<"nodurile "<<st[i]<<" & "<<dr[i]<<" sunt noduri frati;"<<'\n';}
       return 1+max(h(st[i]),h(dr[i]));}
}
int main()
{
    int r,i;
    f>>n;
    for(i=1;i<=n;i++)
        f>>st[i];
    for(i=1;i<=n;i++)
        f>>dr[i];
    r=rad();
    cout<<"nodul radacina este "<<r<<';'<<'\n';
    cout<<"inaltimea arborelui este "<<h(r)<<'.';
}
