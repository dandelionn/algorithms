#include <iostream>
#include <fstream>
using namespace std;
ifstream f("graf19.in");
int st[100],a[20][20],n,ev,as,k,x,y,v[20],este=0;
void citeste()
{
    int i,j;
    f>>n;
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            f>>a[i][j];
    f.close();
}
void init()
{
    st[k]=0;
}
int succesor()
{
    if(st[k]<n)
       {st[k]++;
       return 1;}
    else
       return 0;
}
int valid()
{
    if(k>1)
       if(a[st[k-1]][st[k]]==0)  //Pentru graful neorientat
             return 0;           //if(a[st[k-1]][st[k]]==0&&a[st[k]][st[k-1]]) return 0;
    for(int i=1;i<k;i++)
       if(st[k]==st[i])     //conditia ca lantul sa fie elementar
          return 0;
    return 1;
}
int solutie()
{
    return st[k]==y;
}
void tipar()
{
    este=1;
}
void back()
{
    k=2;
    init();
    while(k>1)
         {
             as=1;ev=0;
             while(as&&!ev)
                  {
                      as=succesor();
                      if(as)
                         ev=valid();
                  }
             if(as)
               if(solutie())
                    tipar();
               else
                   {k++;
                   init();}
             else
                k--;
         }
}
void componente()
{
    int m=0;
    for(x=1;x<=n;x++)
       if(v[x]==0)
          {
              m++;
              st[1]=x;
              v[x]=1;
              cout<<"Componenta conexa "<<m<<": "<<x<<" ";
              for(y=1;y<=n;y++)
                 if(x!=y)
                    {
                        este=0;
                        back();
                        if(este)
                           {
                               v[y]=1;
                               cout<<y<<' ';
                           }
                    }
              cout<<'\n';
          }
}
int main()
{
    citeste();
    componente();
}
