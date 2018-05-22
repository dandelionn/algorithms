#include <iostream>
using namespace std;
struct statistic{char denumire[40];int anc,anr;float valoare;}a[100],aux;
int n,i,j,c;
int main()
{
    cout<<"Numarul de...";cin>>n;
    for(i=0;i<n;i++)
       {
           cin.get();
           cin.get(a[i].denumire,40);
           cin.get();
           cin>>a[i].anc;
           cin>>a[i].anr;
           cin>>a[i].valoare;
       }
    for(i=0;i<n;i++)
       if(a[i].anc>=800&&a[i].anc<900)
         cout<<a[i].denumire<<'\n';
    cout<<"An curent ";cin>>c;
    for(i=0;i<n;i++)
       if(c-a[i].anr>50)
          cout<<a[i].denumire<<'\n';
    for(i=0;i<n-1;i++)
        for(j=i+1;j<n;j++)
           if(a[i].valoare>a[j].valoare)
             {aux=a[i];
             a[i]=a[j];
             a[j]=aux;}
}
