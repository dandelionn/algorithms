#include <iostream>
using namespace std;
int calcul(int n,long int a[])
{
    int i,nr,prime=0;
    long int d;
    for(i=0;i<n;i++)
       {
           d=2;nr=0;
           if(a[i]>1)
              {while(d<=a[i]/2)
                   {
                       if(a[i]%d==0)
                          nr++;
                       d++;
                   }
              if(nr==0)
                prime++;}
       }
    return prime;
}
int main()
{
    int n,i;
    long a[10000];
    cout<<"n=";cin>>n;
    for(i=0;i<n;i++)
       cin>>a[i];
    cout<<"nr de numere prime= "<<calcul(n,a);
}
