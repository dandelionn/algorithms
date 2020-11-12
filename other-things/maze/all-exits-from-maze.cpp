#include <fstream>
#include <iostream>
using namespace std;
struct element{int x,y;};
element a[100],d[5]={{0,0},{-1,0},{0,1},{1,0},{0,-1}};
int as,ev,k,n,m,p[100],L[10][10],este=0;
ifstream f("maze.in");
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
    int x=a[k-1].x,y=a[k-1].y;
    for(int i=1;i<k;i++)
       if(a[k].x==a[i].x&&a[k].y==a[i].y)
         return 0;
    switch(p[k])
       {
           case 1: if(L[x][y] & 1) return 1; break; //spre N;
           case 2: if(L[x][y] & 2) return 1; break; //spre E;
           case 3: if(L[x][y] & 4) return 1; break; //spre S;
           case 4: if(L[x][y] & 8) return 1;        //spre V;
       }
    return 0;
}
int solutie()
{
    return k>2 && L[a[k].x][a[k].y]==16;
}
void tipar()
{
    este=1;
    for(int i=1;i<k;i++)
       cout<<a[i].x<<","<<a[i].y<<' ';
}
void bt()
{
    k=2;
    init();
    while(k>1)
         {
             as=1;ev=0;
             while(as && !ev )
                  {as=succesor();
                  if(as)
                    ev=valid();}
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
    int i,j;f>>n>>m;
    for(i=1;i<=n;i++)
       for(j=1;j<=m;j++)
          f>>L[i][j];
    cout<<"Intrarea in labirint: "<<'\n';
    cout<<"x= ";cin>>i;a[1].x=i;
    cout<<"y= ";cin>>j;a[1].y=j;
    for(i=1;i<=n;i++)
        {L[i][0]=16;
        L[i][m+1]=16;}
    for(i=1;i<=m;i++)
        {L[0][i]=16;
        L[n+1][i]=16;}
    bt();
    if(!este)
      cout<<"Nu exista solutii";
}
