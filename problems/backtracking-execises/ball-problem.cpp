#include <fstream>
#include <iostream>
using namespace std;
struct element{int x,y;};
element a[100],d[9]={{0,0},{-1,-1},{1,0},{1,-1},{1,1},{-1,1},{0,-1},{0,1},{-1,0}};
int n,m,k,ev,as,p[100],L[100][100],este=0;
ifstream f("ball.in");
void init()
{
    p[k]=0;
}
int succesor()
{
    if(p[k]<8)
      {p[k]=p[k]+1;
      a[k].x=a[k-1].x+d[p[k]].x;
      a[k].y=a[k-1].y+d[p[k]].y;
      return 1;}
    else
      return 0;
}
int valid()
{
    if((L[a[k].x][a[k].y]>=L[a[k-1].x][a[k-1].y])||a[k].x<=0||a[k].y<=0||a[k].x>=n+1||a[k].y>=m+1)
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
    int i,j,x,y;
    f>>n>>m>>x>>y;
    for(i=1;i<=n;i++)
       for(j=1;j<=m;j++)
           f>>L[i][j];
    a[1].x=x;a[1].y=y;
    bt();
    if(!este)
      cout<<"nu exista solutii";
    f.close();
}
