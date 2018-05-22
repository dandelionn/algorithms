#include <fstream>
#include <iostream>
using namespace std;
ifstream f("elemente.txt");
int a[20],c[20],p,r,m,n,exp=0;
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
void sort(int v[],int n)
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
void greedy()
{
    int i=n,j=m,k=0;  //indici:i-vector c,j-vector a,k-vector b
    cout<<"E= ";
    while(c[i]>0&&a[j]>0&&k<n)
        {
            k++;
            cout<<"("<<c[i]<<")*("<<a[j]<<")+";
            exp+=c[i]*a[j];
            i--;
            j--;
        }
    p=j;r=i;i=1;j=1;
    while(c[i]<0&&a[j]<0&&k<n)
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
    cout<<'\b'<<" = "<<exp;
}
int main()
{
    citeste();
    sort(c,n);
    sort(a,m);
    greedy();
}
