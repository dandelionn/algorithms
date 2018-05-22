#include <iostream>
using namespace std;
int main()
{
    int a[100],n,i;
    cout<<"n=";cin>>n;
    for(i=0;i<n;i++)
       cin>>a[i];
    cout<<"************"<<'\n';
    cout<<'1'<<'\n';
    for(i=0;i<n;i++)
       if(a[i] & 1)
         cout<<a[i]<<' ';
    cout<<'\n'<<'2'<<'\n';
    for(i=0;i<n;i++)
       if(a[i] & 2)
         cout<<a[i]<<' ';
    cout<<'\n'<<'4'<<'\n';
    for(i=0;i<n;i++)
       if(a[i] & 4)
         cout<<a[i]<<' ';
    cout<<'\n'<<'8'<<'\n';
    for(i=0;i<n;i++)
       if(a[i] & 8)
         cout<<a[i]<<' ';
}
