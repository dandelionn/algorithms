#include <iostream>
#include <fstream>
using namespace std;
ifstream f("pacienti.txt");
struct pacienti{int t,k;};
pacienti a[20];
int n,s=0;
void citeste()
{
    int i;
    f>>n;
    for(i=1;i<=n;i++)
       {f>>a[i].t;a[i].k=i;}
    f.close();
}
void sort()
{
    int i,j;
    pacienti aux;
    for(i=1;i<n;i++)
       for(j=i+1;j<=n;j++)
          if(a[i].t>a[j].t)
              {
                  aux=a[i];
                  a[i]=a[j];
                  a[j]=aux;
              }
}
void afiseaza()
{
    for(int i=1;i<=n;i++)
        {
        cout<<"pacientul "<<a[i].k<<" timp de consultatie "<<a[i].t<<" timp de asteptare "<<s<<'\n';
        s+=a[i].t;
        }
}
int main()
{
    citeste();
    sort();
    afiseaza();
}
