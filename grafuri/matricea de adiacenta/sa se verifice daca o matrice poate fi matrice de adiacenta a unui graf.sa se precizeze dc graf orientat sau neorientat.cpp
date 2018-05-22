#include <iostream>
#include <fstream>
using namespace std;
ifstream f("verific.txt");
int verific(int a[][10],int n)
{
    int i,j;
    for(i=1;i<=n;i++)
       for(j=1;j<=n;j++)
           if(i==j&&a[i][j]!=0)
              return 0;
           else
              if(a[i][j]!=1&&a[i][j]!=0)
                  return 0;
    return 1;
}
int or_neor(int a[][10],int n)
{
    int i,j;
    for(i=1;i<=n-1;i++)
       for(j=i+1;j<=n;j++)
          if(a[i][j]!=a[j][i])
             return 0;
    return 1;
}
int main()
{
    int n,m,a[10][10],i,j;
    f>>n;
    for(i=1;i<=n;i++)
       for(j=1;j<=n;j++)
          f>>a[i][j];
    f.close();
    if(verific(a,n))
       {
           cout<<"Poate fi matrice de adiacenta a unui graf.";
           if(or_neor(a,n))
              cout<<"Neorientat";
           else
              cout<<"Orientat";
       }
    else
       cout<<"Nu poate reprezenta matricea de adiacenta a unui graf.";
}
