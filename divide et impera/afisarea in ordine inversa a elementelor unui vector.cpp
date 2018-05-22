#include <iostream>
using namespace std;
int v[100],n;
void divizeaza(int s,int d,int &m)
{
    m=(s+d)/2;
}
void dei(int s,int d)
{
    int m;
    if(s==d)
      cout<<v[d]<<" ";
    else
       {
           divizeaza(s,d,m);
           dei(m+1,d);
           dei(s,m);
       }
}
int main()
{
    int i;
    cout<<"n= ";cin>>n;
    for(int i=1;i<=n;i++)
       {
           cout<<"v["<<i<<"]=";
           cin>>v[i];
       }
    dei(1,n);
}
