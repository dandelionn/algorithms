#include <iostream>
#include <fstream>

using namespace std;

ifstream f("arbore.txt");
int t[20],n,prim=1,ultim=1,c[20],d[20],k=0,vizitat[20]={0};

int rad()
{
    for(int i=1;i<=n;i++)
        if(t[i]==0)
           return i;
    return 0;
}
int next(int x)
{
    for(int i=1;i<=n;i++)
        if(t[i]==x&&!vizitat[i])
           {c[++ultim]=i;
           return 1;}
    d[++k]=x;
    vizitat[x]=1;
    return 0;
}
void prelucrare()
{
    int i,r=rad();
    if(r==0)
       cout<<"arbore vid (arbore nul)";
    else
       {
       c[ultim]=r;
       while(prim<=ultim&&prim>0)
          {while(vizitat[c[prim]])
              prim++;
          if(next(c[prim]))
             prim++;
          else
             while(vizitat[c[prim]])
                 prim--;}
       }
}
int main()
{
    int i;
    f>>n;
    for(i=1;i<=n;i++)
       f>>t[i];
    prelucrare();
    for(i=1;i<=n;i++)
       cout<<d[i]<<' ';
}

