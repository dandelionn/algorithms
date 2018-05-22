#include <iostream>
#include <fstream>

using namespace std;
int tata[20],fii[20],n;
ifstream f("arbore2.txt");
int rad()
{
    int i;
    for(i=1;i<=n;i++)
       if(tata[i]==0)
          return i;
}
int h(int i)
{
    int ok=0,x=-1,y=-1,j;
    for(j=1;j<=n;j++)
        if(tata[j]==i)
           {if(ok==0)
              {ok++;
               x=j;}
           else
              {ok++;
              y=j;}}
     if(ok==0&&i>0)
        cout<<"nodul "<<i<<" este nod terminal"<<'\n';
    if(ok==0)
        return 0;
    if(ok==1)
        cout<<"nodul "<<i<<" are un fiu"<<'\n';
    if(ok==2)
       {cout<<"nodul "<<i<<" are doi fii"<<'\n';
       cout<<"nodurile "<<x<<" & "<<y<<" sunt noduri frati"<<'\n';}
    return 1+h(x)+h(y);
}
int main()
{
    int r,i,j,ok;
    f>>n;
    for(i=1;i<=n;i++)
        f>>tata[i];
    for(i=1;i<=n;i++)
        f>>fii[i];
    r=rad();
    cout<<"nodul radacina "<<r<<'\n';
    cout<<"inaltimea este "<<h(r)-1;
}
