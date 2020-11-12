#include <iostream>
#include <fstream>
using namespace std;
int a[20][20],vizitat[10],c[10],p[10],n,prim,ultim,k,x;
ifstream f("BF.in");
void citeste()
{
    int i,j;
    f>>n;
    for(i=1;i<=n;i++)
       for(j=1;j<=n;j++)
           f>>a[i][j];
    f.close();
}
void zero()
{
    for(int i=1;i<=n;i++)
       {
           vizitat[i]=0;
           p[i]=0;
       }
}
void init(int k)
{
    prim=ultim=1;
    c[ultim]=k;
    vizitat[k]=1;
    p[k]=0;
}
int este_vida()
{return ultim<prim;}
void adaug(int i,int k)
{
    ultim++;
    c[ultim]=i;
    vizitat[i]=1;
    p[i]=k;
}
void prelucrare()
{
    int i;k=c[prim];
    for(i=1;i<=n;i++)
        if(a[k][i]==1&&vizitat[i]==0)
          adaug(i,k);
    prim++;
}
void afisare()
{
    int i,j,este,y,d[10];
    cout<<"Drumul minim care porneste din nodul "<<x<<": "<<'\n';
    for(j=1;j<=n;j++)
        if(j!=x)
          {
              cout<<"pana la nodul "<<j<<": ";
              for(i=1,este=0;i<=ultim&&!este;i++)
                  if(c[i]==j)
                     este=1;
              if(este==1)
                 {
                     y=p[j];
                     i=0;
                     while(y)
                        {
                            i++;
                            d[i]=y;
                            y=p[y];
                        }
                     for(;i>=1;i--)
                        cout<<d[i]<<' ';
                     cout<<j<<' ';
                 }
              else
                     cout<<"nu exista drum";
               cout<<'\n';
           }
    cout<<'\n';
}
int main()
{
    citeste();
    cout<<"Drumurile de lungime minima intre doua noduri sunt: "<<'\n';
    for(x=1;x<=n;x++)
       {
           zero();
           init(x);
           while(!este_vida())
                prelucrare();
           cout<<'\n';
           for(int i=1;i<=n;i++)
               cout<<c[i]<<' ';
           cout<<'\n';
           afisare();
       }
}
