#include <iostream>
using namespace std;
struct cop{int x,y;}a[100],b,c;
void combina(cop e1,cop e2,cop e3,cop e4,cop e5,cop e6,cop e7,cop e8,cop &z3,cop &z4)
{
    cout<<e1.x<<' '<<e2.x<<e1.y<<' '<<e2.y<<'\n';
    cout<<e3.x<<' '<<e4.x<<e1.y<<' '<<e2.y<<'\n';
    cout<<e5.x<<' '<<e6.x<<e1.y<<' '<<e2.y<<'\n';
    cout<<e7.x<<' '<<e8.x<<e1.y<<' '<<e2.y<<'\n';
    z3=e1;
    z4=e4;
}
void ter(int n,int x1,int y1,int x2,int y2,cop z1,cop z2,cop &z3,cop &z4)
{
    cop e1,e2,e3,e4,e5,e6,e7,e8;
    if(n==0)
       {
           z1.x=x1;z2.x=y1;
           z2.x=x2;z2.y=y2;
       }
    else
       {
           ter(n,x1,y1,x2,a[n-1].y,e1,e2,z3,z4);
           ter(n,x1,a[n-1].y,x2,y2,e3,e4,z3,z4);
           ter(n,x1,y1,a[n-1].x,y2,e5,e6,z3,z4);
           ter(n,a[n-1].x,y1,x2,y2,e7,e8,z3,z4);
           combina(e1,e2,e3,e4,e5,e6,e7,e8,z3,z4);
       }


}
int main()
{
    int n,i,x1,y1,x2,y2;
    cop z1,z2,z3,z4;
    cout<<"nr. de copaci= ";cin>>n;
    cout<<"x1= ";cin>>x1;
    cout<<"y1= ";cin>>y1;
    cout<<"x2= ";cin>>x2;
    cout<<"y2= ";cin>>y2;
    for(i=1;i<=n;i++)
       {
           cout<<"a["<<i<<"].x= ";cin>>a[i].x;
           cout<<"a["<<i<<"].y= ";cin>>a[i].y;
       }
    ter(n+1,x1,y1,x2,y2,z1,z2,z3,z4);
    cout<<"coordonatele colturilor:"<<'\n';
    cout<<"(("<<z3.x<<","<<z3.y<<");";
    cout<<"("<<z4.x<<","<<z4.y<<"))"<<'\n';
}
