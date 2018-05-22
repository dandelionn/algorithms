#include <iostream>
using namespace std;
int a[100];
int sort(int p,int u)
{
    int i=p,j=u,pi=0,pj=1,aux;
    while(i<j)
         {if(a[i]>a[j])
             {aux=a[i];
             a[i]=a[j];
             a[j]=aux;
             aux=pj;
             pj=pi;
             pi=aux;}
         i=i+pi;
         j=j-pj;}
    return j;
}
void divide(int p,int u)
{
    if(p<u)
       {int m=sort(p,u);
        divide(p,m-1);
       divide(m+1,u);}
}
int main()
{
    int n,i;
    cout<<"n= ";cin>>n;
    for(i=1;i<=n;i++)
        cin>>a[i];
    divide(1,n);
    for(i=1;i<=n;i++)
       cout<<i[a]<<' ';
}
