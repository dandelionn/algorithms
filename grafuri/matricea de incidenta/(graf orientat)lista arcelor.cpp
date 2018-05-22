#include <iostream>
#include <fstream>
using namespace std;
ofstream f("graf12.txt");
struct arce{int x,y;};
void term_izo(arce a[],int n,int m)
{
    int i,j,b[20],k=0,g;
    cout<<"noduri terminale: ";
    for(i=1;i<=n;i++)
       {g=0;
       for(j=1;j<=m;j++)
           if(a[j].x==i||a[j].y==i)
              g++;
       if(g==1)
          cout<<i<<' ';
       else
          if(g==0)
             b[++k]=i;}
    cout<<'\n'<<"noduri izolate: ";
    for(i=1;i<=k;i++)
       cout<<b[i]<<' ';
}
int main()
{
    arce a[20];
    int n,m,k;
    cout<<"numar de noduri= ";cin>>n;
    cout<<"numar de arce= ";cin>>m;
    f<<n<<' '<<m<<'\n';
    for(k=1;k<=m;k++)
       {
           cout<<"primul nod al arcului= "<<k<<" : ";cin>>a[k].x;
           cout<<"primul nod al arcului= "<<k<<" : ";cin>>a[k].y;
           f<<a[k].x<<' '<<a[k].y<<'\n';
       }
    term_izo(a,n,m);
}
