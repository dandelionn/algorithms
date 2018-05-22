#include <iostream>
using namespace std;

long long int i,j,s=1,a[21][500],k=2;
int main()
{
    a[1][0]=0;
    a[1][1]=1;
    for(i=2;i<20;i++)
        for(j=1;j<=i*(i-1);j++)
                 {if(j%i!=0)
                      a[i][j]=a[i-1][j/i+1]+k;
                 else
                      a[i][j]=a[i-1][j/i]+k;
                 k++;}

    for(i=0;i<5;i++)
        {for(j=1;j<25;j++)
             cout<<a[i][j]<<' ';
        cout<<'\n';}
}
