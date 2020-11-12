#include <iostream>
using namespace std;
struct element{int x,y;}a[100];
element d[9]={{0,0},{-1,2},{1,2},{2,1},{2,-1},{1,-2},{-1,-2},{-2,-1},{-2,1}};
int n,k,ev,as,p[100],este=0;
void init()
{
    p[k]=0;
}
int succesor()
{
    if(p[k]<8)
      {p[k]++;
      a[k].x=a[k-1].x+d[p[k]].x;
      a[k].y=a[k-1].y+d[p[k]].y;
      return 1;}
    else
      return 0;
}
int valid()
{
    if( a[k].x<1 || a[k].y<1 || a[k].x>n || a[k].y>n )
      return 0;
    for(int i=1;i<k;i++)
        if(a[k].x==a[i].x&&a[k].y==a[i].y)
            return 0;
    return 1;
}
int solutie()
{
    return k==n*n;
}
void tipar()
{
    este=1;
    for(int i=1;i<=n*n;i++)
       cout<<a[i].x<<','<<a[i].y<<' ';
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
    int i,j;
    cout<<"n=";cin>>n;
    cout<<"a[1].x=";cin>>i;
    cout<<"a[1].y=";cin>>j;
    a[1].x=i;a[1].y=j;
    bt();
    if(!este)
      cout<<"nu exista solutii";
}
