#include <fstream>
#include <iostream>
using namespace std;
ifstream f("turisti.txt");
struct turist{int z,m;};
turist a[100];
int n,k,c[100];
void citeste()
{
    int i;
    f>>n>>k;
    for(i=1;i<=n;i++)
        {
            f>>a[i].z>>a[i].m;
        }
    f.close();
}
void sort()
{
    int i,j;
    turist aux;
    for(i=1;i<n;i++)
       for(j=i+1;j<=n;j++)
              if(a[i].z+a[i].m>a[j].z+a[j].m)
                 {aux=a[i];
                 a[i]=a[j];
                 a[j]=aux;}
}
void greedy()
{
    int i,j=1,nr=0;
    for(i=1;i<=n;i++)
       if(j<=k&&a[i].z>c[j])
          {
              c[j]=a[i].z+a[i].m;
              j++;
              nr++;
          }
        else
           {
           j=1;
           if(a[i].z>c[j])
              {
                  c[j]=a[i].z+a[i].m;
                  j++;
                  nr++;
              }
           }
    cout<<"vor fi primiti in camping "<<nr<<" turisti ";
}
int main()
{
    citeste();
    sort();
    greedy();
}
