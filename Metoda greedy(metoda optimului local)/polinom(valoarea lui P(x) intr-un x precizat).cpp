#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;
ifstream f("polinom.txt");
int v[20],s[20],m,n,a,x,pol=0;
void citeste()
{
    int i;
    cout<<"x= ";cin>>x;  //valoarea lui P(x) in punctul x(se citeste x)
    f>>m>>n>>a;   //v[i]*a^n+v[i]*a^n-1+...
    for(i=1;i<=m;i++)
        f>>v[i];
    f.close();
}
void sort()
{
    int i,j,aux;
    for(i=1;i<m;i++)
       for(j=i+1;j<=m;j++)
           if(v[i]<v[j])
              {
                  aux=v[i];
                  v[i]=v[j];
                  v[j]=aux;
              }
}
void copy()
{
    for(int i=1;i<=n+1;i++)
       s[i]=v[i];
}
void greedy()
{
    cout<<"P(x)= ";
    int i,j=0;
    for(i=x+1;i>0;i--)
        {cout<<s[++j]<<"*"<<a<<"^"<<i-1<<"+";
        pol+=s[j]*pow(a,i-1);}
    cout<<'\b'<<"="<<pol;
}
int main()
{
    citeste();
    sort();
    copy();
    greedy();
}
