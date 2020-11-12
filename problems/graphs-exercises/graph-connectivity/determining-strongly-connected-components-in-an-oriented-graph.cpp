#include <iostream>
#include <fstream>
using namespace std;
ifstream f("graf20.in");
int a[20][20],n,st[100],x,y,ev,as,k,este1,este2,este,v[20]={0};
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
       {
           st[k]++;
           return 1;
       }
    else
       return 0;
}
int valid()
{
    if(a[st[k-1]][st[k]]==0)
       return 0;
    for(int i=1;i<k;i++)
        if(st[i]==st[k])
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
    int m=0,i,j;
    for(i=1;i<=n;i++)
       if(v[i]==0)
          {
              m++;
              v[i]=1;
              cout<<"componeta conexa "<<m<<": "<<i<<' ';
              for(j=1;j<=n;j++)
                  if(i!=j)
                     {x=i; y=j; st[1]=x; este=0; back(); este1=este;
                     x=j; y=i; st[1]=x; este=0; back(); este2=este;
                     if(este1&&este2)
                        {v[j]=1;
                        cout<<j<<' ';}}
              cout<<'\n';
          }
}
int main()
{
    citeste();
    componente();
}
