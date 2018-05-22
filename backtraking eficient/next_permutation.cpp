#include <fstream>
using namespace std;

ifstream f("next_permutation.in");
ofstream g("next_permutation.out");

void reverse(int a[],int i,int n)
{
    while(i<n)
        {swap(a[i],a[n]);
        i++;n--;}
}
void write(int a[],int n)
{
   for(int i=1;i<=n;i++)
          g<<a[i]<<' ';
   g<<'\n';
}
void next_per(int a[],int n)
{
    write(a,n);
    int i,j;
    i=n-1;j=n;
    while(i>0&&a[i]>a[i+1])
          i--;
    if(i!=0)
       {while(a[j]<a[i])
           j--;
       swap(a[i],a[j]);
       reverse(a,i+1,n);
       next_per(a,n);}
}
int n,a[100];
int main()
{
    f>>n;
    for(int i=1;i<=n;i++)
        a[i]=i;
    next_per(a,n);
    f.close();
    g.close();
}
