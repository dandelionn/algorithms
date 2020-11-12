#include <iostream>
#include <fstream>
using namespace std;
ifstream f("date.in");
int grad(int a[][10],int n,int i)
{
    int g=0;
    for(int j=1;j<=n;j++)
          g+=a[i][j];
    return g;
}
int main()
{
    int n,a[10][10],i,j,nrm=0;
    f>>n;
    for(i=1;i<=n;i++)
       for(j=1;j<=n;j++)
          f>>a[i][j];
    f.close();
    for(i=1;i<=n;i++)
       if(grad(a,n,i)==0)
          nrm++;
    cout<<"nr de noduri care trebuie adaugate este "<<(nrm+1)/2;
}
