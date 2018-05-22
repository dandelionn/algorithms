#include <iostream>
#include <fstream>
using namespace std;
ifstream f("costapm.txt");
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
    f.close();
}
void init()
{
    int i;
    for(i=1;i<=n;i++)
        L[i]=i;
}
void sortare()
{
    muchie aux;
    int i,j;
    for(i=1;i<=m-1;i++)
        for(j=i+1;j<=m;j++)
           if(u[i].c>u[j].c)
              {aux=u[i];
              u[i]=u[j];
              u[j]=aux;}
}
int main()
{
    int i=1,j,k=0,x,y,ct=0;
    citeste();
    init();
    sortare();
    cout<<"APM este format din muchiile: "<<'\n';
    while(k<n-1)
         {if(L[u[i].x]!=L[u[i].y])
             {k++;
             ct=ct+u[i].c;//se alege muchia pt a unifica doi arbori
             cout<<"["<<u[i].x<<","<<u[i].y<<"] ";
             x=L[u[i].y];   //se unifica cei doi arbori prin muchia [x,y]
             y=L[u[i].x];
            for(j=1;j<=n;j++)
                if(L[j]==x)
                    L[j]=y;}
          i++;}     //se trece la muchia urmatoare din lista muchiilor
    cout<<'\n'<<"costul total= "<<ct;
}
