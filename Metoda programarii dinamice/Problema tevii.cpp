#include <iostream>
#include <fstream>
using namespace std;
ifstream f("pd3.txt");
int L,a[10],T[10],n,m;
void citeste()
{
    int i;
    f>>L>>n;
    for(i=1;i<=n;i++)
        f>>a[i];
    f.close();
}
void init()
{
    m=0;
    T[0]=-1;
}
void p_dinamica()
{
    int j,i;
    for(i=1;i<=n;i++)
       {for(j=m;j>=0;j--)
            if(j+a[i]<=L&&T[j]!=0&&a[i]!=0)
                T[j+a[i]]=a[i];
       if(a[i]+m<L)
          m+=a[i];
       else
          m=L;
       }
}
int solutie()
{
    return T[L]!=0;
}
void afiseaza()
{
    if(!solutie())
      cout<<"Teava nu se poate confectiona";
    else
      for(int i=L;i!=0;)
         {
             cout<<"Bucata de "<<T[i]<<" metri "<<'\n';
             i-=T[i];
         }
}
int main()
{
    citeste();
    init();
    p_dinamica();
    afiseaza();
}
