#include <iostream>
#include <fstream>
using namespace std;
ifstream f("pd2.txt");
int a[10],L[10],p[10],n,k;
void citeste()
{
    int i;
    f>>n;
    for(i=1;i<=n;i++)
       f>>a[i];
    f.close();
}
void init()
{
    L[n]=1;p[n]=n;
}
void p_dinamica()
{
    int i,j;
    for(i=n-1;i>=1;i--)
        {L[i]=1;p[i]=i;
        for(j=i+1;j<=n;j++)
           if(a[i]<=a[j]&&L[i]<=L[j])
               {L[i]=L[j]+1;p[i]=j;}}
}
void cauta_solutia()
{
    int i,max=-1;
    for(i=1;i<=n;i++)
       if(max<L[i])
          {
              max=L[i];
              k=i;
          }
}
void afiseaza()
{
    int i,j;
    cout<<"Lungime subsir= "<<L[k]<<'\n';
    for(i=1,j=k;i<=L[k];i++,j=p[j])
       cout<<a[j]<<" ";
}
int main()
{
    citeste();
    init();
    p_dinamica();
    cauta_solutia();
    afiseaza();
}
