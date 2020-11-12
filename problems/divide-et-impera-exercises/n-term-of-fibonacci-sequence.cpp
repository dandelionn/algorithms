#include <iostream>
using namespace std;
int n;
void combina(int x1,int x2,int &z)
{
    z=x1+x2;
}
void dei(int n,int &z)
{
    int x1,x2;
    if(n==1||n==2)
      z=1;
    else
      {
        dei(n-1,x1);
        dei(n-2,x2);
        combina(x1,x2,z);
      }
}
int main()
{
    int z;
    cout<<"n=";cin>>n;
    dei(n,z);
    cout<<"termenul "<<n<<"= "<<z;
}
