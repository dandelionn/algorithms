#include <iostream>
using namespace std;
int n;
void partitii(int n1,int n2,int &k)
{
    k+=1;
    if(n1>n2)
       {
       partitii(n1-1,n1-2,k);
       partitii(n2-1,n2-2,k);
       }
}
int main()
{
    int k=1;
    cout<<"n= ";cin>>n;
    partitii(n-1,n-2,k);
    cout<<"nr de partitii= "<<k;
}