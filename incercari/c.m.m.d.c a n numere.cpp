#include <iostream>
using namespace std;
int a[100],n,*p;
int divizori(int a,int b)
{
    int r=a%b;
    while(r!=0)
        {
            a=b;
            b=r;
            r=a%b;
        }
    return b;
}
int main()
{
    cout<<"n= ";cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];
}
