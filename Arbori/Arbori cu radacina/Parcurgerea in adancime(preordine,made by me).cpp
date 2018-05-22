#include <iostream>
#include <fstream>

using namespace std;

ifstream f("arbore.txt");

int t[20],n,vizitat[20]={0},prim=1,ultim=1,desc0[20],c[20];
int nodr()
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
          vizitat[i]=1;
          return 1;}
    desc0[x]=0;
    return 0;
}
void prelucrare()
{
    int i,r;
    r=nodr();
    if(r==0)
       cout<<"Arbore vid(arbore nul)";
    else
       {c[ultim]=r;
       vizitat[r]=1;
       while(prim<=ultim&&prim>0)
            {while(!desc0[c[prim]])
                    prim++;
            if(next(c[prim]))
                prim++;
            else
                while(!desc0[c[prim]]&&prim>0)
                    prim--;}}
}
int main()
{
    int i;
    f>>n;
    for(i=1;i<=n;i++)
        {f>>t[i];
        desc0[i]=1;}
    prelucrare();
    for(i=1;i<=n;i++)
        cout<<c[i]<<' ';
}
