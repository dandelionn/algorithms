#include <iostream>
using namespace std;
int i,a[20],s,b[20],c[10][10],n,j,suma=0;
void calcul();
int main()
{
    cout<<"n=";cin>>n;
    for(i=1;i<=n;i++)
       for(j=1;j<i+1;j++)
          cin>>c[i][j];
    i=1;
    while(i>0)
         {
             a[i]++;
             i++;
             if(i==n)
                   while(a[i]!=2)
                        {
                            a[i]++;
                            calcul();
                        }
             while(a[i]==2)
                  {
                      a[i]=0;
                      i--;
                  }
         }
 cout<<suma<<'\n';  //suma elementelor
 for(i=1;i<=n;i++)
    cout<<b[i]<<' ';   //traseul pe care se duce in jos
}
void calcul()
{
    int j,z;
    s=0;
    z=1;
    for(j=1;j<=n;j++)
       if(a[j]==1)    //1=se duce in jos
          s+=c[j][z];
       else
          s+=c[j][++z];   //2=se duce pe diagonala dreapta in jos
    if(s>suma)
      {suma=s;
      for(j=1;j<=n;j++)
         b[j]=a[j];}
}
