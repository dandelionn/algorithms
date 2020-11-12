#include <iostream>
using namespace std;

size_t n,a[]={1,2,3,4,5};


size_t sets(size_t i,size_t j)
{
    if(i & 1<<(j-1))
       return 1;
    else
       return 0;
}
void bit(size_t n)
{
    for(size_t i=0; i<= ( 1 << n) ;i++)
       {for(size_t j=0;j<n;j++)
            if(sets(i,j))
                cout<<a[j]<<' ';
       cout<<'\n';}
}

int main()
{
   n=5;
   bit(n-1);
}
