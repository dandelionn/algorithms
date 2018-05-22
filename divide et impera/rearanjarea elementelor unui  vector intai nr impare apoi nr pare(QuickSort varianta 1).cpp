#include <iostream>
using namespace std;
int x[100],n;
void schimb(int &a,int &b)
{
    int aux=a;
    a=b;
    b=aux;
}
void divizeaza(int s,int d,int &m)
{
    int i=s,j=d,pi=0,pj=1;
    while(i<j)
        {
            if(x[i]%2<x[j]%2)
               {
                   schimb(x[i],x[j]);
                   schimb(pi,pj);
               }
            i=i+pi;
            j=j-pj;
        }
    m=i;
}
void QuickSort(int s,int d)
{
    int m;
    if(s<d)
       {
           divizeaza(s,d,m);
           QuickSort(s,m-1);
           QuickSort(m+1,d);
       }
}
int main()
{
    int i;
    cout<<"n= ";cin>>n;
    for(i=1;i<=n;i++)
       {
           cout<<"x["<<i<<"]=";
           cin>>x[i];
       }
    QuickSort(1,n);
    cout<<"vectorul sortat"<<'\n';
    for(i=1;i<=n;i++)
        cout<<x[i]<<' ';
}
