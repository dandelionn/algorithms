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
    int pivot=x[s],i=s,j=d;
    while(i<j)
         {
             while(x[i]<pivot)
                  i++;
             while(x[j]>pivot)
                  j--;
            if(i<j)
                {schimb(x[i],x[j]);
                if(x[i]==x[j])
                   i++;}
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
    cout<<"vector sortat"<<'\n';
    for(i=1;i<=n;i++)
       cout<<x[i]<<' ';
}
