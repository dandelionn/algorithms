#include <iostream>
using namespace std;
int k=0;
void culori(int i,int n)
{
    if(n==1)
       k++;
    else
        {
            if(i>1)
               culori(i-1,n-1);
            if(i<5)
               culori(i+1,n-1);
        }
}
int main()
{
    int i,n;
    cout<<"n= ";cin>>n;
    for(i=1;i<=5;i++)
       culori(i,n);
    cout<<k;
}
