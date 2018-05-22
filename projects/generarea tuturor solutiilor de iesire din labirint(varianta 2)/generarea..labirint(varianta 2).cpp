#include <fstream>
#include <iostream>
using namespace std;
struct element{int x,y;};
element a[100],d[5]={{0,0},{-1,0},{0,1},{1,0},{0,-1}};
int m,n,ev,as,k,este=0,p[100],L[100][100];
ifstream f("labirint2.txt");
void init()
{
    p[k]=0;
}
int succesor()
{
    if(p[k]<4)
      {p[k]=p[k]+1;
      a[k].x=a[k-1].x+d[p[k]].x;
      a[k].y=a[k-1].y+d[p[k]].y;
      return 1;}
    else
      return 0;
}
int valid()
{
    if(L[a[k].x][a[k].y]==0)
       return 0;
    for(int i=1;i<k;i++)
       if(a[k].x==a[i].x&&a[k].y==a[i].y)
          return 0;
    return 1;
}
int solutie()
{
    return a[k].x==1||a[k].x==n||a[k].y==1||a[k].y==m;
}
void tipar()
{
    este=1;
    for(int i=1;i<=k;i++)
       cout<<a[i].x<<","<<a[i].y<<" ";
    cout<<'\n';
}
void bt()
{
    k=2;
    init();
    while(k>1)
         {
             as=1;ev=0;
             while( as && !ev)
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
    int i,j;
    f>>n>>m;
    cout<<n;
    for(i=1;i<=n;i++)
       for(j=1;j<=m;j++)
          f>>L[i][j];
    cout<<"Intrarea in labirint: "<<'\n';
    cout<<"x= ";cin>>i;a[1].x=i;cout<<"y= ";cin>>j;a[1].y=j;
    bt();
    if(!este)
      cout<<"Nu exista solutii";
}
