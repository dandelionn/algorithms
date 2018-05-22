#include <iostream>
using namespace std;

int n,a[]={1,2,3,4,5};


int sets(int i,int j)
{
    if(i & 1<<(j-1))
       return 1;
    else
       return 0;
}
void bit(int n)
{
    for(int i=0; i<= ( 1 << n-1)-1 ;i++)
       {for(int j=0;j<n;j++)
            if(sets(i,j))
                cout<<a[j]<<' ';
       cout<<'\n';}
}

int main()
{
   n=5;
   bit(n-1);
}
