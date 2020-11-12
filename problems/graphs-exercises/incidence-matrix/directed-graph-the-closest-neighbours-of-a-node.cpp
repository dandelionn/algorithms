#include <iostream>
#include <fstream>
using namespace std;
ifstream f("graf8.in");
struct arc{int x,y,l;};
void vecini(arc a[],int m,int p)
{
    int i,min=60000;
    cout<<"vecinii ce mai apropiati sunt: ";
    for(i=1;i<=m;i++)
           if(a[i].x==p)
              if(a[i].l<min)
                 min=a[i].l;
    for(i=1;i<=m;i++)
       if(a[i].x==p&&a[i].l==min)
          cout<<'\n'<<a[i].y<<" cu lungimea "<<a[i].l;
}
int main()
{
    int n,m,k,p;
    arc a[20];
    f>>n>>m;
    for(k=1;k<=m;k++)
       f>>a[k].x>>a[k].y>>a[k].l;
    cout<<"nodul ";cin>>p;
    vecini(a,m,p);
    f.close();
}
