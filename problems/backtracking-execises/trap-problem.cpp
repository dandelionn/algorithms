#include <iostream>
#include <fstream>
using namespace std;
struct element{int x,y;};
element a[100],d[5]={{0,0},{-1,1},{1,1},{1,-1},{-1,-1}};
int n,m,k,ev,as,p[100],L[100][100],este=0,x2,y2;
ifstream f("traps.in");
void init()
{
    p[k]=0;
}
int succesor()
{
    if(p[k]<4)
      {
          p[k]=p[k]+1;
          a[k].x=a[k-1].x+d[p[k]].x;
          a[k].y=a[k-1].y+d[p[k]].y;
          return 1;
      }
    else
       return 0;
}
int valid()
{
    if(L[a[k].x][a[k].y]==1||a[k].x<=0||a[k].y<=0||a[k].x>=n+1||a[k].y>=m+1)
      return 0;
    for(int i=1;i<k;i++)
       if(a[k].x==a[i].x&&a[k].y==a[i].y)
           return 0;
    return 1;
}
int solutie()
{
    return a[k].x==x2&&a[k].y==y2;
}
void tipar()
{
    este=1;
    for(int i=1;i<=k;i++)
       cout<<a[i].x<<","<<a[i].y<<' ';
    cout<<'\n';
}
void bt()
{
    k=2;
    init();
    while(k>1)
        {
            as=1;ev=0;
            while( as && !ev )
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
    int x1,y1,i,j;
    f>>n>>m>>a[1].x>>a[1].y>>x2>>y2;
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            L[i][j]=0;
    while(f>>i>>j)
        L[i][j]=1;
    bt();
    if(!este)
      cout<<"nu exista solutii";
    f.close();
}
