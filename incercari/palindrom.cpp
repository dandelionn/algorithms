#include <iostream>
using namespace std;
void palindrom(int p,int u,int &n,int &z)
{
    int m;
    if(u==p)
       {if(n!=0)
          {z=z*10+n%10;
          n/=10;}}
    else
       {
           m=(p+u)/2;
           palindrom(p,m,n,z);
           palindrom(m+1,u,n,z);
       }
}
int main()
{
    int a,n,z=0;
    cin>>a;
    n=a;
    palindrom(1,9,n,z);
    cout<<a<<' '<<z<<'\n';
    if(a==z)
       cout<<"da";
}
