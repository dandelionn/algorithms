#include <iostream>
#include <fstream>
using namespace std;
ifstream f("DF.in");
int a[20][20],n,st[20],k,vf,vizitat[20]={0};
void citeste()
{
    int i,j;
    f>>n;
    for(i=1;i<=n;i++)
       for(j=1;j<=n;j++)
          f>>a[i][j];
    f.close();
}
void init(int k)
{
    vf=1;
    st[vf]=k;
    vizitat[k]=1;
}
void adaug(int i)
{
    vf++;
    st[vf]=i;
    vizitat[i]=1;
}
void prelucreaza()
{
    int i;
    while(vf>0)
        {i=1;
        k=st[vf];
        while(i<=n&&(a[i][k]==0||(a[i][k]==1&&vizitat[i]==1)))
               i++;
        if(i>n)
           vf--;
        else
          {
           cout<<i<<' ';
           adaug(i);
          }}
}
int main()
{
    citeste();
    cout<<"nodul de la care incepe parcurgerea este ";cin>>k;
    cout<<"Parcurgerea: "<<k<<' ';
    init(k);
    prelucreaza();
}
