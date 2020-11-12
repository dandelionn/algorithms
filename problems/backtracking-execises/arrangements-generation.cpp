#include <iostream>
#include <string.h>
using namespace std;
int a[100],n,k,ev,as,m;
struct cub{int l,c;}v[100];
void init()
{
    a[k]=0;
}
int succesor()
{
    if(a[k]<n)
      {
          a[k]+=1;
          return 1;
      }
    else
          return 0;
}
int valid()
{
    for(int i=1;i<k;i++)
        if(a[k]==a[i])
          return 0;
    return 1;
}
int solutie()
{
    return k==m;
}
void tipar()
{
    int sr=0;
    for(int i=1;i<m;i++)
       if(v[a[i]].l<=v[a[i+1]].l||v[a[i]].c==v[a[i+1]].c)
          sr++;
    if(sr==0)
       {for (int i=1;i<=m;i++)
           cout<<v[a[i]].l<<' '<<v[a[i]].c<<'\n';
       cout<<'\n';}
}
void bt()
{
    k=1;
    init();
    while(k>0)
        {
            as=1; ev=0;
            while(as && !ev)
                 {
                     as=succesor();
                     if(as)
                       ev=valid();
                 }
            if(as)
               if(solutie())
                  tipar();
               else
                  {
                      k++;
                      init();
                  }
            else
                k--;
        }
}
int main()
{
    cout<<"n=";cin>>n;
    cout<<"m=";cin>>m;
    for(int i=1;i<=n;i++)
        cin>>v[i].l>>v[i].c;
    bt();
}

