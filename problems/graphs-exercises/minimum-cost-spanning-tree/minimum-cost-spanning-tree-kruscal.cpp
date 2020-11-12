#include <iostream>
#include <fstream>
using namespace std;
ifstream f("graf43.in");
struct muchie{int x,y,c;};
muchie u[100];
int n,m,L[20];
void citeste()
{
    int i=1;
    f>>n;
    while(f>>u[i].x>>u[i].y>>u[i].c)
         i++;
    m=i-1;
}
void init()
{
    for(int i=1;i<=n;i++)
       L[i]=i;
}
void sortare()
{
    muchie aux;
    int i,j;
    for(i=1;i<=n-1;i++)
       for(j=i+1;j<=n;j++)
           if(u[i].c>u[j].c)
              {
                  aux=u[i];
                  u[i]=u[j];
                  u[j]=aux;
              }
}
int main()
{
    citeste();init();sortare();
    int i=1,k=0,j,ct=0,x,y;
    cout<<"APM este format din muchiile: "<<'\n';
    while(k<n-1)
         {
             if(L[u[i].x]!=L[u[i].y])
                 {
                     k++;
                     ct=ct+u[i].c;
                     cout<<"["<<u[i].x<<","<<u[i].y<<"] ";
                     x=L[u[i].y];
                     y=L[u[i].x];
                    for(j=1;j<=n;j++)
                        if(L[j]==x)
                            L[j]=y;
                 }
             i++;
         }
    cout<<'\n'<<"costul minim= "<<ct;
}
