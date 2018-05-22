#include <iostream>
#include <fstream>
using namespace std;
ifstream f("elemente.txt");
int a[20],c[20],m,n,p,r,exp=0;
void citeste()
{
    int i;
    f>>n>>m;
    for(i=1;i<=n;i++)
        f>>c[i];
    for(i=1;i<=m;i++)
        f>>a[i];
    f.close();
}
void sort1(int v[],int n)
{
    int i,j,aux;
    for(i=1;i<n;i++)
       for(j=i+1;j<=n;j++)
           if(v[i]>v[j])
              {
                  aux=v[i];
                  v[i]=v[j];
                  v[j]=aux;
              }
}
void sort2(int v[],int n)
{
    int i,j,aux;
    for(i=1;i<n;i++)
       for(j=i+1;j<=n;j++)
           if(v[i]<v[j])
              {
                  aux=v[i];
                  v[i]=v[j];
                  v[j]=aux;
              }
}
void greedy()
{
    cout<<"E= ";
    int i=n,j=m,k=0;
    while(c[i]>0&&a[j]<0&&k<n)
        {
              k++;
              cout<<"("<<c[i]<<")*("<<a[j]<<")+";
              exp+=c[i]*a[j];
              i--;
              j--;
        }
    p=i;r=j;i=1;j=1;
    while(c[i]<0&&a[j]>0&&k<n)
         {
             k++;
             cout<<"("<<c[i]<<")*("<<a[j]<<")+";
             exp+=c[i]*a[j];
             i++;
             j++;
         }
    if(c[i]<0)
        while(k<n)
            {
                k++;
                cout<<"("<<c[i]<<")*("<<a[j]<<")+";
                exp+=c[i]*a[j];
                i++;
                j++;
            }
    else
        {
        i=p;j=r;
        while(k<n)
            {
                k++;
                cout<<"("<<c[i]<<")*("<<a[j]<<")+";
                exp+=c[i]*a[j];
                i--;
                j--;
            }
        }
    cout<<'\b'<<"="<<exp;
}
int main()
{
    citeste();
    sort1(c,n);
    sort2(a,m);
    greedy();
}
